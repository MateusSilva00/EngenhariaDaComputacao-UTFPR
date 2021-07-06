// 5.    Implemente uma função recursiva que imprima o número de 0s e 1s dado um vetor de inteiros. Assuma que este
// vetor possui apenas 0s e 1s.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zeroOuUm (int tam, int i);

int main(){

  srand(time(0));

  zeroOuUm(10, 0);

  return 0;
}

void zeroOuUm(int tam, int i){
  if(i < tam){
    printf("%d   ", rand() % 2);
    zeroOuUm(tam, i+1);
  }
}
