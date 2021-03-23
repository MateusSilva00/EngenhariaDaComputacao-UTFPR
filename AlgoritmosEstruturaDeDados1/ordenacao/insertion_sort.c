#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int *arr, int size){
  printf("\n\n");
  for(int i = 0; i < size; i++){
    printf("[%d]  ", arr[i]);
  }
}

void insertion_sort(int *arr, int size){

  int i, key, j;

  for(i=1; i < size; i++){
    j = i -1;
    key = arr[i];
    while(j>=0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
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

  insertion_sort(arr, size);
  printf("\n\n=== SORTED NUMBERS ===");
  display(arr,size);

  return 0;
}
