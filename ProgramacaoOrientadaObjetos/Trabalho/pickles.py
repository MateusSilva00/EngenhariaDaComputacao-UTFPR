import pickle
import math
from Veiculo import *

carro = Veiculo('Mustang')
file_pi = open('filename.txt', 'wb')
pickle.dump(carro, file_pi)

filename = 'filename.txt'
with open(filename, 'wb') as f:
    classification_dict = pickle.load(f)
    print(classification_dict)
