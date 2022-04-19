from turtle import penup
from Veiculo import *
from util import *
import sys
import time

class Simulador:
    def __init__(self):
        self.__veiculos = [] # Inicializa uma lista vazia 

    # Função 1
    def incluirVeiculo(self):
        marca_veiculo = input('\tDigite a marca do Veículo: ')
        veiculo = Veiculo(marca_veiculo) # Criar o objeto veículo com base na marca da carro
        self.__veiculos.append(veiculo) # Adiciona o veículo na lista de veículos
        time.sleep(3)

    # Função 2
    def excluirVeiculo(self):
        id  =  exibirCarrosListados(self.__veiculos, "Deseja excluir qual carro(id)? ")
        
        for i in range(len(self.__veiculos)): # Percorre a lista para encontrar o veículo
            if id == self.__veiculos[i].getId(): # Verifica se o código digitado existe
                print("Veículo encontrado e excluído com sucesso")
                del self.__veiculos[i]
                encontrou = True
            break

        if not encontrou:
            print("Veículo não encontrado")

        time.sleep(3)

    # Função 3
    def abastecerVeiculo(self):
        id = exibirCarrosListados(self.__veiculos, "Qual Veículo deseja abastecer(id)? ")
        for i in range(len(self.__veiculos)):
            if id == self.__veiculos[i].getId():
                encontrou = True
                abastecer = int(input("Quanto litros deseja abastecer: "))
                self.__veiculos[i].setCombustivel(abastecer)
            break

        if not encontrou:
            print("Veículo não encontrado")
        time.sleep(3)

    # Função 4
    def movimentarVeiculo(self):
        pass
    
    # Função 5
    def movimentarVeiculos(self):
        pass

    # Função 6
    def imprimirVeiculo(self):
        id = exibirCarrosListados(self.__veiculos, "Qual veículo deseja imprimir(id)? ")
        for i in range(len(self.__veiculos)):
            if id == self.__veiculos[i].getId():
                encontrou = True
                print(self.__veiculos[i].__str__())
            break

        if not encontrou:
            print("Veículo não encontrado")
        time.sleep(20)

    # Função 7
    def imprimirVeiculos(self):
        for i in range(len(self.__veiculos)):
            print(self.__veiculos[i].__str__())

    # Função 8
    def calibrar_esvaziar_PneuEspecifico(self):
        id = exibirCarrosListados(self.__veiculos, "Deseja calibrar/esvaziar a roda de qual carro(id) ? ")
        for i in range(len(self.__veiculos)):
            if id == self.__veiculos[i].getId():
                encontrou = True
                self.__veiculos[i].imprimirRodas()
                acao = int(input("Deseja\n1 - Esvaziar\n2 - Calibrar ? "))
                
                if acao == 1:
                    roda = int(input("Qual roda deseja esvaziar ? ")) - 1
                    self.__veiculos[i].mudarRodaEstado(roda, False)
                else:
                    roda = int(input("Qual roda deseja calibrar ? ")) - 1
                    self.__veiculos[i].mudarRodaEstado(roda, True)
            break

        self.__veiculos[i].imprimirRodas()

        if not encontrou:
            print("Veículo não encontrado")
        time.sleep(5)

    # Função 9
    def calibrarPneus(self):
        id = exibirCarrosListados(self.__veiculos, "Deseja calibrar a roda de qual carro(id)? ")
        for i in range(len(self.__veiculos)):
            if id == self.__veiculos[i].getId():
                encontrou = True
                for roda in range(4):
                    self.__veiculos[i].mudarRodaEstado(roda, True)
            break

        self.__veiculos[i].imprimirRodas()
        if not encontrou:
            print("Veículo não encontrado")
        time.sleep(3.5)

    # Função 10
    def esvaziarPneus(self):
        id = exibirCarrosListados(
            self.__veiculos, "Deseja calibrar a roda de qual carro(id)? ")
        for i in range(len(self.__veiculos)):
            if id == self.__veiculos[i].getId():
                encontrou = True
                for roda in range(4):
                    self.__veiculos[i].mudarRodaEstado(roda, False)
            break

        self.__veiculos[i].imprimirRodas()
        if not encontrou:
            print("Veículo não encontrado")
        time.sleep(3.5)

    # Função 11
    def imprimirPista(self):
        pass

    # Função 12
    def gravarVeiculos(self):
        for veiculo in self.__veiculos:
            f = open('veiculos.txt', 'a') # Abre o arquivo veiculos.txt no modo append
            f.write(veiculo.__str__())

    # Função 13
    def lerVeiculos(self):
        file = open('veiculos.txt', 'r')
        lines = file.readlines()
        print(lines)
        print(type(lines))
        print(len(lines))
        time.sleep(4)



    def menu(self):
        
        clearConsole() # Função para limparar o console
        
        print("\tBem Vindo ao simulador de corrida\nEscolha uma das opções abaixo:")
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
            self.incluirVeiculo()
        if codigo_menu == 2:
            self.excluirVeiculo()
        elif codigo_menu == 3:
            self.abastecerVeiculo()
        elif codigo_menu == 4:
            # movimentarVeiculo()
            pass
        elif codigo_menu == 5:
            # movimentarVeiculos()
            pass
        elif codigo_menu == 6:
            self.imprimirVeiculo()
        elif codigo_menu == 7:
            self.imprimirVeiculos()
        elif codigo_menu == 8:
            self.calibrar_esvaziar_PneuEspecifico()
        elif codigo_menu == 9:
            self.calibrarPneus()
        elif codigo_menu == 10:
            self.esvaziarPneus()
        elif codigo_menu == 11:
            # imprimirPista()
            pass
        elif codigo_menu == 12:
            self.gravarVeiculos()
        elif codigo_menu == 13:
            self.lerVeiculos()
        elif codigo_menu == 14:
            sys.exit('\tAté breve bro!')
