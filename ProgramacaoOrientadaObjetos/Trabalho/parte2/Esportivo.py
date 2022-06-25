from VeiculoMotorizado import *

class Esportivo(VeiculoMotorizado):
    def __init__(self, marca:str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.letra = 'E'
        print("\n***********************************************************")
        print("Carro esportivo da marca {} criado com sucesso - ID: {}".format(self.marca.capitalize(), self.id))
        print("***********************************************************")

    def mover(self):
        if self.Ipva:  # Verifica se o Ipva está pago
            if self.Combustivel > self.gastoCarro:  # Verifica se há combustível
                for i in range(self.rodas):
                    if self.estadoRoda[i].Calibragem == 'Vazia':
                        print('{} há roda(s) vazia(s)'.format(self.marca))
                        return

                blocos = (self.Combustivel) // self.gastoCarro
                self.Combustivel = self.Combustivel % self.gastoCarro
                self.distanciaPercorrida = blocos
                print("Carro Passeio {} - {} andou {} blocos e está com {} de gasolina".format(
                    self.marca, self.id, blocos, self.Combustivel))

            else:
                print('{} com combustível insuficiente'.format(self.Combustivel))
        else:
            print("{} não está com ipva em dia".format(self.marca))