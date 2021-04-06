#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search2(int *arr, int init, int end,int value){

  if(end >= init){

    int mid = init + (end - init) / 2;

    if(arr[mid] == value)
      return mid;

    if(arr[mid] > value)
      return binary_search2(arr, init, mid-1, value);

    //else
    return binary_search2(arr, mid+1, end, value);
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

  int ret_bin = binary_search2(arr, 0, 10, find);

  if(ret_bin != -1){
    printf("\nO valor se encontra no vetor na posição %d", ret_bin);
  }
  else printf("\nO valor não se encontra no vetor!");

  return 0;
}
