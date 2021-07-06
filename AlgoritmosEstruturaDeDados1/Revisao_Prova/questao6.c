// Joãozinho está tentando implementar o Selection Sort para vetores de inteiros, mas seu código abaixo não está funcionando
// muito bem. Faças as devidas correções
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

void selection_sort(int num[], int tam){

  int i, j, min, aux;
  for(i=0; i < (tam-1); i++){
    min = i;
    for(j=(i+1); j < tam; j++){
      if(num[j] < num[min]){
        min = j;
      }
    }
    if(i != min){
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
}

int main(){

  srand(time(0));
  int size=10, arr[size], i;
  printf("=== VETOR ORIGINAL ===\n");
  for(i=0; i < size; i++){
    arr[i] = rand() % 50 + 1;
    printf("[%d] ", arr[i]);
  }

  printf("\n=== VETOR ORDENADO ===\n");
  selection_sort(arr, size);
  for(i=0; i < size; i++){
    printf("[%d] ", arr[i]);
  }

  return 0;
}
