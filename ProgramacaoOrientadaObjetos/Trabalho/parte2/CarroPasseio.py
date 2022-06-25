from VeiculoMotorizado import *
from interfaceIPVA import interfaceIPVA

class CarroPasseio(VeiculoMotorizado):
    def __init__(self, marca):
        super().__init__(marca)
        self.rodas = 4
        print("\n***********************************************************")
        print("Carro de passeio da marca {} criado com sucesso - ID: {}".format(self.marca, self.id))
        print("***********************************************************")
