#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int *arr, int size, int value){

  for(int i=0; i < size; i++){
      if(arr[i] == value){
        return i;
      }
  }
  return -1;
}

int main(){

  srand(time(0));

  int size = 15, arr[size];
  int i, find;

  for(i=0; i < size; i++){
    arr[i] = rand() % 40 + 1;
    printf("[%d] ", arr[i]);
  }

  printf("\nQual número deseja buscar? ");
  scanf("%d", &find);

  int ret_search = linear_search(arr, size, find);

  if(ret_search != -1){
    printf("\nO valor se encontra na vetor na posição %d", ret_search);
  }
  else printf("\nO valor não se encontra no vetor");

  return 0;
}
