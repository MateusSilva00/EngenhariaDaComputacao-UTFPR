BEGIN;
DROP SCHEMA IF EXISTS atividade02 CASCADE;
CREATE SCHEMA IF NOT EXISTS atividade02;

CREATE SEQUENCE IF NOT EXISTS ra_sequence
    AS INT
    INCREMENT 1
    START 15000;

CREATE TABLE Aluno
(
    RA       INTEGER PRIMARY KEY DEFAULT NEXTVAL('ra_sequence'),
    Nome     VARCHAR(50) NOT NULL,
    DataNasc DATE        NOT NULL,
    Idade    SMALLINT CHECK ( Idade > 0 ),
    NomeMae  VARCHAR(50) NOT NULL,
    Cidade   VARCHAR(30),
    Estado   CHAR(2),
    Curso    VARCHAR(50),
    periodo  SMALLINT CHECK ( periodo >= 1 AND periodo <= 12)
);

CREATE TABLE Disciplina
(
    Sigla       CHAR(7)     NOT NULL PRIMARY KEY,
    Nome        VARCHAR(25) NOT NULL,
    SiglaPreReq CHAR(7),
    NNCred      SMALLINT    NOT NULL,
    Monitor     VARCHAR(50),
    Depto       CHAR(8)
);

CREATE TABLE Matricula
(
    RA         INTEGER,
    Sigla      CHAR(7),
    Ano        CHAR(4)    NOT NULL,
    Semestre   CHAR(1)    NOT NULL,
    CodTurma   DECIMAL(4) NOT NULL,
    NotaP1     NUMERIC(3, 1) CHECK ( NotaP1 >= 0.00 AND NotaP1 <= 10.0),
    NotaP2     NUMERIC(3, 1) CHECK ( NotaP2 >= 0.00 AND NotaP2 <= 10.0),
    NotaTrab   NUMERIC(3, 1) CHECK ( NotaTrab >= 0.00 AND NotaTrab <= 10.0),
    NotaFIM    NUMERIC(3, 1) CHECK ( NotaFIM >= 0.00 AND NotaFIM <= 10.0),
    Frequencia DECIMAL(4, 2),


    CONSTRAINT fk_ra FOREIGN KEY (RA) REFERENCES Aluno (RA),
    CONSTRAINT fk_sigla FOREIGN KEY (Sigla) REFERENCES Disciplina (Sigla)
);

COMMIT;

BEGIN;
CREATE UNIQUE INDEX IdxAlunoNNI ON Aluno (Nome, NomeMae, Idade);

-- 1. Escreva uma consulta que utilize esse índice.
EXPLAIN
SELECT *
FROM Aluno
WHERE Nome = 'André da Mota'
  AND NomeMae = 'Julia Rocha'
  AND Idade = 41;
-- Index Scan using idxalunonni on aluno  (cost=0.28..8.30 rows=1 width=456)
--   Index Cond: (((nome)::text = 'André da Mota'::text) AND ((nomemae)::text = 'Julia Rocha'::text) AND (idade = 41))

-- 2. Mostre um exemplo onde o índice não é usado mesmo utilizando algum campo indexado
-- na clausula where, e explique por quê.
EXPLAIN
SELECT Nome, Idade, NomeMae
FROM Aluno
WHERE NomeMae = 'Ana Clara Teixeira';

-- Seq Scan on aluno  (cost=0.00..131.50 rows=25 width=238)
--   Filter: ((nomemae)::text = 'Ana Clara Teixeira'::text)
-- R: De acordo com a documentação do PostgreSQL um índice Btree de múltiplas colunas pode ser usado em consultas com quaisquer subset
-- de colunas no índice. Porém, ele funciona de forma mais eficiente quando as condições são aplicadas as colunas inicias do índice
-- (colunas mais a esquerda). Logo, na consulta acima, devido a baixa seletividade da consulta, o postgresql achou mais inteligente
-- fazer um sequential scan.
-- No entanto, caso a consulta fosse SELECT nome, idade, nomemae FROM Aluno where nome = 'Cauê Dias' a consulta seria feita utilizando um
-- index only scan
ROLLBACK ;

-- 3 - a) Sequencial Scan
BEGIN;
CREATE INDEX idx_notafim ON matricula (notafim);
EXPLAIN ANALYZE
SELECT notafim, RA
FROM Matricula
WHERE NotaFIM != 9;
-- Seq Scan on matricula  (cost=0.00..748.00 rows=31947 width=10) (actual time=0.010..9.996 rows=31949 loops=1)
--   Filter: (notafim <> '9'::numeric)
--   Rows Removed by Filter: 51
-- Planning Time: 0.227 ms
-- Execution Time: 11.215 ms
ROLLBACK;

-- 3 - b) Bitmap Index Scan
BEGIN;
CREATE INDEX idx_aluno_curso_perido ON aluno (idade, curso, periodo);

EXPLAIN
SELECT Nome, Idade, curso, periodo
FROM aluno
WHERE Nome LIKE 'João%'
  AND Idade <= 35
  AND Curso = 'ENGENHARIA DA COMPUTAÇÃO'
  AND periodo >= 6;

