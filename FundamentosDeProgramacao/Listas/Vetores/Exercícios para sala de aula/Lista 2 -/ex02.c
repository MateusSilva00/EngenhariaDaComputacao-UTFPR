// Gerar um vetor A de inteiros com 8 elementos aleatórios entre 1 e 10. Construir um vetor B de mesma
// dimensão com os elementos de A multiplicados por 2.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void mostrarVetorInteirosDuplicado(int vetor[], int tamanho){
  int i;

  for(i=0; i<tamanho; i++){
    printf("%d ", vetor[i]*2);
  }
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos = 8, limite = 10, vetor[elementos];
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
