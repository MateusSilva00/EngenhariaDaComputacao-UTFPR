-- CREATE DATABASE db_biblioteca; cria o banco de dados
-- SHOW DATABASES; mostra todos os bancos de dados na máquina
-- USE db_biblioca; usa o banco de dados
-- SELECT DATABASE(); mostra qual banco de dados está sendo utilizado
-- DROP DATABASE [IF EXISTS] nome_BD; Apaga o banco de dados em questão

-- SHOW TABLES; 

CREATE TABLE IF NOT EXISTS tbl_Livro(
	ID_Livro smallint AUTO_INCREMENT PRIMARY KEY,
    Nome_Livro varchar(50) NOT NULL,
	ISBN varchar(30) NOT NULL,
	ID_Autor smallint NOT NULL,
	Data_Pub DATE NOT NULL,
    Preco_Livro decimal NOT NULL
);

CREATE TABLE tbl_autores(
	ID_Autor smallint PRIMARY KEY,
	Nome_autor varchar(50),
    Sobrenome_autor varchar(50)
);

CREATE TABLE tbl_editoras(
	ID_editora smallint PRIMARY KEY AUTO_INCREMENT,
    Nome_editora varchar(50) NOT NULL
);



SHOW TABLES;
