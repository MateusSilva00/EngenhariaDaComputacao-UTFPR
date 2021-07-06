// Implemente uma função recursiva que retorna a média aritmética ponderada dos elementos inteiros de um vetor de tamanho
// variável tam. Para o cálculo da média ponderada, o peso de cada elemento é igual a seu índice no vetor + 1.
// Exemplo: Vetor = [5,6,3,2]  Média Ponderada = (5x1 + 6x2 + 3x3 + 4x4) / (1+2+3+4) = 4,2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float mediaAritmetica(int arr[], int tam, int i, float media){
  if(i < tam){
    media = media + (arr[i] * (i+1));
    mediaAritmetica(arr, tam, i+1, media);
  }

  else {
    int divisor = ((1 + tam)*tam)/2;
    printf("\nSoma %.2f\nDivisor %d\n", media, divisor);
    media = media / divisor;
    return media;
  }
}

int main(){
  srand(time(0));

  int tam=100, arr[tam], i;
  float media = 0, ret_media;

  printf("Vetor = ");
  for(i=0; i < tam; i++){
      arr[i] = rand() % 10 + 1;
      printf("%d ", arr[i]);
  }

  ret_media = mediaAritmetica(arr, tam, 0, media);
  printf("\nA média aritmética é %.2f", ret_media);

  return 0;
}
