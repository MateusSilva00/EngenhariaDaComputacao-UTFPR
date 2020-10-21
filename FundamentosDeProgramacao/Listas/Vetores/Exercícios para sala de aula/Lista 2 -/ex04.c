// Gerar um vetor A de inteiros com 10 elementos aleatórios entre 1 e 10 e construir um vetor B de mesma
// dimensão com os mesmos elementos de A, mas em ordem invertida, ou seja, o primeiro elemento de A será o
// último de B, o segundo elemento de A será o penúltimo de B e assim sucessivamente.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void mostrarVetorInteirosInvertido(int vetor[], int tamanho){
  int i;
  for(i=tamanho-1; i>0; i--){
    printf("%d    ",  vetor[i]);
  }
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos = 10, limite = 10, vetor[elementos];
  char ch;

  do {
    gerarVetorInteiros(vetor, elementos, limite);
    printf("=== VETOR A ===\n");
    mostrarVetorInteiros(vetor, elementos);
    printf("\n=== VETOR B ===\n");
    mostrarVetorInteirosInvertido(vetor, elementos);
    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
