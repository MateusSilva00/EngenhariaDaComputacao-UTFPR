# Bibliotecas do python
from random import randint
from abc import ABC, abstractclassmethod, abstractmethod

# Classes
from Roda import * 

class Veiculo(ABC):
    @abstractclassmethod
    def __init__(self, marca:str, quantidadeRodas):
        self.__marca = marca
        self.__id:int = randint(1000, 9999)
        self.__distanciaPercorrida: int = 0
        self.__quantidadeRodas = quantidadeRodas
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
    
    @property # Getter
    def estadoRoda(self):
        return self.__rodas 
    
    @property # Getter
    def distanciaPercorrida(self):
        return self.__distanciaPercorrida
    
    @distanciaPercorrida.setter
    def distanciaPercorrida(self, novaDistancia):
        self.__distanciaPercorrida += novaDistancia
    
    # Imprime o id do veiculo
    def exibirVeiculoID(self) -> None:
        print("{} - ID {}".format(self.__marca.capitalize(), self.__id))

    # Imprime todas as rodas de um veículo
    def exibirRodas(self) -> None:
        for i in range(len(self.__rodas)):
            print(f"Roda {i + 1} - {self.__rodas[i].Calibragem}")

    def tipoCarro(self) -> None:
        if self.letra == 'B':
            print("Bicicleta")
        if self.letra == 'E':
            print("Carro Esportivo")
        if self.letra == 'M':
            print("Motocicleta")
        if self.letra == 'C':
            print("Carro Passeio")

    # Imprime todas as informações úteis do veículo
    def exibirVeiculoCompleto(self) -> None:
        self.exibirVeiculoID()
        self.tipoCarro()
        self.exibirRodas()
        print(f"Distância percorrida {self.__distanciaPercorrida:.2f}")
        try:
            self.Ipva
        except:
            print("Veículo não paga Ipva")
            pass

    # Método abstrato
    @abstractmethod
    def mover(self) -> None:
        pass
