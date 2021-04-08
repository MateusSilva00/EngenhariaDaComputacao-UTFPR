// Faça um função recursiva que permita calcular a média de um vetor de floats de Tamanho;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float mediaAritmetica(float arr[], int tam, int i, float media){
  if(i < tam){
    media = media + arr[i];
    mediaAritmetica(arr, tam, i+1, media);
  }

  else {
    printf("\nSoma %.2f\nDivisor %d\n", media, tam);
    media = media / tam;
    return media;
  }
}

int main(){
  srand(time(0));

  int tam=3, i;
  float arr[tam], media = 0, ret_media;

  printf("Vetor = ");
  for(i=0; i < tam; i++){
      scanf("%f", &arr[i]);
  }

  ret_media = mediaAritmetica(arr, tam, 0, media);
  printf("\nA média aritmética é %.2f", ret_media);

  return 0;
}
