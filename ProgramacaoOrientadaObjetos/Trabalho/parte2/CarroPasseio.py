from VeiculoMotorizado import *
from interfaceIPVA import interfaceIPVA
from math import floor

class CarroPasseio(VeiculoMotorizado):
    def __init__(self, marca:str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.letra = 'C'
        print("\n***********************************************************")
        print("Carro de passeio da marca {} criado com sucesso - ID: {}".format(self.marca.capitalize(), self.id))
        print("***********************************************************")

    def mover(self):
        if self.Ipva: # Verifica se o Ipva está pago
            if self.Combustivel > self.gastoCarro: # Verifica se há combustível
                for i in range(self.rodas):
                    if self.estadoRoda[i].Calibragem == 'Vazia':
                        print('{} há roda(s) vazia(s)'.format(self.marca))
                        return
                
                blocos = (self.Combustivel) // self.gastoCarro
                self.veiculoAndou(self.Combustivel % self.gastoCarro)
                self.distanciaPercorrida = blocos
                print("Carro Passeio {} - ID:{} andou {} blocos e está com {:.2f} de gasolina".format(self.marca, self.id, blocos, self.Combustivel))

            else:
                print('{} com combustível insuficiente'.format(self.Combustivel))
        else:
            print("{} não está com ipva em dia".format(self.marca))

    def desenhar(self) -> None:
        posicao = floor(self.distanciaPercorrida) * 4
        print("    ____".rjust(posicao-6))
        print(" __/  |_ \_".rjust(posicao-3))
        print("|  _     _``-. ".rjust(posicao+1))
        print("'-(_)---(_)--'".rjust(posicao))
        print("\n\n")
