from turtle import pos
from Veiculo import *
import math

class Bicicleta(Veiculo):
    def __init__(self, marca:str, quantidadeRodas:int):
        super().__init__(marca, quantidadeRodas)
        self.letra = 'B'
        print("\n***********************************************************")
        print("Bicicleta da marca {} criada com sucesso - ID: {}".format(self.marca.capitalize(), self.id))
        print("***********************************************************")


    def mover(self):
        for i in range(self.rodas):
            if self.estadoRoda[i].Calibragem == 'Vazia':
                print('{} há roda(s) vazia(s)'.format(self.marca))
                return
        self.distanciaPercorrida = 2
        print("Bicicleta {} - ID:{} andou 2 blocos".format(self.marca, self.id))
    
    def desenhar(self):
        posicao = math.floor(self.distanciaPercorrida) * 4
        print("   __o".rjust(posicao-1))
        print(" _`\<,_:".rjust(posicao))
        print("(*)/ (*)".rjust(posicao))
        print("\n\n")
