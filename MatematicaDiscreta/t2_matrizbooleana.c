#include <stdio.h>
#define MAX_ROWS 4
#define MAX_COLS 4

void read_matrix(int rows, int columns, int matrix[][columns], char name)
{
    printf("Digite a matriz %c [%d x %d]\n", name, rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            do
            {
                printf("Valor [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] != 0 && matrix[i][j] != 1)
                    printf("Matrix booleana só aceita valores 0 ou 1!\n\n");
            } while (matrix[i][j] != 0 && matrix[i][j] != 1);
        }
    }
}

void print_matrix(int rows, int columns, int matrix[][columns], char name)
{
    printf("\nMatriz %c: \n", name);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrixes(
    int rows, int columns_a, int columns_b,
    int matrix_a[][columns_a], int matrix_b[][columns_b], int result_matrix[][columns_b])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns_b; j++)
        {
            int value = 0;
            for (int k = 0; k < columns_a; k++)
            {
                value |= (matrix_a[i][k] && matrix_b[k][j]);
            }
            result_matrix[i][j] = value;
        }
    }
}

int main()
{

    int i_a;
    int j_a;
    int i_b;
    int j_b;

    do
    {
        printf("\nDigite o número de linhas da matriz A: ");
        scanf("%d", &i_a);
        printf("Digite o número de colunas da matriz A: ");
        scanf("%d", &j_a);

        if (i_a > MAX_ROWS || j_a > MAX_COLS)
            printf("Número de linhas e colunas não deve ser superior a 4\n");

    } while (i_a > MAX_ROWS || j_a > MAX_COLS);

    do
    {
        printf("\nDigite o número de linhas da matriz B: ");
        scanf("%d", &i_b);
        printf("Digite o número de colunas da matriz B: ");
        scanf("%d", &j_b);

        if (i_b > MAX_ROWS || j_b > MAX_COLS)
            printf("Número de linhas e colunas não deve ser superior a 4\n");
        else if (j_a != i_b)
        {
            printf("Número de linhas da Matriz B deve ser igual ao número de colunas da Matriz A\n");
            printf("Colunas A: %d e Linhas de B %d\n", j_a, i_b);
        }

    } while (i_b > MAX_ROWS || j_b > MAX_COLS || (j_a != i_b));

    int matrix_a[i_a][j_a], matrix_b[i_b][j_b];
    int result_matrix[i_a][j_b];
    char a = 'A';
    char b = 'B';
    char c = 'C';

    read_matrix(i_a, j_a, matrix_a, a);

    read_matrix(i_b, j_b, matrix_b, b);

    multiply_matrixes(i_a, j_a, j_b, matrix_a, matrix_b, result_matrix);

    print_matrix(i_a, j_a, matrix_a, a);
    print_matrix(i_b, j_b, matrix_b, b);
    print_matrix(i_a, j_b, result_matrix, c);

    return 0;
}