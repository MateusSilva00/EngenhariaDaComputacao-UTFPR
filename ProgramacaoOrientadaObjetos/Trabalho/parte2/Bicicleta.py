from Veiculo import *

class Bicicleta(Veiculo):
    def __init__(self, marca:str):
        super().__init__(marca)
        self.rodas = 2
        print("\n***********************************************************")
        print("Bicicleta da marca {} criada com sucesso - ID: {}".format(self.marca, self.id))
        print("***********************************************************")

