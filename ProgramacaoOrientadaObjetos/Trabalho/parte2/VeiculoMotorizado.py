# Bibliotecas do python
from random import choice
from abc import ABC, abstractclassmethod
from Veiculo import Veiculo

class VeiculoMotorizado(Veiculo, ABC):
    @abstractclassmethod
    def __init__(self, marca: str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.__gastoMotocicleta: float = 0.25
        self.__gastoCarro: float = 0.75
        self.__gastoFerrari: float = 2.3
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
        if self.__ipva:
            print('Ipva pago')
            return True
        else:
            print("Ipva atrasado")
            return False
    
    @Ipva.setter
    def Ipva(self, pago):
        self.__ipva = pago

    @property # Getter
    def gastoMotocicleta(self):
        return self.__gastoMotocicleta
    
    @property
    def gastoCarro(self):
        return self.__gastoCarro
    
    @property
    def gastoFerrari(self):
        return self.__gastoFerrari

