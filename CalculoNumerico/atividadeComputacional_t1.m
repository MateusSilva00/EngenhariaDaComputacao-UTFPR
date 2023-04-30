function solution = main()
    [matrix, consts] = make_equation(30, 0.1);
    [L, U] = lu_decomposition(matrix);
    solution = solving_lu(L, U, consts);
    disp(solution);
end

function [matriz_coef, consts] = make_equation(size_m, h)
    matriz_coef = zeros(size_m);
    consts = zeros(size_m, 1);
    consts(1) = 1;
    consts(end) = 1;

    for i = 1:size_m
        matriz_coef(i, i) = -2 * (1 + h^2);
        if i > 1
            matriz_coef(i, i - 1) = 1;
        end
        if i < size_m
            matriz_coef(i, i + 1) = 1;
        end
    end

    matriz_coef(end, end) = -2 * (1 + h^2);
end

function [L, U] = lu_decomposition(matriz)
    U = matriz;
    size_matriz = size(U, 1);
    L = eye(size_matriz);

    for j = 1:(size_matriz - 1)
        for i = (j + 1):size_matriz
            L(i, j) = U(i, j) / U(j, j);
            U(i, :) = U(i, :) - L(i, j) * U(j, :);
        end
    end
end

function [x] = solving_lu(matrix_L, matrix_U, coef)
    n = length(coef);
    size_solution = length(matrix_U);
    y = zeros(size_solution, 1);

    for i = 1:n
        y(i) = coef(i);
        for j = 1:i-1
            y(i) = y(i) - matrix_L(i, j) * y(j);
        end
        y(i) = y(i) / matrix_L(i, i);
    end

    x = zeros(size_solution, 1);
    for i = n:-1:1
        x(i) = y(i);
        for j = (i + 1):n
            x(i) = x(i) - matrix_U(i, j) * x(j);
        end
        x(i) = x(i) / matrix_U(i, i);
    end
end


