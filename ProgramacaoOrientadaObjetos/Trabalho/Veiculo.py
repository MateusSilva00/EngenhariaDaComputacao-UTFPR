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
        print(f"Veículo {self.__marca} criado com sucesso!\nSeu id é: {self.__id}")

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

    def setIpva(self):
        self.__ipva = True
        print(f"Ipva paga com sucesso")

    def imprimirCarroID(self) -> str:
        return f"Carro {self.__marca} - ID {self.__id}"


    # Imprime todas as rodas de um veículo
    def imprimirRodas(self) -> None:
        for i in range(len(self.__rodas)):
            print(f"Roda {i + 1} - {self.__rodas[i].getCalibragem()}")

    # Calibra ou esvazia a roda
    def mudarRodaEstado(self, numero_roda:int, acao: bool):
        self.__rodas[numero_roda].setCalibragem(acao)


    def desenhaCarro(self):
        print("    ____".rjust(self.__distanciaPercorrida))
        print(" __/  |_ \_".rjust(self.__distanciaPercorrida))
        print("|  _     _``-. ".rjust(self.__distanciaPercorrida))
        print("'-(_)---(_)--'".rjust(self.__distanciaPercorrida))
        print("\n\n")

    def imprimirCarroCompleto(self):
        print(self.imprimirCarroID())
        self.imprimirRodas()
        print(f"Distância percorrida {self.__distanciaPercorrida}")
        print(f"Ipva {self.getIpva()}")
        print(f"Combustivel em {self.__combustivel} litros")
        print(f"Valor da venda R${self.__valorvenda}\n")


    def mover(self) -> None:
        if self.__ipva:
            if self.__combustivel > 0.55:
                for i in range(len(self.__rodas)):
                    if self.__rodas[i].getCalibragem() == 'Vazia':
                        print('Há rodas vazias')
                        return 
                print("Vai andar")
            else:
                print("Combustível insuficiente")
        else:
            print("Ipva não está em dia")