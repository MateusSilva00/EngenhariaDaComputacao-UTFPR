import numpy as np

matrix = np.matrix([[1, 0, 1, 0], [1, 1, 0, 1], [2, 3, 1, 1]])
# result = np.matrix([0, 1, 1])
size = 3

for j in range(0, size - 1):
    for i in range(j + 1, size):
        m = matrix[i, j] / matrix[j, j]
        matrix[i, :] = matrix[i, :] - (m * matrix[j, :])
        # result[0, :] = result[0, :] - (m * result[0, :])


print(f"Matriz A\n{matrix[:3, :3]}\nResposta\n{matrix[:, -1].tolist()}")
