import abc

class interfaceIPVA(metaclass=abc.ABCMeta):
    
    CARRO_POPULAR = 1.3
    MOTOCICLETA = 0.75
    FERRARI = 3.15
    VALOR_BASE = 500

    @classmethod
    def calcularIpva():
        pass