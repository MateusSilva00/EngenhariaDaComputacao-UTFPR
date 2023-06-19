import numpy as np
import matplotlib.pyplot as plt


def regra_dos_trapezios(interval_a, interval_b, qt_trapezios, precision, func):
    values = np.linspace(interval_a, interval_b, qt_trapezios + 1)
    height = (interval_b - interval_a) / qt_trapezios

    itr = 0
    for idx in range(len(values) - 1):
        value_a = func(values[idx])
        value_b = func(values[idx + 1])
        itr += (height / 2) * (value_a + value_b)

    itr = np.round(itr, precision)
    return itr


def my_function(x):
    return x


def phi(x, c1, c2, c3, c4):
    return c1 * np.sin(x) + c2 * np.sin(2 * x) + c3 * np.sin(3 * x) + c4 * np.sin(4 * x)


def gaussian_elimination(A, b):
    n = len(A)
    for i in range(n):
        # Pivoteamento parcial
        max_idx = i
        max_val = abs(A[i, i])
        for k in range(i + 1, n):
            if abs(A[k, i]) > max_val:
                max_idx = k
                max_val = abs(A[k, i])
        A[[i, max_idx]] = A[[max_idx, i]]
        b[[i, max_idx]] = b[[max_idx, i]]

        # Eliminação gaussiana
        for j in range(i + 1, n):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            b[j] -= factor * b[i]

    # Substituição retroativa
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1 :], x[i + 1 :])) / A[i, i]

    return x


def solution():
    # Construindo o sistema linear de quadrados mínimos
    interval_a = -np.pi
    interval_b = np.pi
    qt_trapezios = 100
    precision = 8

    A = np.zeros((4, 4))
    b = np.zeros(4)

    for i in range(4):
        for j in range(4):
            A[i, j] = regra_dos_trapezios(
                interval_a,
                interval_b,
                qt_trapezios,
                precision,
                lambda x: np.sin((j + 1) * x) * np.sin((i + 1) * x),
            )
        b[i] = regra_dos_trapezios(
            interval_a,
            interval_b,
            qt_trapezios,
            precision,
            lambda x: x * np.sin((i + 1) * x),
        )

    coefficients = gaussian_elimination(A, b)
    print(coefficients)

    x = np.linspace(interval_a, interval_b, 1000)
    f_values = my_function(x)
    phi_values = phi(x, *coefficients)

    plt.plot(x, f_values, label="f(x) = x")
    plt.plot(x, phi_values, label="φ(x)")
    plt.legend()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title("Aproximação de Quadrados Mínimos")
    plt.show()
