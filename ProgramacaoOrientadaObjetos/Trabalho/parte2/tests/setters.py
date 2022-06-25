class Pessoa(object):
    def __init__(self, nome, idade, salario):
        self._nome = nome
        self._idade = idade
        self._salario = salario

    @property
    def nome(self):
        print('get do nome')
        return self._nome

    @nome.setter
    def nome(self, nome):
        print('set do nome', nome)
        self._nome = nome

    @property
    def idade(self):
        print('get da idade')
        return self._idade

    @idade.setter
    def idade(self, idade):
        print('set da idade', idade)
        self._idade = idade

    @property
    def salarioPegar(self):
        print('get do salario')
        return self._salario

    @salarioPegar.setter
    def salarioPegar(self, salario):
        print('set do salario', salario)
        self._salario = salario


pessoa = Pessoa('Miguel', 30, 50)
# print(pessoa.__dict__)  # valores iniciais
# pessoa.nome = 'Afonso'
# pessoa.idade = 20
pessoa.salarioPegar = 500
# print(pessoa.nome)
# print(pessoa.idade)
print(pessoa.salarioPegar)
