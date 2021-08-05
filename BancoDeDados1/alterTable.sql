-- USE db_biblioteca;
-- É possivel alterar a estrutura de uma tabela após ter sido criada, acrescentando ou excluindo atributos 
SHOW TABLES;

ALTER TABLE tbl_Livro DROP COLUMN ID_Autor;

ALTER TABLE tbl_Livro
ADD ID_Autor smallint NOT NULL;

ALTER TABLE tbl_Livro
ADD CONSTRAINT fk_ID_Autor
FOREIGN KEY (ID_Autor)
REFERENCES tbl_autores (ID_Autor);

SELECT * FROM tbl_Livro, tbl_autores;

ALTER TABLE tbl_Livro
ADD ID_editora smallint NOT NULL;

ALTER TABLE tbl_Livro
ADD CONSTRAINT fk_id_editora
FOREIGN KEY (ID_editora)
REFERENCES tbl_editoras (ID_editora);