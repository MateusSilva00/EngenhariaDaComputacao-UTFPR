-- USE db_biblioteca;
CREATE TABLE tbl_test_incremento(
	codigo smallint PRIMARY KEY AUTO_INCREMENT,
	nome varchar(20) NOT NULL
)AUTO_INCREMENT = 15;

INSERT INTO tbl_test_incremento(nome) VALUES ('Ana');
INSERT INTO tbl_test_incremento(nome) VALUES ('Maria');
INSERT INTO tbl_test_incremento(nome) VALUES ('Julia');
INSERT INTO tbl_test_incremento(nome) VALUES ('Joana');

SELECT * FROM tbl_test_incremento;

SHOW TABLES;

/* Podemos verificar o valor de incremento mais atual armazenado em uma tabela no banco de dados com
o seguinte comando:
SELECT MAX (nome_coluna) FROM tabela */

SELECT MAX(codigo) FROM tbl_test_incremento;

/*Para alterar o valor de incremento do próximo registro a ser armazenado em uma tabela, use o comando
a seguir:
ALTER TABLE tabela AUTO_INCREMENT = x*/

ALTER TABLE tbl_test_incremento AUTO_INCREMENT = 100;

INSERT INTO tbl_test_incremento(nome) VALUES ('Matador');
INSERT INTO tbl_test_incremento(nome) VALUES ('Aleister');
INSERT INTO tbl_test_incremento(nome) VALUES ('João Agiota');
INSERT INTO tbl_test_incremento(nome) VALUES ('Papa Léguas');

SELECT * FROM tbl_test_incremento;
