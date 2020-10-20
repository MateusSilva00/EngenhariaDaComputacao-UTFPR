// Gerar um vetor A de inteiros com 7 elementos aleatórios entre 1 e 10. Construir um vetor B de mesmo
// tamanho, sendo que cada elemento de B deverá ser o elemento de A correspondente multiplicado por sua
// posição (ou índice), ou seja, B[i] = A[i] * i.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void mostrarVetorInteirosDuplicado(int vetor[], int tamanho){
  int i, resultado;

  for(i=0; i<tamanho; i++){
    resultado = vetor[i]*i;
    printf("%d ", resultado);
  }
}

int main(){

  int elementos = 7, limite = 10, vetor[elementos];
  char ch;

  do {
    gerarVetorInteiros(vetor, elementos, limite);
    printf("=== VETOR A ===\n");
    mostrarVetorInteiros(vetor, elementos);
    printf("\n=== VETOR B ===\n");
    mostrarVetorInteirosDuplicado(vetor, elementos);
    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
