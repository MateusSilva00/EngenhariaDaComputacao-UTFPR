#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int comp(const void *elem1, const void *elem2){
    int f = *((int *)elem1);
    int s = *((int *)elem2);
    if (f > s)
        return 1;
    if (f < s)
        return -1;
    return 0;
}

int MaxSum(int a[][TAM], int n){
    for(int i = 0; i < n; i++)
        qsort(a[i], n, sizeof(int), comp);

    // Guarda o maior valor do último vetor
    int sum = a[n-1][TAM-1]; //12
    int prev = a[n-1][TAM-1]; //12


    int i, j;
    // Seleciona o maior elemento do último array
    for(i = n-2; i>=0; i--){
        for(j = TAM - 1; j>=0; j--){
            if(a[i][j] < prev){
                prev = a[i][j];
                sum += prev;
                break;
            }
        }
    if(j == -1)
        return 0;
    }
    return sum;
}


int main(){

    int arr[TAM][TAM] = {{1, 7, 3, 4},
                    {4, 2, 5, 1},
                    {15, 5, 3, 8},
                    {12, 4, 6, 8}};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = MaxSum(arr, size);
    printf("Sum of elements: %d \n", sum);
    
    return 0;
}
