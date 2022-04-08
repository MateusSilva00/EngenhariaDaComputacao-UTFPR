from Veiculo import *
from util import *
import sys
import time

class Simulador:
    def __init__(self):
        self.__veiculos = ['None'] * 10 
        pass

    # Classe principal
    def main(self):
        pass

    def menu(self):
        clearConsole() # Função para limparar o console
        print("Bem Vindo ao simulador de corrida\nEscolha uma das opções abaixo:")
        print("\t1 - Incluir Veículo")
        print('\t2 - Excluir Veículo')
        print('\t3 - Abastecer Veículo')
        print('\t4 - Movimentar Veículo')
        print('\t5 - Movimentar todos os veículos')
        print('\t6 - Imprimir todos os dados de um veículo')
        print('\t7 - Imprimir todos os dados de todos os veículos')
        print('\t8 - Esvaziar / Calibrar um pneu')
        print('\t9 - Calibrar todos os pneus de um veículo específico')
        print('\t10 - Esvaziar todos os pneus de um veículo específico')
        print('\t11 - Imprimir pista de corrida')
        print('\t12 - Gravar veículos em arquivo')
        print('\t13 - Ler veículos do arquivo')
        print('\t14 - Sair da aplicação')
        
        codigo_menu = int(input())

        if codigo_menu == 1:
            marca_veiculo = input('\tDigite a marca do Veículo: ')
            Veiculo(marca_veiculo)
            time.sleep(3)
        elif codigo_menu == 2:
            int(input('\tQual veículo deseja excluir? '))
        elif codigo_menu == 14:
            sys.exit('\tAté breve desgraçado!')



    def incluirVeiculo(self):
        pass

    def excluirVeiculo(self):
        pass

    def abastecerVeiculo(self):
        pass

    def movimentarVeiculo(self):
        pass

    def movimentarVeiculos(self):
        pass

    def imprimirVeiculo(self):
        pass

    def imprimirVeiculos(self):
        pass

    def calibrar_esvaziar_PneuEspecifico(self):
        pass

    def calibrarPneus(self):
        pass

    def esvaziarPneus(self):
        pass

    def imprimirPista(self):
        pass

    def gravarVeiculos(self):
        pass

    def lerVeiculos(self):
        pass


if __name__ == "__main__":
    pass