#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int *arr, int size){
  printf("\n\n");
  for(int i = 0; i < size; i++){
    printf("[%d]  ", arr[i]);
  }
}

void swap(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

void selection(int *arr, int size){

  int i, key, j;
  for(i=0; i < size - 1; i++){
    key = i;
    for(j=i+1; j < size; j++){
      if(arr[j] < arr[key]) key = j;
    }

    if(key != i) swap(&arr[key], &arr[i]);

  }
}

int main(){

  srand(time(0));

  int size=10, arr[size], i;

  printf("=== ORIGINAL VECTOR ===\n\n");
  for(i=0; i < size; i++){
    arr[i] = rand() % 100 + 1;
    printf("[%d]  ", arr[i]);
  }

  selection(arr, size);
  printf("\n\n=== SORTED NUMBERS ===");
  display(arr,size);

  return 0;
}
