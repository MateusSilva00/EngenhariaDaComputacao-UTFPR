#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"


int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos=50, a[elementos], soma;
  float media;
  char ch;
    do {
      gerarVetorInteiros(a, elementos, 100);
      printf("=== VETOR A ===\n");
      mostrarVetorInteiros(a, elementos);
      soma = somarVetorInteiro(a, elementos);
      printf("\nSoma dos valores do vetor.: %d", soma);
      media = soma / elementos;
      printf("\nMedia dos valores do vetor.: %.2f", media);

      printf("\n\nDeseja continuar o programa (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}
