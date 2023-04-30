import numpy as np
import math


def bissection(a: int, b: int, tolerance, iter: int = 0):
    if np.sign(my_function(a)) == np.sign(my_function(b)):
        raise Exception("The scalars 'a' and 'b' do not bound a root")

    mid = (a + b) / 2

    print(
        f"Iteration: {iter} - a={a:.5f}  b={b:.5f} - f(a): {my_function(a):.5f} - f(b): {my_function(b):.5f} - t={mid:.5f} - f(t): {my_function(mid):.5f}"
    )
    iter += 1

    if (b - a) < tolerance:
        return mid
    if np.abs(my_function(mid)) < tolerance:
        return mid

    elif np.sign(my_function(a)) == np.sign(my_function(mid)):
        a = mid
        return bissection(a, b, tolerance, iter)

    elif np.sign(my_function(b)) == np.sign(my_function(mid)):
        b = mid
        return bissection(a, b, tolerance, iter)


def my_function(x):
    # Exercício 1-a
    return round(math.pow(x, 3) + 3 * math.pow(x, 2) - 1, 5)
    # Exercício 1-b
    return round(x - math.cos(math.radians(x)), 5)


# Exercício 1-a
bissection(-2, 0, 10e-5)

# Exercício 1-b
# bissection(0, (math.pi / 2), 10e-5)
