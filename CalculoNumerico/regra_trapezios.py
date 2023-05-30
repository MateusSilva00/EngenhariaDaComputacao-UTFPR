import numpy as np
from typing import Tuple


def using_numpy():
    a = 0
    b = 1
    m = 5
    h = (b - a) / (m - 1)
    x = np.linspace(a, b, m)
    f = np.exp(np.power(x, 2))

    I_trap = (h / 2) * (f[0] + 2 * sum(f[1 : m - 1]) + f[m - 1])
    err_trap = 2 - I_trap

    print(I_trap)
    print(err_trap)


def function(point_x0: int, point_x1: int) -> Tuple[float, float]:
    """
    Função utilizada para calcular a integral

    Args
        points_x0: Valor de X no inicio do intervalo
        points_x1: Valor de X no final do intervalo

    Returns
        O valor da função no ínicio e no final do intervalo
    """
    return (np.exp(np.power(point_x0, 2)), np.exp(np.power(point_x1, 2)))


def regra_dos_trapezios(
    interval_a: int, interval_b: int, qt_trapezios: int, precision: int
):
    """
    Calcula uma integral utilizando a regra dos trapézaios

    Args:
        interval_a: Inteiro para o limite de integração 'a'
        interval_b: Inteiro para o limite de integração 'b'
        qt_trapezios: Número de trapézios para serem utilizados
        precision: Número de casas de decimais para o retorno da integral

    Return
        itr: Valor da integral
    """

    values = np.linspace(interval_a, interval_b, qt_trapezios + 1)
    height = (interval_b - interval_a) / qt_trapezios

    itr = 0
    for idx in range(len(values) - 1):
        value_a, value_b = function(point_x0=values[idx], point_x1=values[idx + 1])
        itr += (height / 2) * (value_a + value_b)

    itr = np.round(itr, precision)
    return itr


def main():
    itr = regra_dos_trapezios(interval_a=0, interval_b=1, qt_trapezios=4, precision=6)
    print(itr)


if __name__ == "__main__":
    main()
