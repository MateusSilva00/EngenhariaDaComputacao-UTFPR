# Exibe os carros listados junto com algum texto e retorna o código do carro inserido pelo usuário
def exibirVeiculosListados(veiculos: list, text:str) -> int:
    print("\n*** VEÍCULOS LISTADOS ***")
    for veiculo in veiculos:
        print(veiculo.imprimirVeiculoID())
    
    codigo = int(input("\n" + text))
    return codigo


def exibirTiposVeiculos():
    print("\tB - Bicicleta")
    print("\tE - Carro Esportivo")
    print("\tM - Motocicleta")
    print("\tC - Carro Passeio")