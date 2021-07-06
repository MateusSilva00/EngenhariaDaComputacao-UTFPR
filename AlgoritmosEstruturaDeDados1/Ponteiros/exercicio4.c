// 4 - Implemente o exercício 3 de forma recursiva.
// 3) Implemente uma função que recebe um vetor de inteiros V e um número inteiro N e calcula o menor e o maior índice
// que N ocorre em V. Exemplo: V={0,1,3,4,1,7,2} e N = 1, o resultado será menor = 1 e maior = 5.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compare(int array[], int size, int N, int i, int *maior, int *menor){

  if(i == size){
    printf("\n");
  }
  else{
    if(N == array[i]){
      if(*menor == -1){
        *menor = i;
        *maior = i;
      }
      if(*maior <= i){
        *maior = i;
      }
    }
    compare(array, size, N, i+1, maior, menor);
  }
}


int main(){

  srand(time(0));

  int vetorInteiros[10], i=0;
  int maior, menor = -1, n;

  for(; i < 10; i++){
    vetorInteiros[i] = rand() % 5 + 1;
    printf("%d  ", vetorInteiros[i]);
  }

  n = rand() % 5 + 1; //gerando número de comparação aleatoriamente
  printf("\nValor a procurar: %d", n);

  compare(vetorInteiros, 10, n , 0, &maior, &menor);
  printf("\nMenor indice: %d\nMaior indice: %d", menor, maior);

  return 0;
}
