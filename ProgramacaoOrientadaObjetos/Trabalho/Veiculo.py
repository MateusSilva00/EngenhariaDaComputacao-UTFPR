from random import randint
from random import uniform
from random import choice
from Roda import *

class Veiculo():

    # Método construtor. Inicializa automaticamente quando a classe for chamada
    def __init__(self, marca: str):
        self.__marca = marca
        self.__id: str = str(randint(1,20)) # Gera número aleatório entre 1 e 20
        self.__distanciaPercorrida: float = 0
        self.__ipva: bool = bool(choice([True, False]))
        self.__combustivel: float = 3.5
        self.__quantidadeRodas: int = 4
        self.__valorvenda: int = randint(25000, 100000) # Gera valor de venda de 25000 a 100000
        self.rodas: list = [Roda() for _ in range(self.__quantidadeRodas)] # Cria 4 objetos de roda
        print(f"\tVeículo {self.__marca} criando com sucesso!\n\tSeu id é: {self.__id}")

    def mover():
        pass

    def imprimirRodas(self):
        for roda in self.rodas:
            print(roda.getCalibragem())

    def __str__(self):
        if self.__ipva:
            self.__ipva = 'em dia'
        else:
            self.__ipva = 'atrasado'
        return f"\
            Carro: {self.__id}\n \
            É da marca {self.__marca}\n \
            Possui {self.__quantidadeRodas} rodas e esta com seu IPVA {self.__ipva}\n \
            O valor da venda é de R$ {self.__valorvenda}\n"

    def imprimirTrajetoria(self):
        file = open(f'carro{self.__id.zfill(2)}_trajetoria.txt', "w")
        #file.write(self.__str__())
        file.close()

    # def __del__(self):
    #     print(f"Destruindo carro com id {self.__id}")
