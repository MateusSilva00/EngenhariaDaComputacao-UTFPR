from numpy import array, diag, diagflat, dot, savetxt, newaxis

matriz_a = array([[10, 2, 1], [1, 5, 1], [2, 3, 10]])
matriz_b = array([7, -8, 9])

initial_guess = array([0.7, -1.6, 0.6])

with open("jacobi.txt", "w") as outfile:
    outfile.writelines("Matriz A\n")
    savetxt(outfile, matriz_a, fmt="%d")

    outfile.writelines("Matriz Resultados\n")
    savetxt(outfile, matriz_b, fmt="%d")

    outfile.writelines("Chute Inicial\n")
    print(initial_guess)
    savetxt(outfile, initial_guess, fmt="%d")


def jacobi(matriz_a: array, matriz_b: array, guess: array):
    diagonal = diag(matriz_a)
    # isolated = (matriz_a - diagflat(diagonal)) * (-1)
    # isolated = isolated / diagonal[:, newaxis]
    isolated = matriz_a - diagflat(diagonal)

    with open("jacobi.txt", "a") as outfile:
        outfile.writelines("Diagonal A\n")
        savetxt(outfile, diagonal, fmt="%.2f")

        outfile.writelines("Diagonal Isolando\n")
        savetxt(outfile, isolated, fmt="%.2f")

    for _ in range(2):
        guess = (matriz_b - dot(isolated, guess)) / diagonal

    with open("jacobi.txt", "a") as outfile:
        outfile.writelines("Resultado\n")
        savetxt(outfile, guess, fmt="%.2f")


jacobi(matriz_a, matriz_b, initial_guess)
