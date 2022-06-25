from VeiculoMotorizado import *

class Motocicleta(VeiculoMotorizado):
    def __init__(self, marca):
        super().__init__(marca)
        self.rodas = 4
        print("\n***********************************************************")
        print("Motocicleta da marca {} criada com sucesso - ID: {}".format(self.marca, self.id))
        print("***********************************************************")
