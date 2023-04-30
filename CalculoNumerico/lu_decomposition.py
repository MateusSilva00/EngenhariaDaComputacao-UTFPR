import numpy as np
from pprint import pprint
from typing import NewType, Tuple

MATRIX_COEF = NewType("MATRIX_COEF", np.array)
CONST = NewType("CONST", np.array)
EQUATION = Tuple[MATRIX_COEF, CONST]


def make_equation(size_m: int, h: float) -> EQUATION:
    matriz_coef = np.zeros((size_m, size_m))
    consts = np.zeros((size_m, 1), dtype=int)
    consts[0] = 1
    consts[-1] = 1

    for i in range(size_m):
        matriz_coef[i, i] = -2 * (1 + h**2)
        if i > 0:
            matriz_coef[i, i - 1] = 1
        if i < size_m - 1:
            matriz_coef[i, i + 1] = 1

    matriz_coef[size_m - 1, size_m - 1] = -2 * (1 + h**2)

    return matriz_coef, consts


def lu_decomposition(matriz: np.matrix) -> tuple[np.array, np.array]:
    U = np.copy(matriz)
    size_matriz: int = np.shape(U)[0]
    L = np.eye(size_matriz)

    # Itera sobre as colunas
    for j in np.arange(size_matriz - 1):
        # Itera sobre as linhas abaixo da diagonal principal
        for i in np.arange(j + 1, size_matriz):
            # Fator de elimnição gaussiana
            L[i, j] = U[i, j] / U[j, j]

            # Atualiza a linha i usando a linha j e o fator de eliminação
            for k in np.arange(j + 1, size_matriz):
                U[i, k] = U[i, k] - (L[i, j] * U[j, k])
            U[i, j] = 0

    with open("outfile.txt", "w") as outfile:
        outfile.writelines("Matriz de entrada\n")
        np.savetxt(outfile, matriz, fmt="%d")

        outfile.writelines("Matriz L\n")
        np.savetxt(outfile, L, fmt="%d")

        outfile.writelines("Matriz U\n")
        np.savetxt(outfile, U, fmt="%d")

    return L, U


def solving_lu(matrix_L, matrix_U, coef: np.array):

    n = len(coef)
    size_solution = len(matrix_U)
    y = np.zeros((size_solution, 1))

    # Substituição direta para resolver Ly = B
    for i in range(n):
        y[i] = coef[i]
        for j in range(i):
            y[i] = y[i] - (matrix_L[i][j] * y[j])
        y[i] /= matrix_L[i][i]

    # Substituição regressiva para resolver Ux = y
    x = np.zeros((size_solution, 1))
    for i in range(n - 1, -1, -1):
        x[i] = y[i]
        for j in range(i + 1, n):
            x[i] -= matrix_U[i][j] * x[j]
        x[i] /= matrix_U[i][i]

    with open("outfile.txt", "a") as outfile:
        outfile.writelines(f"Conjunto solução\n{x}")

    return x


def main():
    matrix, consts = make_equation(30, 0.1)
    U, L = lu_decomposition(matrix)
    solution = solving_lu(U, L, consts)


if __name__ == "__main__":
    main()