-- Bitmap Heap Scan on aluno  (cost=64.12..136.62 rows=4 width=36)
--   Recheck Cond: ((idade <= 35) AND ((curso)::text = 'ENGENHARIA DA COMPUTAÇÃO'::text) AND (periodo >= 6))
--   Filter: ((nome)::text ~~ 'João%'::text)
--   ->  Bitmap Index Scan on idx_aluno_curso_perido  (cost=0.00..64.12 rows=128 width=0)
--         Index Cond: ((idade <= 35) AND ((curso)::text = 'ENGENHARIA DA COMPUTAÇÃO'::text) AND (periodo >= 6))
ROLLBACK;

-- 3 - c) Index Scan
BEGIN;
CREATE INDEX idx_nome_estado ON aluno (nome, estado);

EXPLAIN
SELECT *
FROM Aluno
WHERE nome = 'Isabel Moreira'
  AND Estado = 'PR';
-- Index Scan using idx_nome_estado on aluno  (cost=0.28..8.30 rows=1 width=75)
--   Index Cond: (((nome)::text = 'Isabel Moreira'::text) AND (estado = 'PR'::bpchar))
ROLLBACK;

-- 3 - d) Index-Only Scan
BEGIN;
CREATE INDEX idx_curso_periodo ON aluno (curso, periodo);
EXPLAIN
SELECT Curso, periodo
FROM aluno
WHERE Curso = 'LETRAS'
  AND periodo >= 9;
-- Index Only Scan using idx_curso_periodo on aluno  (cost=0.28..6.46 rows=109 width=18)
--   Index Cond: ((curso = 'LETRAS'::text) AND (periodo >= 9))
ROLLBACK;

-- 3 - e) Multi-Index Scan
BEGIN;
CREATE INDEX idx_ra_nome ON aluno (ra, nome);
CREATE INDEX idx_notafim_frquencia ON matricula (notafim, frequencia);

EXPLAIN
SELECT Aluno.ra, nome, NotaFIM, Frequencia
FROM aluno
         INNER JOIN matricula ON Aluno.ra = Matricula.RA
WHERE Aluno.ra = '17700'
  AND Nome = 'Bruno Aragão'
  AND NotaFIM = 5.8
  AND Frequencia = 90;

-- Nested Loop  (cost=4.64..33.81 rows=1 width=30)
--   ->  Index Only Scan using idx_ra_nome on aluno  (cost=0.28..4.30 rows=1 width=20)
--         Index Cond: ((ra = 17700) AND (nome = 'Bruno Aragão'::text))
--   ->  Bitmap Heap Scan on matricula  (cost=4.36..29.50 rows=1 width=14)
--         Recheck Cond: ((notafim = 5.8) AND (frequencia = '90'::numeric))
--         Filter: (ra = 17700)
--         ->  Bitmap Index Scan on idx_notafim_frquencia  (cost=0.00..4.36 rows=7 width=0)
--               Index Cond: ((notafim = 5.8) AND (frequencia = '90'::numeric))
ROLLBACK;

-- 4 Faça consultas com juncões entre as tabelas e mostre o desempenho criando-se índices
-- para cada chave estrangeira.
BEGIN;
EXPLAIN ANALYZE
SELECT Aluno.RA,
       D.Sigla,
       aluno.nome,
       Aluno.Curso
FROM aluno
         INNER JOIN Matricula M ON aluno.RA = M.RA
         INNER JOIN Disciplina D ON M.Sigla = D.Sigla
WHERE Aluno.ra = 17700
  AND D.Sigla = 'MO20CP ';
-- Planning Time: 0.161 ms
-- Execution Time: 3.476 ms

CREATE INDEX idx_fk_ra ON Matricula (RA);
CREATE INDEX idx_fk_sigla ON Matricula (sigla);

EXPLAIN ANALYZE
SELECT Aluno.RA,
       D.Sigla,
       aluno.nome,
       Aluno.Curso
FROM aluno
         INNER JOIN Matricula M ON aluno.RA = M.RA
         INNER JOIN Disciplina D ON M.Sigla = D.Sigla
WHERE Aluno.ra = 17700
  AND D.Sigla = 'MO20CP ';
-- Planning Time: 0.106 ms
-- Execution Time: 0.098 ms

ROLLBACK;

-- 5 - Utilize um índice bitmap para semestre e mostre-o em uso nas consultas.
CREATE INDEX idx_semestre ON matricula (Semestre);
EXPLAIN VERBOSE
SELECT *
FROM matricula
WHERE Semestre = '2';
-- Bitmap Heap Scan on atividade02.matricula  (cost=184.50..732.85 rows=16028 width=52)
-- "  Output: ra, sigla, ano, semestre, codturma, notap1, notap2, notatrab, notafim, frequencia"
--   Recheck Cond: (matricula.semestre = '2'::bpchar)
--   ->  Bitmap Index Scan on idx_semestre  (cost=0.00..180.50 rows=16028 width=0)
--         Index Cond: (matricula.semestre = '2'::bpchar)
ROLLBACK;

