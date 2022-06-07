import os

def clearConsole() -> None:
    command = 'clear'
    if os.name in ('nt', 'dos'):  # Verifica se máquina é um ruindows
        command = 'cls' # se for, vai executar o commando cls
    os.system(command)

# Exibe os carros listados junto com algum texto e retorna o código do carro inserido pelo usuário 
def exibirCarrosListados(veiculos: list, text: str) -> int:
    print("***  CARRO LISTADOS  ***") 
    for veiculo in veiculos:
        print(veiculo.imprimirCarroID())
    
    codigo = int(input(text))
    return codigo

