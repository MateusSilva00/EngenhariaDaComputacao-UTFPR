# Bibliotecas do python
from random import randint
from abc import ABC, abstractclassmethod

# Classes
from Roda import * 

class Veiculo(ABC):
    @abstractclassmethod
    def __init__(self, marca:str):
        self.__marca = marca
        self.__id:int = randint(1000, 9999)
        self.__distanciaPercorrida: int = 0
        self.__quantidadeRodas = 0
    
        self.__rodas: list = [Roda() for _ in range(self.__quantidadeRodas)] # Cria 4 instâncias de roda

    @property # Getter
    def id(self):
        return self.__id

    @property # Getter
    def marca(self):
        return self.__marca
    
    @property # Getter
    def rodas(self):
        return self.__quantidadeRodas

    @rodas.setter # Setter
    def rodas(self, quantidadeRodas):
        self.__quantidadeRodas = quantidadeRodas
    
    # Imprime o id do veiculo
    def imprimirVeiculoID(self) -> None:
        return f"Véiculo {self.__marca} - ID {self.__id}"

    # Imprime todas as rodas de um veículo
    def imprimirRodas(self) -> None:
        for i in range(len(self.__rodas)):
            print(f"Roda {i + 1} - {self.__rodas[i].Calibragem}")

    # Imprime todas as informações úteis do veículo
    def imprimirVeiculoCompleto(self) -> None:
        print(self.imprimirVeiculoID())
        self.imprimirRodas()
        print(f"Distância percorrida {self.__distanciaPercorrida:.2f}")

    # Verifica todas as condições para que o carro se mova
    def mover(self) -> None:
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
