// 2) Implemente uma função recursiva que recebe um vetor com 10 diferentes números e retorna o maior e o menor dentre
// estes números. Imprima esses valores fora do escopo da função (na main).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compare(int array[], int i, int size, int *maior, int *menor){
  if(i == 0){
    *maior = array[i];
    *menor = array[i];
  }

  if(i < size){
    if(array[i] > *maior) *maior = array[i];
    if(array[i] < *menor) *menor = array[i];
    compare(array, i+1, 10, maior, menor);
  }
}

int main(){

  srand(time(0));

  int vetorInteiros[10], i=0;
  int maior, menor;

  for(; i < 10; i++){
    vetorInteiros[i] = rand() % 1000 + 1;
    printf("%d ", vetorInteiros[i]);
  }

  compare(vetorInteiros, 0, 10, &maior, &menor);
  printf("\nMaior valor: %d\nMenor valor: %d", maior, menor);

  return 0;
}
