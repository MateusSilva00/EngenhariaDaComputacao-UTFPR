USE db_biblioteca; 

INSERT INTO tbl_autores(ID_Autor, Nome_autor, Sobrenome_autor) VALUES (1, "Daniel", "Barret");
INSERT INTO tbl_autores(ID_Autor, Nome_autor, Sobrenome_autor) VALUES (2, "Daniel", "Kanemman");
INSERT INTO tbl_autores(ID_Autor, Nome_autor, Sobrenome_autor) VALUES (3, "Augusto", "Cury");
INSERT INTO tbl_autores(ID_Autor, Nome_autor, Sobrenome_autor) VALUES (4, "Nassim", "Taleb");
INSERT INTO tbl_autores(ID_Autor, Nome_autor, Sobrenome_autor) VALUES (5, "Karl", "Marx");

SELECT * FROM tbl_autores;

INSERT INTO tbl_editoras(Nome_editora) VALUES ("Prentice Hall");
INSERT INTO tbl_editoras(Nome_editora) VALUES ("O' Reilly");
INSERT INTO tbl_editoras(Nome_editora) VALUES ("Microsoft Press");
INSERT INTO tbl_editoras(Nome_editora) VALUES ("Wiley");

INSERT INTO tbl_Livro(Nome_Livro, ISBN, Data_Pub, Preco_Livro, ID_Autor, ID_editora)
VALUES ("Linux Command Line and Shell Scripting", 143856969, "20091221", 68.35, 1, 3);

INSERT INTO tbl_Livro(Nome_Livro, ISBN, Data_Pub, Preco_Livro, ID_Autor, ID_editora)
VALUES ("O CAPITAL", 197856062, "20000403", 99.99, 5, 1);

INSERT INTO tbl_Livro(Nome_Livro, ISBN, Data_Pub, Preco_Livro, ID_Autor, ID_editora)
VALUES ("A lógica do Cisne Negro", 601853912, "20161230", 40, 4, 2);


select * from tbl_Livro;