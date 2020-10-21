// Gerar um vetor de inteiros com 15 elementos aleatórios entre 1 e 25. Gerar outros dois vetores, um
// contendo os valores pares e outro os ímpares. Mostrar os três vetores.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void vetoresPares(int vetor[], int tamanho);
void vetoresImpares(int vetor[], int tamanho);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos = 15, limite = 25, vet[elementos];
  char ch;
  do {
    printf("=== VETOR COMPLETO === \n");
    gerarVetorInteiros(vet, elementos, limite);
    mostrarVetorInteiros(vet, elementos);
    printf("\n=== VETOR DE PARES ===\n");
    vetoresPares(vet, elementos);
    printf("\n=== VETORES IMPARES ===\n");
    vetoresImpares(vet, elementos);
    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}

void vetoresPares(int vetor[], int tamanho){
  int i;

  for(i=0; i<tamanho; i++){
    if(vetor[i] % 2 == 0){
      printf("%d ", vetor[i]);
    }
  }
}

void vetoresImpares(int vetor[], int tamanho){
  int i;

  for(i=0; i<tamanho; i++){
    if(vetor[i] % 2 != 0){
      printf("%d ", vetor[i]);
    }
  }
}
