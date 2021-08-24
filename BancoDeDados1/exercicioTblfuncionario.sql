CREATE DATABASE db_tbl_funcionario;
SHOW DATABASES;
USE db_tbl_funcionario;

SHOW TABLES;
-- DROP TABLE tbl_funcionario;

CREATE TABLE IF NOT EXISTS tbl_funcionario( 
	cd_tbl_funcionario smallint NOT NULL AUTO_INCREMENT PRIMARY KEY,
	nome varchar(30) NOT NULL,
    salario DECIMAL(12,2),
	sexo char(1),
	Idade smallint,
    uf char(2),
    cidade varchar(40) NOT NULL,
    est_civil char (10)
)AUTO_INCREMENT = 1;

ALTER TABLE tbl_funcionario
MODIFY nome VARCHAR(75);

INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Rodrigo Teixeira Cardiloso', 1588, 'm', 25, 'sc', 'Lages', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Maria Teixeira Joaquina', 2000, 'f', 23, 'pr', 'Pato Branco', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Bastianzinho Benz e Silva', 1000, 'm', 55, 'pr', 'Curitiba', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Ana Paulina Teixeirina', 4500, 'f', 34, 'sc', 'Florianópolis', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Tonico Vampirino Alves', 1500, 'm', 25, 'sc', 'Sao Paulo', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Jose de Deus Olivre', 2000, 'm', 35, 'ba', 'Savador', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('José Bolseiro', 1500, 'm', 30, 'sc', 'Biguaçu', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Bilbo Sonaro Teixeira', 1000, 'm', 35, 'sc', 'Florianópolis', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Jack Alambrado Afora', 1199, 'm', 35, 'rs', 'Nova Petrópolis', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Jenuina Verginina Silasbileia', 1990, 'f', 35, 'rs', 'Bagé', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil) 
	VALUES ('Jucandré Teixeiré Bolson', 1999, 'm', 35, 'rr', 'Selvinha', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil)
	VALUES ('Mateus Henrique Silva', 6350, 'm', 24, 'sp', 'Santos', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil)
	VALUES ('Marcelo da Cruz', 10350, 'm', 42, 'pr', 'Pato Branco', 'Casado');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil)
	VALUES ('Ana Beatriz Marcelo', 2200, 'f', 20, 'sp', 'São Vicente', 'Solteiro');
INSERT INTO tbl_funcionario (nome, salario, sexo, Idade, uf, cidade, est_civil)
	VALUES ('Jeferson Marcelo Alburque', 9200, 'm', 48, 'ce', 'Fortaleza', 'Solteiro');
    
    
-- 1)	Selecionar todos os funcionários e todos os seus dados, com e sem * 
SELECT * FROM tbl_funcionario;
SELECT cd_tbl_funcionario, nome, salario, sexo, idade, uf, cidade, est_civil FROM tbl_funcionario;
SELECT DISTINCT nome FROM tbl_funcionario;
-- 2)	Na sua opinião, seria possível implementar uma consulta em SQL de modo tal que eventuais tuplas duplicadas 
-- fossem removidas? Tente Select nome from funcionário. Use select distinct. 
-- Compare, interprete, discuta, pense e prossiga. 
SELECT DISTINCT nome FROM tbl_funcionario;

-- 6)	O nome de todos os funcionários e seus respectivos salários;
SELECT nome, salario FROM tbl_funcionario;

-- 7)	O maior, o menor  e a média dos salários de todos os funcionários;
SELECT MAX(salario) as Máximo, MIN(salario) as Mínimo, AVG(salario) as Média FROM tbl_funcionario;

-- 8)	O maior, o menor  e a média dos salários de todos os funcionários H e depois repita para as M. Daria para
-- apresentar os dois na mesma consulta? Daria para apresentar em uma linha os dados dos homens e a segunda linha 
-- os das mulheres? Daria para apresentar em duas colunas?
SELECT MAX(salario) as Máximo, MIN(salario) as Mínimo, AVG(salario) as Média FROM tbl_funcionario
WHERE sexo = 'm';
SELECT MAX(salario) as Máximo, MIN(salario) as Mínimo, AVG(salario) as Média FROM tbl_funcionario
WHERE sexo = 'f';

