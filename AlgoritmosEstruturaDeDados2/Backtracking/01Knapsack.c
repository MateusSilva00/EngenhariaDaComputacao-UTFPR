#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity Max
void printknapSack(int Max, int pesos[], int valores[], int size)
{
    int i, w;
    int K[size + 1][Max + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= size; i++)
    {
        for (w = 0; w <= Max; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (pesos[i - 1] <= w)
                K[i][w] = max(valores[i - 1] +
                                  K[i - 1][w - pesos[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int res = K[size][Max];
    printf("%d\n", res);

    w = Max;
    for (i = size; i > 0 && res > 0; i--)
    {

        // either the result comes from the top
        // (K[i-1][w]) or from (valores[i-1] + K[i-1]
        // [w-pesos[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else
        {

            // This item is included.
            printf("%d ", pesos[i - 1]);

            // Since this weight is included its
            // value is deducted
            res = res - valores[i - 1];
            w = w - pesos[i - 1];
        }
    }
}

// Driver code
int main()
{
    int valores[] = {60, 100, 120};
    int pesos[] = {10, 20, 30};
    int Max = 50;
    int size = sizeof(valores) / sizeof(valores[0]);

    printknapSack(Max, pesos, valores, size);

    return 0;
}