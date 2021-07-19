#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void menorTroco(int arr[], int size, int troco)
{
    int x = 0;
    while (troco > 0)
    {
        if (troco >= arr[x])
        {
            troco = troco - arr[x];
            printf("%d\n", arr[x]);
        }
        else
            x++;
    }
}

int main()
{

    int troco, tam;
    scanf("%d %d", &troco, &tam);
    int arr[tam];
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &arr[i]);
    }
    menorTroco(arr, tam, troco);
    return 0;
}