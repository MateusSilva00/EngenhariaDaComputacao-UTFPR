# Bibliotecas do python
from random import choice
from abc import ABC, abstractclassmethod, abstractmethod, abstractproperty

from Veiculo import *

class VeiculoMotorizado(Veiculo, ABC):
    @abstractclassmethod
    def __init__(self, marca: str):
        super().__init__(marca)
        self.gastoMotocicleta: float = 0.25
        self.gastoCarro: float = 0.75
        self.gastoFerrari: float = 2.3
        self.__combustivel: float = 3.5
        self.__ipva = bool(choice([True, False]))

    @property # Getter
    def Combustivel(self):
        return self.__combustivel

    @Combustivel.setter
    def Combustivel(self, litros):
        self.__combustivel += litros
        print(f"Nova quantidade de combustível: {self.__combustivel} litros.\n{self.marca} abastecido com sucesso")

    def abastecer(self, litros: float):
        self.Combustivel = litros

    @property # Getter
    def Ipva(self):
        return self.__ipva
    
    @Ipva.setter
    def Ipva(self):
        self.__ipva = True

