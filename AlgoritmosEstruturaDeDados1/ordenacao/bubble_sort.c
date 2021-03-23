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

void bubble_sort(int *arr, int size){

  int i, aux;
  int change = 1;

  while (change == 1) {
    change = 0;
    for(i=0; i < size - 1; i++){
      if(arr[i] > arr[i+1]){
        swap(&arr[i], &arr[i+1]);
        change = 1;
      }
    }
  }
}

int main(){

  srand(time(0));

  int size=10, arr[size], i;

  printf("=== ORIGINAL VECTOR ===\n\n");
  for(i=0; i < 10; i++){
    arr[i] = rand() % 100 + 1;
    printf("[%d]  ", arr[i]);
  }

  bubble_sort(arr, size);
  printf("\n\n=== SORTED NUMBERS ===");
  display(arr, size);

  return 0;
}
