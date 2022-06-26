from VeiculoMotorizado import *
from math import floor

class Esportivo(VeiculoMotorizado):
    def __init__(self, marca:str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.letra = 'E'
        print("\n***********************************************************")
        print("Carro esportivo da marca {} criado com sucesso - ID: {}".format(self.marca.capitalize(), self.id))
        print("***********************************************************")

    def mover(self):
        if self.Ipva:  # Verifica se o Ipva está pago
            if self.Combustivel > self.gastoFerrari:  # Verifica se há combustível
                for i in range(self.rodas):
                    if self.estadoRoda[i].Calibragem == 'Vazia':
                        print('{} há roda(s) vazia(s)'.format(self.marca))
                        return

                blocos = (self.Combustivel) // self.gastoFerrari
                self.veiculoAndou(self.Combustivel % self.gastoFerrari)
                self.distanciaPercorrida = blocos
                print("Carro Esportivo {} - ID:{} andou {} blocos e está com {:.2f} de gasolina".format(self.marca, self.id, blocos, self.Combustivel))

            else:
                print('{} com combustível insuficiente'.format(self.Combustivel))
        else:
            print("{} não está com ipva em dia".format(self.marca))

    
    def desenhar(self) -> None:
        posicao = floor(self.distanciaPercorrida) * 8
        print("        __".rjust(posicao-5))
        print("      ~( @".rjust(posicao-5))
        print("   _____]_[_/_>__".rjust(posicao))
        print("  / __ \\<> |  __ \\".rjust(posicao))
        print("=\\_/__\\_\\__|_/__\\".rjust(posicao))
        print("   (__)      (__)".rjust(posicao)) #17
        print("\n\n")