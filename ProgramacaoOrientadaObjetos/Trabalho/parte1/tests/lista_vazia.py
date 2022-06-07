lista = [None] * 10
print(lista)

frutas: list = ['Banana', 'Maça', 'Abacate', 'Limão']
# print(frutas)

# for fruta in frutas:
    # print(fruta)

for i in range(len(frutas)):
    print(f"{i} - {frutas[i]}")