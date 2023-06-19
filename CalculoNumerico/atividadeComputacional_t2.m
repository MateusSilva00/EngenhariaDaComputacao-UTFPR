function atividadeComputacional_t2()
    % Construindo o sistema linear de quadrados mínimos
    interval_a = -pi;
    interval_b = pi;
    qt_trapezios = 100;

    A = zeros(4, 4);
    b = zeros(4, 1);

    for i = 1:4
        for j = 1:4
            A(i, j) = regra_dos_trapezios(interval_a, interval_b, qt_trapezios, @(x) sin((j) * x) * sin((i) * x));
        end
        b(i) = regra_dos_trapezios(interval_a, interval_b, qt_trapezios, @(x) x * sin((i) * x));
    end

    disp("Sistema Linear")
    disp("Matriz A:")
    disp(A)
    disp("Matriz b:")
    disp(b)

    coefficients = gaussian_elimination(A, b);
    disp("Coeficientes:");
    disp(coefficients);

    fig = figure;
    set(fig, 'Units', 'Normalized', 'Position', [0 0 1 1]);

    x = linspace(interval_a, interval_b, 1000);
    f_values = my_function(x);
    phi_values = phi(x, coefficients(1), coefficients(2), coefficients(3), coefficients(4));

    plot(x, f_values);
    hold on;
    plot(x, phi_values);
    hold off;
    legend("f(x) = x", "φ(x)");
    xlabel("x");
    ylabel("y");
    title("Aproximação de Quadrados Mínimos");
    set(fig, 'WindowState', 'maximized');
end

function itr = regra_dos_trapezios(interval_a, interval_b, qt_trapezios, func)
    values = linspace(interval_a, interval_b, qt_trapezios + 1);
    height = (interval_b - interval_a) / qt_trapezios;

    itr = 0;
    for idx = 1:(length(values) - 1)
        value_a = func(values(idx));
        value_b = func(values(idx + 1));
        itr += (height / 2) * (value_a + value_b);
    end

    itr;
end

function value = my_function(x)
    value = x;
end

function value = phi(x, c1, c2, c3, c4)
    value = c1 * sin(x) + c2 * sin(2 * x) + c3 * sin(3 * x) + c4 * sin(4 * x);
end

function x = gaussian_elimination(A, b)
    n = length(A);
    for i = 1:n
        % Pivoteamento parcial
        [max_val, max_idx] = max(abs(A(i:n, i)));
        max_idx += i - 1;
        A([i, max_idx], :) = A([max_idx, i], :);
        b([i, max_idx]) = b([max_idx, i]);

        % Eliminação gaussiana
        for j = (i + 1):n
            factor = A(j, i) / A(i, i);
            A(j, i:end) -= factor * A(i, i:end);
            b(j) -= factor * b(i);
        end
    end

    % Substituição retroativa
    x = zeros(n, 1);
    for i = n:-1:1
        x(i) = (b(i) - dot(A(i, i + 1:end), x(i + 1:end))) / A(i, i);
    end
end

atividadeComputacional_t2()


