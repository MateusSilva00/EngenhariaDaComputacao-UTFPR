from random import randint
from random import uniform
from random import choice
from Roda import *
import math

class Veiculo():

    # Método construtor. Inicializa automaticamente quando a classe for chamada
    def __init__(self, marca: str):
        self.__id: str = str(randint(1000,9999)) # Gera número aleatório entre 1000 e 9999 e depois converte para string
        self.__marca: str = marca
        self.__distanciaPercorrida: float = 0
        self.__ipva: bool = bool(choice([True, False]))
        self.__combustivel: float = 3.5
        self.__quantidadeRodas: int = 4
        self.__valorVenda: int = randint(25000, 100000) # Gera valor de venda de 25000 a 100000
        self.__rodas: list = [Roda() for _ in range(self.__quantidadeRodas)] # Cria 4 instâncias de roda
        print(f"Veículo {self.__marca} criado com sucesso!\nSeu id é: {self.__id}")

    # Verifica se o IPVA está em dia ou em atraso
    def getIpva(self) -> str:
        if self.__ipva: #Se o ipva for True,
            return "em dia" # então está em dia
        return "atrasado" # se não, está atrasado

    def getId(self) -> int:
        return int(self.__id) # Pega o Id do carro como um inteiro

    def setCombustivel(self, litros: float) -> None:
        self.__combustivel += litros
        print(f"Nova quantidade de combustível {self.__combustivel}.\nVeículo abastecido com sucesso")

    
    def setIpva(self) -> None:
        self.__ipva = True

    def imprimirCarroID(self) -> str:
        return f"Carro {self.__marca} {self.__cor} - ID {self.__id}"

    # Imprime todas as rodas de um veículo
    def imprimirRodas(self) -> None:
        for i in range(len(self.__rodas)):
            print(f"Roda {i + 1} - {self.__rodas[i].getCalibragem()}")
    
    # Imprime todas as informações úteis do veículo
    def imprimirCarroCompleto(self) -> None:
        print(self.imprimirCarroID())
        self.imprimirRodas()
        print(f"Distância percorrida {self.__distanciaPercorrida:.2f}")
        print(f"Ipva {self.getIpva()}")
        print(f"Combustivel em {self.__combustivel:.2f} litros")
        print(f"Valor da venda R${self.__valorVenda}\n")

    # Calibra ou esvazia a roda
    def mudarRodaEstado(self, numero_roda:int, acao: bool) -> None:
        self.__rodas[numero_roda].setCalibragem(acao)


    def desenhaCarro(self) -> None:
        posicao = math.floor(self.__distanciaPercorrida) * 3 # Arredonda a distância percorrida e multiplica por 3 para tornar mais perceptível o movimento
        print("    ____".rjust(posicao-6)) # rjust = right ajustment, coloca algumas posições a direita.
        print(" __/  |_ \_".rjust(posicao-3)) # Como os prints possuem tamanho de diferentes, o inteiro que será 
        print("|  _     _``-. ".rjust(posicao+1)) # na função rjust tambem será
        print("'-(_)---(_)--'".rjust(posicao))
        print("\n\n")

    # Verifica todas as condições para que o carro se mova
    def mover(self) -> None:
        if issubclass(self, )
        if self.__ipva:
            if self.__combustivel > 0.55:
                for i in range(len(self.__rodas)):
                    if self.__rodas[i].getCalibragem() == 'Vazia':
                        print('Há rodas vazias')
                        return 
                blocos = (self.__combustivel / 0.55)
                self.__combustivel = self.__combustivel % 0.55
                self.__distanciaPercorrida += blocos
                print(f"Carro {self.__id} andou {blocos:.2f} blocos")
            else:
                print("Combustível insuficiente")
        else:
            print("Ipva não está em dia")