SELECT MAX(salario) as Máximo, MIN(salario) as Mínimo, AVG(salario) as Média FROM tbl_funcionario
WHERE (sexo = 'm')
UNION 
SELECT MAX(salario), MIN(salario), AVG(salario) FROM tbl_funcionario
WHERE (sexo = 'f');

-- 9)	O a média salarial de todos os funcionários que tenham Teixeira no nome;
SELECT AVG(salario) FROM tbl_funcionario
WHERE nome LIKE '%Teixeira%';

-- 10)	 Um atributo MedSal com a média dos salários entre todos os funcionários;
SELECT AVG(salario) as MedSal FROM tbl_funcionario;

-- 11)	 Um atributo SomaSal com a soma de todos os salários;
SELECT SUM(salario) as SomaSal FROM tbl_funcionario;

-- 12)	 O salário do funcionário com o código = y; 
SELECT salario FROM tbl_funcionario
WHERE (cd_tbl_funcionario = 'y');

-- 13)	 O nome dos funcionários que moram em Santa Catarina (com tratamento adequado de string);
SELECT nome FROM tbl_funcionario
WHERE (UPPER(uf) = 'SC');

-- 14)	 Os funcionários com o código 1, 2, 4 e 6 apresentados na ordem alfabética decrescente;
SELECT nome FROM tbl_funcionario
WHERE cd_tbl_funcionario  (1, 2, 4, 6) 
ORDER BY nome DESC;

-- 15)	 Um atributo QtdFuncMaster com a quantidade de funcionários que ganham entre 1000 e 2000;
SELECT COUNT(nome) as QtdFuncMaster FROM tbl_funcionario
WHERE salario >= 1000 AND salario <= 2000;

-- 16)	 Um atributo MedIdade com a média entre as idades dos funcionários;
SELECT AVG(idade) as MedIdade FROM tbl_funcionario;

-- 17)	 Todos os funcionários cujo nome comece com a letra M e não terminem com Teixeira. Varie.
 SELECT nome FROM tbl_funcionario
 WHERE nome LIKE 'M%' AND nome NOT LIKE "%Teixeira%";
 
-- 18)	 Atualize a tabla funcionários. Por merecimento, aumente em 10% o salário de todos os funcionários que 
-- contenham Marcelo em qualquer parte do nome. Não esqueça que não deve importar a forma como o termo Marcelo
-- está escrito. 
UPDATE tbl_funcionario
SET salario = salario * 1.1
WHERE nome LIKE UPPER('%Marcelo%');

SELECT nome, salario FROM tbl_funcionario
WHERE nome LIKE UPPER('%Marcelo%');

-- 19)	 Estenda a consulta anterior. Aumente em mais 10% o salário dos Marcelos, caso o valor total, incluindo 
-- aquilo que vc já aumentou na consulta anterior, ainda não esteja na faixa entre 10.000 e 20.000.  
UPDATE tbl_funcionario
SET salario = salario * 1.1 
	WHERE salario NOT BETWEEN 10000 AND 20000
    AND nome LIKE UPPER('%Marcelo%');

-- 20)	 Retorne o campo (atributo) sexo e a quantidade de funcionários de cada sexo;
SELECT COUNT(sexo) as 'M/F' FROM tbl_funcionario
WHERE sexo = 'm' 
UNION 
SELECT COUNT(sexo) FROM tbl_funcionario WHERE sexo = 'f';

-- 21)	 Retorne o campo sexo e a quantidade de funcionários de cada sexo. Restrinja a consulta aos 
-- funcionários do Paraná;
SELECT COUNT(sexo) as 'M/F' FROM tbl_funcionario
WHERE sexo = 'm' AND uf = 'pr'
UNION 
SELECT COUNT(sexo) FROM tbl_funcionario 
WHERE sexo = 'f' AND uf = 'pr';

-- 22)	 Retorne o campo sexo e a quantidade de funcionários de cada sexo. Restrinja a consulta aos 
-- funcionários do Paraná. Só mostre os dados dos casos em que a quantidade de funcionários seja maior que 10;
SELECT COUNT(sexo) as 'M/F' FROM tbl_funcionario
WHERE sexo = 'm' AND uf = 'pr'
IF 'M/F' > 10
UNION 
SELECT COUNT(sexo) FROM tbl_funcionario 
WHERE sexo = 'f' AND uf = 'pr' ;


