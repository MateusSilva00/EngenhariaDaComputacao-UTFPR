from VeiculoMotorizado import *
from math import floor

class Motocicleta(VeiculoMotorizado):
    def __init__(self, marca:str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.letra = 'M'
        print("\n***********************************************************")
        print("Motocicleta da marca {} criada com sucesso - ID: {}".format(self.marca.capitalize(), self.id))
        print("***********************************************************")

    def mover(self):
        if self.Ipva:  # Verifica se o Ipva está pago
            if self.Combustivel > self.gastoMotocicleta:  # Verifica se há combustível
                for i in range(self.rodas):
                    if self.estadoRoda[i].Calibragem == 'Vazia':
                        print('{} há roda(s) vazia(s)'.format(self.marca))
                        return

                blocos = (self.Combustivel) // self.gastoMotocicleta # 12
                self.veiculoAndou(self.Combustivel % self.gastoMotocicleta)
                self.distanciaPercorrida = blocos
                print("Motocicleta {} - ID:{} andou {} blocos e está com {:.2f} de gasolina".format(
                    self.marca, self.id, blocos, self.Combustivel))

            else:
                print('{} com combustível insuficiente'.format(self.Combustivel))
        else:
            print("{} não está com ipva em dia".format(self.marca))

    def desenhar(self):
        posicao = floor(self.distanciaPercorrida) * 4
        print("  , _oo".rjust(posicao-1))
        print(".-/c-//: :".rjust(posicao))
        print("(_)'=='(_)".rjust(posicao))
        print("\n\n")
