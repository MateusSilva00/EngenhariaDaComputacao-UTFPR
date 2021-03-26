#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int *arr, int size){
  printf("\n\n");
  for (int i=0; i < size; i++){
    printf("[%d] ", arr[i]);
  }
}

void swap(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

int partition(int *arr, int lower, int upper){


  int i = lower - 1, j;
  int pivot = arr[upper];
  printf("\n\nPivo: %d", pivot);
  for(j = lower; j < upper; j++){
      if(arr[j] <= pivot){
        i++;
        if(i != j){
          swap(&arr[i], &arr[j]);
          display(arr, 10);
        }
      }
  }
  swap(&arr[i+1], &arr[upper]);
  display(arr,10);

  return(i+1); // Retorna a posição onde se encontra o pivô
}

void quickSort(int *arr, int lower, int upper){
  if(upper > lower){
    //Var para receber a posição do pivo
    int partitionIndex = partition(arr, lower, upper);
    quickSort(arr, lower, partitionIndex-1); // Organiza os números a esquerda do pivo
    quickSort(arr, partitionIndex+1, upper); // Organiza os números a direita do pivo
  }
}

int main(){

  srand(time(0));

  int size=10, arr[size], i;

  printf("=== ORIGINAL VECTOR ===\n\n");
  for(i=0; i < size; i++){
    arr[i] = rand() % 100 + 1;
    printf("[%d] ", arr[i]);
  }

  quickSort(arr, 0, size-1);
  printf("\n\n=== SORTED NUMBERS ===");
  display(arr, size);

  return 0;
}
