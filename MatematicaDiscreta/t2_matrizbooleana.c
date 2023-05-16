#include <stdio.h>
#include <stdbool.h>
#define ROWS 4
#define COLS 4

void read_matrix(bool matrix[][COLS], char name)
{
    printf("Digite a matriz %c [%d x %d]\n", name, ROWS, COLS);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("Valor [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(bool matrix[][4], char name)
{
    printf("\n\nMatriz %c: \n", name);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrixes(bool matrix_a[][4], bool matrix_b[][4], bool result_matrix[][4])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            bool value = false;
            for (int k = 0; k < ROWS; k++)
            {
                value |= matrix_a[i][k] && matrix_b[k][j];
            }
            result_matrix[i][j] = value;
        }
    }
}

int main()
{
    bool matrix_a[ROWS][COLS], matrix_b[ROWS][COLS];
    bool result_matrix[ROWS][COLS];
    char a = 'A';
    char b = 'B';
    char c = 'C';

    read_matrix(matrix_a, a);
    print_matrix(matrix_a, a);

    read_matrix(matrix_b, b);
    print_matrix(matrix_b, b);

    multiply_matrixes(matrix_a, matrix_b, result_matrix);
    print_matrix(result_matrix, c);

    return 0;
}