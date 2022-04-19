from random import randint
from random import uniform
from random import choice
from Roda import *

class Veiculo():

    # Método construtor. Inicializa automaticamente quando a classe for chamada
    def __init__(self, marca: str):
        self.__id: str = str(randint(1000,9999)) # Gera número aleatório entre 1000 e 9999 e depois converte para string
        self.__marca = marca
        self.__distanciaPercorrida: float = 0
        self.__ipva: bool = bool(choice([True, False]))
        self.__combustivel: float = 3.5
        self.__quantidadeRodas: int = 4
        self.__valorvenda: int = randint(25000, 100000) # Gera valor de venda de 25000 a 100000
        self.__rodas: list = [Roda() for _ in range(self.__quantidadeRodas)] # Cria 4 instâncias de roda
        print(f"\tVeículo {self.__marca} criado com sucesso!\n\tSeu id é: {self.__id}")

    # Verifica se o IPVA está em dia ou em atraso
    def getIpva(self):
        if self.__ipva:
            return "em dia"
        return "atrasado"

    def getId(self) -> int:
        return int(self.__id)

    def setCombustivel(self, litros: float):
        self.__combustivel += litros
        print(f"Nova quantidade de combustível {self.__combustivel}.\nVeículo abastecido com sucesso")


    def imprimirTrajetoria(self):
        file = open(f'carro{self.__id.zfill(2)}_trajetoria.txt', "w")
        file.write(self.__str__())
        file.close()

    def imprimirCarroID(self):
        return f"Carro {self.__marca} - ID {self.__id}"

    # Imprime todas as rodas de um veículo
    def imprimirRodas(self):
        for i in range(len(self.__rodas)):
            print(f"Roda {i + 1} - {self.__rodas[i].getCalibragem()}")

    # Calibra ou esvazia a roda
    def mudarRodaEstado(self, numero_roda:int, acao: bool):
        self.__rodas[numero_roda].setCalibragem(acao)

    # Método 'mágico' para representar um objeto
    def __str__(self):
        return f"\n{self.__marca}\n{self.__id}\n{self.__distanciaPercorrida}\n{self.getIpva()}\n{self.__combustivel}\n{self.__valorvenda}\n{self.imprimirRodas()}"


    def mover(self):
        if self.__combustivel > 0.55 and self.__ipva:
            if self.__rodas.getCalibragem():
                print("Carro pode se mover")
