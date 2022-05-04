from random import choice

# Criando classe roda
class Roda:
    # Método construtor. Inicializa automaticamente quando a classe for chamada
    def __init__(self):
        self.__calibragemPneu: bool = bool(choice([True, False]))

    def setCalibragem(self, novaCalibragem: bool) -> None:
        self.__calibragemPneu = novaCalibragem

    def getCalibragem(self) -> str:
        if self.__calibragemPneu: # Se a calibragem for True,
            return 'Calibrada' # então a roda está calibrada
        return 'Vazia' # se não estará vazia

    def __str__(self) -> str:
        return self.getCalibragem()
