from Veiculo import *

class Bicicleta(Veiculo):
    def __init__(self, marca:str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.letra = 'B'
        print("\n***********************************************************")
        print("Bicicleta da marca {} criada com sucesso - ID: {}".format(self.marca.capitalize(), self.id))
        print("***********************************************************")


    def mover(self):
        for i in range(len(self.__rodas)):
            if self.__rodas[i].Calibragem == 'Vazia':
                print('{} há roda(s) vazia(s)'.self.marca)
                return
        print("Bicileta {} - {} andou 2 blocos".format(self.marca, self.id))
