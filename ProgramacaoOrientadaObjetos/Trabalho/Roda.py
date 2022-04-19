from random import choice
class Roda:
    def __init__(self):
        self.__calibragemPneu: bool = bool(choice([True, False]))

    def setCalibragem(self, novaCalibragem: bool):
        self.__calibragemPneu = novaCalibragem

    def getCalibragem(self):
        if self.__calibragemPneu:
            return 'Calibrada'
        return 'Vazia'

    def __str__(self):
        return "Magia"
