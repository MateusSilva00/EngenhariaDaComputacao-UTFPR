USE db_biblioteca;
-- ASC - ORDEM ASCENDENTE
-- DESC - ORDEM DESCENDENTE

SELECT * FROM tbl_Livro
ORDER BY Nome_Livro ASC;

SELECT Nome_Livro, Preco_Livro
FROM tbl_Livro
ORDER BY Preco_Livro;