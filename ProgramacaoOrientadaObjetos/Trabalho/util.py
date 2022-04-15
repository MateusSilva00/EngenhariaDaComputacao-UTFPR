import os

def clearConsole() -> None:
    command = 'clear'
    if os.name in ('nt', 'dos'):  # Verifica se máquina é um ruindows
        command = 'cls'
    os.system(command)

def exibirCarrosListados(veiculos: list, text: str) -> int:
    print("***  CARRO LISTADOS  ***")
    for veiculo in veiculos:
        print(veiculo.imprimirCarroID())
    
    codigo = int(input(text))
    return codigo

