#include <stdio.h>

int DAC_pow(int base, int expoente)
{
    int x;
    if (expoente == 0)
        return 1;
    else if (expoente == 1)
        return base;
    else
    {
        if (expoente % 2 == 0)
        {
            x = DAC_pow(base, expoente / 2);
            return x * x;
        }
        else
        {
            x = DAC_pow(base, (expoente - 1) / 2);
            return x * x * base;
        }
    }
}

int main()
{

    int base, expo;
    printf("Insira a base: ");
    scanf("%d", &base);
    printf("Insira o expoente: ");
    scanf("%d", &expo);

    int resultado = DAC_pow(base, expo);
    printf("\n%d elevado a %d é igual a %d", base, expo, resultado);

    return 0;
}