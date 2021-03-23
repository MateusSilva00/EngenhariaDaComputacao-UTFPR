#include <stdio.h>
#include <stdlib.h>

int interpolation_search(int *arr, int size, int value){

  int init = 0;
  int end = size - 1;
  while (init <= end) {
    /*Funciona de maneira análoga a interpolação de uma reta
    onde x' - x0 / x1 - x0 ou y' - y0/y' - 0
    */
    int half = init + ((end-init)*(value - arr[init])) / (arr[end] - arr[init]);

    printf("\nO indice do meio foi: %d", half);
    if(value < arr[half])
      end = half - 1;

    else if(value > arr[half])
      init = half + 1;

    else return half;
  }
  return -1;
}

int main(){

  int i, find, arr[10] = {4,10,16,21,22,30,34,37,45,54};

  for(i=0; i < 10; i++){
    printf("[%d]  ", arr[i]);
  }

  printf("\nQual valor deseja procurar: ");
  scanf("%d", &find);

  int ret_interpolation = interpolation_search(arr, 10, find);

  if(ret_interpolation != -1){
    printf("\nO valor se encontra no vetor na posição %d", ret_interpolation);
  }
  else printf("\nO valor não se encontra no vetor!");

  return 0;
}
