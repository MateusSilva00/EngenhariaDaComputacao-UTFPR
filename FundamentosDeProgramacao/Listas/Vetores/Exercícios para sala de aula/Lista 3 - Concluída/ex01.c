#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
#include "ordenacao_vetor.h"
#include <ctype.h>


int main(){
  srand(time(0));
  int tamanho=10, vetA[tamanho];
  char ch;

  do {
    printf("=== VETOR ORIGINAL ===\n");
    gerarVetorInteiros(vetA, tamanho, 10);
    mostrarVetorInteiros(vetA, tamanho);
    printf("\n=== VETOR ORDENADO ===\n");
    bubbleSort(vetA, tamanho);
    mostrarVetorInteiros(vetA, tamanho);

    printf("\n\nDeseja repetir o programa S ou N? ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