-- 6 - Compare na prática o custo de executar uma consulta com e sem um índice clusterizado
-- na tabela aluno. Ou seja, faça uma consulta sobre algum dado indexado, clusterize a tabela naquele
-- ındice e refaça a consulta. Mostre os comandos e os resultados do explain analyze.
BEGIN;
EXPLAIN ANALYZE
SELECT Nome, Curso, Idade, periodo
FROM Aluno
WHERE RA = 17529;
-- Index Scan using aluno_pkey on aluno  (cost=0.28..8.30 rows=1 width=36) (actual time=0.015..0.016 rows=1 loops=1)
--   Index Cond: (ra = 17529)
-- Planning Time: 0.101 ms
-- Execution Time: 0.021 ms


CREATE UNIQUE INDEX idx_ra ON aluno (ra);
CLUSTER Aluno USING idx_ra;

EXPLAIN ANALYZE
SELECT Nome, Curso, Idade, periodo
FROM Aluno
WHERE RA = 17529;
-- Index Scan using idx_ra on aluno  (cost=0.28..8.30 rows=1 width=36) (actual time=0.013..0.016 rows=1 loops=1)
--   Index Cond: (ra = 17529)
-- Planning Time: 0.071 ms
-- Execution Time: 0.034 ms

ROLLBACK;

-- 7 - Acrescente um campo adicional na tabela de Aluno, chamado de informacoesExtras, do
-- tipo JSON. Insira dados diferentes telefônicos e de times de futebol que o aluno torce para cada aluno
-- neste JSON. Crie índices para o JSON e mostre consultas que o utiliza (explain analyze). Exemplo:
-- retorne os alunos que torcem para o Internacional.
BEGIN;
ALTER TABLE Aluno
    ADD COLUMN informacoesExtras JSONB;

DO
$$
    DECLARE
        timesFutebol TEXT[] := ARRAY ['São Paulo', 'Corinthians', 'Santos', 'Palmeiras'];
        comidas      TEXT[] := ARRAY ['Feijoada', 'Bife acebolado', 'Sushi', 'Hamburguer Artesanal'];
        bebidas      TEXT[] := ARRAY ['Whisky', 'Cerveja', 'Vinho', 'Pinga com Mel e Limão'];
        aluno_id     INTEGER;
    BEGIN
        FOR aluno_id IN (SELECT RA FROM Aluno)
            LOOP
                UPDATE Aluno
                SET informacoesExtras = JSONB_BUILD_OBJECT(
                        'telefone', CONCAT('+55 ', FLOOR(RANDOM() * 1000000000 + 1000000000)::BIGINT),
                        'timeCoracao', timesFutebol[FLOOR(RANDOM() * 4 + 1)],
                        'bebidaFavorita', bebidaS[FLOOR(RANDOM() * 4 + 1)],
                        'comidaFavortia', comidas[FLOOR(RANDOM()) * 4 + 1]
                                        )
                WHERE RA = aluno_id;
            END LOOP;
    END
$$;

CREATE EXTENSION IF NOT EXISTS btree_gin;
CREATE INDEX idx_timeCoracao ON Aluno USING gin((informacoesExtras ->> 'timeCoracao'));
CREATE INDEX idx_bebida ON aluno USING gin((informacoesExtras ->> 'bebidaFavorita'));

EXPLAIN ANALYZE
SELECT Nome, Cidade, informacoesExtras ->> 'timeCoracao' as "Time", informacoesExtras ->> 'bebidaFavorita'
FROM Aluno
WHERE informacoesExtras ->> 'timeCoracao' = 'Santos' AND informacoesExtras ->> 'bebidaFavorita' = 'Pinga com Mel e Limão';

-- Bitmap Heap Scan on aluno  (cost=16.63..20.65 rows=1 width=92) (actual time=0.287..0.496 rows=335 loops=1)
--   Recheck Cond: (((informacoesextras ->> 'bebidaFavorita'::text) = 'Pinga com Mel e Limão'::text) AND ((informacoesextras ->> 'timeCoracao'::text) = 'Santos'::text))
--   Heap Blocks: exact=132
--   ->  BitmapAnd  (cost=16.63..16.63 rows=1 width=0) (actual time=0.267..0.268 rows=0 loops=1)
--         ->  Bitmap Index Scan on idx_bebida  (cost=0.00..8.19 rows=25 width=0) (actual time=0.142..0.142 rows=1271 loops=1)
--               Index Cond: ((informacoesextras ->> 'bebidaFavorita'::text) = 'Pinga com Mel e Limão'::text)
--         ->  Bitmap Index Scan on idx_timecoracao  (cost=0.00..8.19 rows=25 width=0) (actual time=0.118..0.118 rows=1270 loops=1)
--               Index Cond: ((informacoesextras ->> 'timeCoracao'::text) = 'Santos'::text)
-- Planning Time: 0.203 ms
-- Execution Time: 0.523 ms

ROLLBACK ;