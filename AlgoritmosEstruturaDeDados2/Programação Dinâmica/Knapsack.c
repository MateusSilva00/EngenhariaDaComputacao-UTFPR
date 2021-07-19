#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int KnapSack(int Capacidade, int Pesos[], int valores[], int n){
    int i, w;
    int K[n+1][Capacidade + 1];

    for(i = 0; i <=n; i++){
        for(w = 0; w <= Capacidade; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(Pesos[i - 1] <= w)
                K[i][w] = max(valores[i - 1] + K[i - 1][w - Pesos[i - 1]], K[i - 1][w]);
            else K[i][w] = K[i-1][w];
        }
    }

    return K[n][Capacidade];
}

int main(){

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", KnapSack(W, wt, val, n));

    return 0;
}