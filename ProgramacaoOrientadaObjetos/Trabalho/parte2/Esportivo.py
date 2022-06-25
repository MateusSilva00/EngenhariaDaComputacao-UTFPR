from VeiculoMotorizado import *

class Esportivo(VeiculoMotorizado):
    def __init__(self, marca):
        super().__init__(marca)
        self.rodas = 4
        print("\n***********************************************************")
        print("Carro esportivo da marca {} criado com sucesso - ID: {}".format(self.marca, self.id))
        print("***********************************************************")
