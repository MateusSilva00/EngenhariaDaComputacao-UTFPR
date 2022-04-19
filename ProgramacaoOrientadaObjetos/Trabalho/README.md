# Trabalho Prático - Parte 1  

O seguinte trabalho tem como objetivo fazer um simulador de corridas utilizando o conceito de classes e objetos. Foi desenvolvido em Python3 para a disciplina de Programação Orientada a Objetos do 4º período de Engenharia da Computação.

## Dicas de Tipo
As dicas de tipo são uma boa prática em programação em Python. Elas servem como um modo de incluir anotações sobre os tipos esperados de variáveis, parâmetros e retorno em funções. <br>
Exemplo:
> def somar(a,b):<br>
>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return a + b<br>

Utilizando dicas de tipo
> def somar(a: int, b: int) -> int:<br>
> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return a + b<br>

**Importante** lembrar que o Python não faz nenhuma verificação para saber se as dicas de tipo estão corretas. Portanto, caso fossem inseridos floats na função somar, ela ainda seria executada.

# Arquivos
###  Roda.py
Dentro do arquivo Roda.py será a definição da classe roda. Esta classe possui apenas o atributo "calibragemPneu", o método setCalibragem para mudar o estado da roda e o método getCalibragem para retorna o estado da Roda.

### Veículo.py
Este arquivo é para as definições da classe veículo. Esta classe possuí diversas atributos, porém a única que será definida pelo usuário será a marca do carro. 

### Simulador.py
Nesse arquivo será instânciado os veículos com suas rodas e um menu será aberto para fazer alterações em seus atributos. Também é possívlel mover-se com os carros na pista de corrida. 

### util.py
Algumas funções que não pertencem necessariamente a nenhuma classe porém são chamadas diversas vezes em simulador.py.

### main.py
Arquivo principal onde será executado a uma instância da classe simulador.

### Equivalências
Vale pontuar algumas equivalências entre a linguagem Python e Java

|                | Python                         |Java           |
|----------------|-------------------------------|-----------------------------|
|Refererência a classe | `self`|`this`|
|Converter string para int |`int()`            |`Integer.parseInt()`|
|Função / Métodos|`def funcao()`| `static void funcao()`|
