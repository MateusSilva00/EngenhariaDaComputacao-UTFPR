from Veiculo import *
from util import *
import sys
import time
import pickle
import os

class Simulador:
    def __init__(self):
        self.__veiculos: list = [] # Inicializa uma lista vazia 

    # Função 1
    def incluirVeiculo(self):
        marca_veiculo = input('Digite a marca do Veículo: ')
        veiculo = Veiculo(marca_veiculo) # Criar o objeto veículo com base na marca da carro
        self.__veiculos.append(veiculo) # Adiciona o veículo na lista de veículos
        time.sleep(3)

    # Função 2
    def excluirVeiculo(self):
        if len(self.__veiculos) != 0:
            id  =  exibirCarrosListados(self.__veiculos, "Deseja excluir qual carro(id)? ")
            encontrou = False
            for i in range(len(self.__veiculos)): # Percorre a lista para encontrar o veículo
                if id == self.__veiculos[i].getId(): # Verifica se o código digitado existe
                    print("Veículo encontrado e excluído com sucesso")
                    del self.__veiculos[i]
                    encontrou = True
                    break

            if not encontrou:
                print("Veículo não encontrado")
        
        else:
            print("Sem carros cadastrados")

        time.sleep(3)

    # Função 3
    def abastecerVeiculo(self):
        if len(self.__veiculos) != 0:

            id = exibirCarrosListados(self.__veiculos, "Qual Veículo deseja abastecer(id)? ")
            encontrou = False
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].getId():
                    encontrou = True
                    abastecer = int(input("Quanto litros deseja abastecer: "))
                    self.__veiculos[i].setCombustivel(abastecer)
                    break

            if not encontrou:
                print("Veículo não encontrado")
        
        else:
            print("Sem carros cadastrados")

        time.sleep(3)

    # Função 4
    def movimentarVeiculo(self):
        if len(self.__veiculos) != 0:
            id = exibirCarrosListados(self.__veiculos, "Qual veículo deseja movimentar(id)? ")
            encontrou = False
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].getId():
                    encontrou = True
                    self.__veiculos[i].mover()
                    break

            if not encontrou:
                print("Veículo não encontrado")

        else:
            print("Sem carros cadastrados")
        
        time.sleep(4)

    # Função 5
    def movimentarVeiculos(self):
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].imprimirCarroID()
                self.__veiculos[i].mover()
            time.sleep(5)
        else:
            print("Sem carros cadastrados")

    # Função 6
    def imprimirVeiculo(self):
        if len(self.__veiculos) != 0:
            id = exibirCarrosListados(self.__veiculos, "Qual veículo deseja imprimir(id)? ")
            encontrou = False

            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].getId():
                    encontrou = True
                    self.__veiculos[i].imprimirCarroCompleto()
                    break

            if not encontrou:
                print("Veículo não encontrado")

        else:
            print("Sem carros cadastrados")
        time.sleep(7)

    # Função 7
    def imprimirVeiculos(self):
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].imprimirCarroCompleto()
        
        else:
            print("Sem carros cadastrados")
        time.sleep(15)

    # Função 8
    def calibrar_esvaziar_PneuEspecifico(self):
        if len(self.__veiculos) != 0:
            id = exibirCarrosListados(self.__veiculos, "Deseja calibrar/esvaziar a roda de qual carro(id) ? ")
            encontrou = False
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
        
        else:
            print("Sem carros cadastrados")
        time.sleep(5)

    # Função 9
    def calibrarPneus(self):
        if len(self.__veiculos) != 0:
            id = exibirCarrosListados(self.__veiculos, "Deseja calibrar a roda de qual carro(id)? ")
            encontrou = False
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].getId():
                    encontrou = True
                    for roda in range(4):
                        self.__veiculos[i].mudarRodaEstado(roda, True)
                    break

            self.__veiculos[i].imprimirRodas()
            if not encontrou:
                print("Veículo não encontrado")
        else:
            print("Sem carros cadastrados")
        time.sleep(3.5)

    # Função 10
    def esvaziarPneus(self):
        if len(self.__veiculos) != 0:
            encontrou = False
            id = exibirCarrosListados(self.__veiculos, "Deseja esvaziar a roda de qual carro(id)? ")
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].getId():
                    encontrou = True
                    for roda in range(4):
                        self.__veiculos[i].mudarRodaEstado(roda, False)
                    break

            self.__veiculos[i].imprimirRodas()

            if not encontrou:
                print("Veículo não encontrado")
        
        else:
            print("Sem carros cadastrados")

        time.sleep(3.5)

    # Função 11
    def imprimirPista(self):
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].desenhaCarro()
            time.sleep(10)
        
        else:
            print("Ainda não há carros cadastrados!\n")
            time.sleep(2.5)

    # Função 12
    def gravarVeiculos(self):
        if len(self.__veiculos) != 0:
            if os.path.isfile('veiculos.txt'):
                mode:str = 'ab' # Se o arquivo já existe, abra no modo append 
            else:
                mode:str = 'wb' # Se o arquivo não exsite, crie no modo write

            with open('veiculos.txt', mode=mode) as file:
                pickle.dump(len(self.__veiculos), file)
                for veiculo in self.__veiculos:
                    pickle.dump(veiculo, file)
            print("veiculos gravados com sucesso")
        
        else:
            print('Não há veículos para serem gravados')
        
        time.sleep(3.2)

    # Função 13
    def lerVeiculos(self):
        if os.path.isfile('veiculos.txt'):
            with open('veiculos.txt', "rb") as file:
                for _ in range(pickle.load(file)):
                    self.__veiculos.append(pickle.load(file))
            print('veiculos lidos com sucesso')

        else:
            print("Nenhum arquivo encontrado")    
        time.sleep(3.2) 

    # Função 14
    def pagarIpva(self):
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].setIpva()
            print("Ipva's pagos com sucesso")
            time.sleep(4)
        else:
            print("Ainda não há carros cadastrados!\n")
            time.sleep(2.5)

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
        print('\t14 - Pagar IPVA de todos os veículos')
        print('\t15 - Sair da aplicação')
                
        codigo_menu = int(input("\nQual sua opção: "))

        if codigo_menu == 1:
            self.incluirVeiculo()
        elif codigo_menu == 2:
            self.excluirVeiculo()
        elif codigo_menu == 3:
            self.abastecerVeiculo()
        elif codigo_menu == 4:
            self.movimentarVeiculo()
            pass
        elif codigo_menu == 5:
            self.movimentarVeiculos()
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
            self.imprimirPista()
            pass
        elif codigo_menu == 12:
            self.gravarVeiculos()
        elif codigo_menu == 13:
            self.lerVeiculos()
        elif codigo_menu == 14:
            self.pagarIpva()
        elif codigo_menu == 15:
            sys.exit('Até breve bro!')
        else:
            print("Codigo inválido, tente novamente")
            time.sleep(1.3)