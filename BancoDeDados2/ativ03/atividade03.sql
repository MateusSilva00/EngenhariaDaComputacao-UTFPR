CREATE SCHEMA IF NOT EXISTS atividade03;

SET SEARCH_PATH TO atividade03;

-- Cliente{id cli, CPF, Nome, data_reg, valor_max_liberado}

CREATE TABLE cliente
(
    id_cliente         integer PRIMARY KEY,
    cpf                char(11),
    nome               varchar(60),
    data_reg           date,
    valor_max_liberado decimal(10, 2)
);

-- Emprestimo{id empr, data empr, valor_total, nro_parcelas, quitado, id cli}
CREATE TABLE emprestimo
(
    id_emprestimo   integer PRIMARY KEY,
    id_cliente      integer,
    data_emprestimo date,
    valor_total     decimal(10, 2),
    nro_parcelas    smallint,
    quitado         boolean,
    CONSTRAINT fk_id_cliente FOREIGN KEY (id_cliente) REFERENCES cliente (id_cliente)
);


DROP FUNCTION get_cliente_id;

-- 1. Dado o nome do cliente, retornar seu ID.
CREATE OR REPLACE FUNCTION get_cliente_id(nome_encontrar varchar)
    RETURNS table
            (
                nome_encontrado varchar,
                id              integer
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT nome, id_cliente

        FROM cliente
        WHERE $1 = cliente.nome;
END;
$$;

-- 2. Dado o ID de um cliente, retornar o valor total devido dos emprestimos.
CREATE FUNCTION get_total_debt_by_id(id_encontrar integer)
    RETURNS table
            (
                Devedor                              varchar,
                "Valor total devido aos emprestimos" decimal(10, 2)
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT nome, SUM(valor_total) AS "Valor total devido aos emprestimo"
        FROM cliente
                 INNER JOIN emprestimo E ON cliente.id_cliente = E.id_cliente
        WHERE E.id_cliente = $1
        GROUP BY nome;
END;
$$;

SELECT *
FROM get_total_debt_by_id(10);

-- 3. Dado o ID de um cliente, retornar sua data de registro no sistema.
CREATE OR REPLACE FUNCTION get_debts_date(id_encontrar int)
    RETURNS DATE[]
    LANGUAGE plpgsql AS
$$
DECLARE
    DATAS date[];
BEGIN
    SELECT ARRAY_AGG(data_emprestimo) AS d
    INTO DATAS
    FROM cliente AS c
             INNER JOIN emprestimo e ON c.id_cliente = e.id_cliente
    WHERE c.id_cliente = $1
    GROUP BY e.id_cliente
    ORDER BY d;
    RETURN DATAS;
END;
$$;

SELECT *
FROM get_total_debt_by_id(1000);


-- 4. Dados o CPF e o novo valor, atualizar o cliente com seu novo valor liberado para emprestimo.
CREATE OR REPLACE FUNCTION new_max_loan(cpf_encontrar char(11), new_max_value decimal(10, 2)) RETURNS void
    LANGUAGE plpgsql AS
$$
BEGIN
    UPDATE cliente
    SET valor_max_liberado = new_max_value
    WHERE cpf = cpf_encontrar;

    IF NOT FOUND THEN
        RAISE EXCEPTION 'Cliente com CPF % não encontrado', cpf_encontrar;
    ELSE
        RAISE NOTICE 'Novo valor máximo liberado de R$% para %', new_max_value, cpf_encontrar;
    END IF;
END;
$$;


SELECT *
FROM cliente
WHERE CPF = '36814792087';
-- 501,36814792087,Vitor Novaes,1972-01-02,604252.15
SELECT *
FROM new_max_loan('36814792087', 471324);
SELECT *
FROM cliente
WHERE CPF = '36814792087';
-- 501,36814792087,Vitor Novaes,1972-01-02,471324.00


-- 5. Dado o ID do empréstimo, quitar o mesmo.
CREATE OR REPLACE FUNCTION pay_off_debt(
    id_procurado integer
) RETURNS VOID
    LANGUAGE plpgsql
AS
$$
DECLARE
    nome_devedor varchar;
BEGIN
    UPDATE emprestimo
    SET quitado = TRUE
    WHERE id_emprestimo = id_procurado;

    IF NOT FOUND THEN
        RAISE EXCEPTION 'Empréstimo de id: % não encontrado', id_procurado;
    ELSE
        SELECT nome
        INTO nome_devedor
        FROM cliente AS c
                 INNER JOIN emprestimo AS e ON c.id_cliente = e.id_cliente
        WHERE id_emprestimo = id_procurado;
        RAISE NOTICE 'Empréstimo % de % quitado com sucesso!', id_procurado, nome_devedor;
    END IF;
END;
$$;

SELECT *
FROM emprestimo
WHERE id_emprestimo = 662;
-- 662,2425,2003-12-07,4472405.10,42,false
SELECT *
FROM pay_off_debt(662);
-- 662,2425,2003-12-07,4472405.10,42,true

-- 6. Dado o ID de um cliente, retornar o valor do empréstimo mais antigo que não está quitado.
CREATE OR REPLACE FUNCTION get_older_debt(id_cliente_procurado integer)
    RETURNS table
            (
                "Nome do devedor" varchar,
                "Divida"          decimal,
                "Data Emprestimo" date
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT nome, E.valor_total, E.data_emprestimo
        FROM cliente
                 INNER JOIN emprestimo E ON cliente.id_cliente = E.id_cliente
        WHERE quitado = FALSE
          AND E.id_cliente = id_cliente_procurado
        ORDER BY data_emprestimo ASC
        LIMIT 1;
END;
$$;


SELECT * from get_older_debt(4);
-- Dr. Luigi da Cunha,2296951.76,1970-07-15

SELECT * from get_older_debt(666);
-- Srta. Nina Barros,3497033.42,1990-10-10

SELECT * from get_older_debt(993);
-- João Felipe Pereira,9979915.99,1987-06-21
