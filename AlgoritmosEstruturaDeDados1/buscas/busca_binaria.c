#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int *arr, int size, int value){

  int init = 0;
  int end = size - 1;

  while (init <= end) {
    int half = (init + end) / 2;

    if(arr[half] == value)
      return half;

    if(arr[half] < value){
      init = half + 1;
    }

    if(arr[half] > value){
      end = half-1;
    }
  }
  return -1;
}

int main(){

  int i, find, arr[10] = {4,10,27,38,74,79,84,103,241,270};

  for(i=0; i < 10; i++){
    printf("[%d]  ", arr[i]);
  }

  printf("\nQual valor deseja procurar: ");
  scanf("%d", &find);

  int ret_bin = binary_search(arr, 10, find);

  if(ret_bin != -1){
    printf("\nO valor se encontra no vetor na posição %d", ret_bin);
  }
  else printf("\nO valor não se encontra no vetor!");

  return 0;
}
