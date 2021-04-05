// Implemente uma função recursiva que calcula o valor máximo de um vetor de inteiros.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maiorNum(int num[], int tam, int i, int maior){
  if(i == 0) maior = num[i];

  if(i < tam){
    if(num[i] > maior){
      maior = num[i];
    }
    maiorNum(num, tam, i+1, maior);
  }

  else return maior;
}

int main(){

  srand(time(0));

  int vetInteiros[15], i=0;

  for(; i < 15; i++){
    vetInteiros[i] = rand() % 1000 + 1;
    printf("%d  ", vetInteiros[i]);
  }

  printf("\n\nO maior número do vetor é %d", maiorNum(vetInteiros, 15, 0, 0));

}
