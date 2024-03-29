# Importando bibliotecas do python
from cmath import e
from time import sleep
from utils import *

# Importando classes
from Veiculo import *
from VeiculoMotorizado import VeiculoMotorizado
from Bicicleta import Bicicleta
from Esportivo import Esportivo
from Motocicleta import Motocicleta
from CarroPasseio import CarroPasseio
import pickle
import os

class Simulador():
    def __init__(self):
        self.__veiculos: list = [] # Inicializa uma lista vazina
        self.__letrasValidas = ['B', 'E', 'M', 'C']
        print("\n\tBem Vindo ao simulador de corrida")

    # Função 1
    def incluirVeiculo(self) -> None:
        print("\nQual tipo de veículo deseja incluir: ")
        exibirTiposVeiculos()
        
        try:
            tipoVeiculo = input("Opção: ").upper()
            if tipoVeiculo in self.__letrasValidas:
                marca_veiculo = input("Digite a marca do veículo: ")
                if tipoVeiculo == 'B':
                    veiculo = Bicicleta(marca_veiculo, 2)
                elif tipoVeiculo ==  'E':
                    veiculo = Esportivo(marca_veiculo, 4)
                elif tipoVeiculo == 'M':
                    veiculo = Motocicleta(marca_veiculo, 2)
                else:
                    veiculo = CarroPasseio(marca_veiculo, 4)
                self.__veiculos.append(veiculo)
            else:
                print("Opção inválida!\n")

        except ValueError:
            print("O valor precisa ser uma string!\n")

    # Função 2
    def excluirVeiculo(self) -> None:
        if len(self.__veiculos) != 0:
            id = exibirVeiculosListados(self.__veiculos, "Deseja excluir qual veiculo (id)? ")
            encontrou = False
            # Percorre a lista para encontrar o veículo
            for i in range(len(self.__veiculos)):
                # Verifica se o código digitado existe
                if id == self.__veiculos[i].id:
                    print("{} encontrado e excluído com sucesso".format(self.__veiculos[i].marca))
                    del self.__veiculos[i]
                    encontrou = True
                    break

            if not encontrou:
                print("veículo não encontrado")
        else:
            print("Não há veículos cadastrados!")

    # Função 3
    def abastecerVeiculo(self) -> None:
        if len(self.__veiculos) != 0:
            id = exibirVeiculosListados(self.__veiculos, "Qual veículo deseja abastecer(id)? ")
            encontrou = False
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].id:
                    encontrou = True
                    if isinstance(self.__veiculos[i], VeiculoMotorizado):
                        abastecer = float(input("Quanto litros deseja abastecer: "))
                        self.__veiculos[i].setCombustivel = abastecer
                    else:
                        print("Impossível abastecer uma bibicleta meu caro")
                    break                     

            if not encontrou:
                print("veículo não encontrado")
        else:
            print("Não há veículos cadastrados!")
    
    # Função 4
    def movimentarVeiculoEspecifico(self) -> None:
        if len(self.__veiculos) != 0:
            id = exibirVeiculosListados(self.__veiculos, "Qual veículo deseja movimentar(id) ? ")
            encontrou = False
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].id:
                    encontrou = True
                    self.__veiculos[i].mover()
                    break

            if not encontrou:
                print("veículo não encontrado")
        else:
            print("Não há veículos cadastrados!")

    # Função 5
    def movimentarVeiculoTipo(self) -> None:
        if len(self.__veiculos) != 0:
            print("Qual tipo de veículo deseja movimentar")
            exibirTiposVeiculos()
            try:
                opcao = input("Opcao: ").upper()
                if opcao in self.__letrasValidas:
                    for i in range(len(self.__veiculos)):
                        if self.__veiculos[i].letra == opcao:
                            self.__veiculos[i].mover()
                else:
                    print("Opção inválida")
            except ValueError:
                print("O valor precisa ser uma string!\n")
        else: 
            print("Não há veículos cadastrados!")

    # Função 6
    def movimentarVeiculos(self) -> None:
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].mover()
        else:
            print("Não há veículos cadastrados!")

    # Função 7 
    def imprimirDadosVeiculos(self) -> None:
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].exibirVeiculoCompleto()
        else:
            print("Não há veículos cadastrados")

    # Função 8
    def imprimirDadosVeiculosTipo(self) -> None:
        if len(self.__veiculos) != 0:
            print("Qual tipo de veículo deseja ver")
            exibirTiposVeiculos()
            try:
                opcao = input("Opcao: ").upper()
                if opcao in self.__letrasValidas:
                    for i in range(len(self.__veiculos)):
                        if self.__veiculos[i].letra == opcao:
                            self.__veiculos[i].exibirVeiculoCompleto()
                else:
                    print("Opção inválida")
            except ValueError:
                print("O valor precisa ser uma string!\n")
        else:
            print("Não há veículos cadastrados!")

    # Função 9
    def calibrar_esvaziar_PneuEspecifico(self) -> None:
        if len(self.__veiculos) != 0:
            id = exibirVeiculosListados(self.__veiculos, "Deseja calibrar/esvaziar roda de qual veiculo (id)? ")
            encontrou = False
            for i in range(len(self.__veiculos)):
                if id == self.__veiculos[i].id:
                    encontrou = True
                    self.__veiculos[i].exibirRodas()
                    try:
                        acao = int(input("Deseja\n1 - Esvaziar\n2 - Calibrar ? "))

                        if acao == 1:
                            roda = int(input("Qual roda deseja esvaziar ? ")) - 1
                            self.__veiculos[i].mudarRodaEstado(roda, False)
                        else:
                            roda = int(input("Qual roda deseja calibrar ? ")) - 1
                            self.__veiculos[i].mudarRodaEstado(roda, True)
                        break
                    except ValueError:
                        print("O valor precisar ser um inteiro!\n")

            self.__veiculos[i].exibirRodas()
        else:
            print("Não há veículos cadastrados!")

    # Função 10
    def calibrarVeiculoTipo(self) -> None:
        if len(self.__veiculos) != 0:
            print("Qual tipo de veículo deseja calibrar")
            exibirTiposVeiculos()
            try:
                opcao = input("Opcao: ").upper()
                if opcao in self.__letrasValidas:
                    for i in range(len(self.__veiculos)):
                        if self.__veiculos[i].letra == opcao:
                            for roda in range(self.__veiculos[i].rodas):
                                self.__veiculos[i].mudarRodaEstado(roda, True)
                    print("Rodas calibradas com sucesso!")
                else:
                    print("Opção inválida")
            except ValueError:
                print("O valor precisa ser uma string!\n")
        else:
            print("Não há veículos cadastrados")

    # Função 11
    def esvaziarVeiculoTipo(self) -> None:
        if len(self.__veiculos) != 0:
            print("Qual tipo de veículo deseja calibrar")
            exibirTiposVeiculos()
            try:
                opcao = input("Opcao: ").upper()
                if opcao in self.__letrasValidas:
                    for i in range(len(self.__veiculos)):
                        if self.__veiculos[i].letra == opcao:
                            for roda in range(self.__veiculos[i].rodas):
                                self.__veiculos[i].mudarRodaEstado(roda, False)
                    print("Rodas esvaziadas com sucesso!")
                else:
                    print("Opção inválida")
            except ValueError:
                print("O valor precisa ser uma string!\n")
        else:
            print("Não há veículos cadastrados")

    # Função 12
    def imprimirPista(self) -> None:
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
                self.__veiculos[i].desenhar()            
            sleep(3)
        else:
            print("Ainda não há carros cadastrados!\n")

    # Função 13
    def gravarVeiculos(self) -> None:
        if len(self.__veiculos) != 0:
            with open('veiculos.txt', mode='wb') as file:
                pickle.dump(len(self.__veiculos), file)
                for veiculo in self.__veiculos:
                    pickle.dump(veiculo, file)
            print("Veículos gravados com sucesso")
        else:
            print("Não há veículos para serem gravados")

    # Função 14
    def lerVeiculos(self) -> None:
        if os.path.isfile('veiculos.txt'):
            for i in range(len(self.__veiculos)):
                del self.__veiculos[i]
            
            with open('veiculos.txt', 'rb') as file:
                for _ in range(pickle.load(file)):
                    self.__veiculos.append(pickle.load(file))
            print("Veículos lidos com sucesso!")
        else:
            print("Nenhum arquivo encontrado")
    

    # Função 15
    def pagarIpvas(self):
        if len(self.__veiculos) != 0:
            for i in range(len(self.__veiculos)):
               if isinstance(self.__veiculos[i], VeiculoMotorizado):
                   self.__veiculos[i].setIpva = True
            print("Todos veículos pagos com sucesso")
        
        else:
            print("Sem veículos cadastrado")


    def menu(self) -> None:
        print("\nEscolha uma das opções abaixo: ")
        print("\t1 - Incluir veículo")
        print("\t2 - Excluir veículo")
        print("\t3 - Abastecer veículo")
        print("\t4 - Movimentar um veículo específco")
        print("\t5 - Movimentar veículos por tipo")
        print("\t6 - Movimentar todos os veículos")
        print("\t7 - Imprimir todos os dados de todos os veículos")
        print("\t8 - Imprimir dados de veículos por tipo")
        print("\t9 - Esvaziar/Calibrar um penu específico")
        print("\t10 - Calibrar todos os pneus de veículos por tipo")
        print("\t11 - Esvaziar todos os pneus de veículos por tipo")
        print("\t12 - Imprimir pista de corrida")
        print("\t13 - Gravar veículos em arquivo")
        print("\t14 - Ler veículos do arquivo")
        print("\t15 - Pagar todos os IPVA's")
        print("\t0 - Sair")

        try: 
            codigo_menu = int(input("\nQual sua opção: "))  
            if codigo_menu == 1:
                self.incluirVeiculo()
            elif codigo_menu == 2:
                self.excluirVeiculo()

            elif codigo_menu == 3:
                self.abastecerVeiculo()
            
            elif codigo_menu == 4:
                self.movimentarVeiculoEspecifico()

            elif codigo_menu == 5:
                self.movimentarVeiculoTipo()
            
            elif codigo_menu == 6:
                self.movimentarVeiculos()

            elif codigo_menu == 7:
                self.imprimirDadosVeiculos()
            
            elif codigo_menu == 8:
                self.imprimirDadosVeiculosTipo()
            
            elif codigo_menu == 9:
                self.calibrar_esvaziar_PneuEspecifico()
            
            elif codigo_menu == 10:
                self.calibrarVeiculoTipo()
            
            elif codigo_menu == 11:
                self.esvaziarVeiculoTipo()

            elif codigo_menu == 12:
                self.imprimirPista()

            elif codigo_menu == 13:
                self.gravarVeiculos()
            
            elif codigo_menu == 14:
                self.lerVeiculos()

            elif codigo_menu == 15:
                self.pagarIpvas()

            elif codigo_menu == 0:
                print("Saindo do programa... Até mais ;)")
                sleep(1.23)
                exit()

        except ValueError:
            print("O valor precisa ser um número inteiro!\n")

        sleep(1.3)
