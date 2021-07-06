// 4. (2,0) Implemente o Quicksort reverso, ou seja, ao final o vetor deve estar ordenado de
// maneira decrescente (e não crescente, como aprendemos em aula).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int *arr, int size){
  printf("\n");
  for(int i=0; i < size; i++){
    printf("[%d]  ", arr[i]);
  }
}

void swap(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

int partition(int *arr, int inicio, int fim){

  int i = inicio - 1, j;
  int pivot = arr[fim];
  printf("\nPivo: %d\n", pivot);
  for(j=inicio; j < fim; j++){
    if(arr[j] >= pivot){
      i++;
      if(i!=j){
        swap(&arr[i], &arr[j]);
        // display(arr, 10);
      }
    }
  }

  swap(&arr[i+1], &arr[j]);
  display(arr, 10);

  return(i+1);
}

void quicksort(int *arr, int inicio, int fim){
  if(fim > inicio){
    int indice = partition(arr, inicio, fim);
    quicksort(arr, inicio, indice-1);
    quicksort(arr, indice+1, fim);
  }
}

int main(){

  srand(time(0));

  int size = 10, arr[size], i;

  printf("=== VETOR ORIGINAL ===\n");
  for(i=0; i < size; i++){
    arr[i] = rand() % 100 + 1;
    printf("[%d]  ", arr[i]);
  }

  quicksort(arr, 0, size-1);
  printf("\n\n=== VETOR ORDENADO ===");
  display(arr, size);

  return 0;
}
