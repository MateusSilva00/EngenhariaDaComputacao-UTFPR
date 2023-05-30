from typing import Tuple
import numpy as np


def function(point_x0: int, point_x1: int, point_x2: int) -> Tuple[float, float, float]:
    """
    Função utilizada para calcular a integral

    Args
        points_x0: Valor de X no inicio do intervalo
        points_x1: Valor de X para os pares
        points_x2: Valor dde X para os impares
    Returns
        O valor da função no ínicio e no final do intervalo
    """
    return (
        np.exp(np.power(point_x0, 2)),
        np.exp(np.power(point_x1, 2)),
        np.exp(np.power(point_x2, 2)),
    )


def derivada_quarta(x: float) -> float:
    """
    Cálculo o valor da quarta derivada da função acima

    Return
        O valor da função em x
    """
    return np.exp(np.power(x, 2)) * (12 + 48 * np.power(x, 2) + 16 * np.power(x, 4))


def regra_de_simpson(interval_a: int, interval_b, qt_intervalos: int, precision: int):
    """
    Calcula uma integral utilizando a regra de Simpson

    Args:
        interval_a: Inteiro para o limite de integração 'a'
        interval_b: Inteiro para o limite de integração 'b'
        qt_intervalos: Número (par) de intervalos para serem utilizados
        precision: Número de casas de decimais para o retorno da integral

    Return
        itr: Valor da integral
    """
    values = np.linspace(interval_a, interval_b, qt_intervalos + 1)
    height = (interval_b - interval_a) / qt_intervalos

    itr = 0
    m = int(qt_intervalos / 2) + 1
    values = np.insert(values, 1, 0)

    for idx in range(1, m):
        init = values[2 * idx - 1]
        mid = values[2 * idx]
        end = values[2 * idx + 1]
        value_a, value_b, value_c = function(init, mid, end)
        itr += (height / 3) * (value_a + (4 * value_b) + value_c)

    itr = np.round(itr, precision)

    valores_derivada = [derivada_quarta(i / 1000) for i in range(0, 1000)]
    m4 = max(valores_derivada)

    etr = ((interval_b - interval_a) / 180) * m4 * np.power(height, 4)

    return itr, etr


def main():
    itr, etr = regra_de_simpson(0, 1, 4, precision=6)
    print(itr, etr)


if __name__ == "__main__":
    main()
