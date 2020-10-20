#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#include "vetores.h"

int main(){
  setlocale(LC_ALL,"Portuguese");

  srand(time(0));
  int tamVet, limiteVet;
  char ch;
  do {
    printf("Informe o tamanho do vetor.: ");
    scanf("%d", &tamVet);
    printf("Informe o valor de n.: ");
    scanf("%d", &limiteVet);

    printf("\n=== VETOR GERADO ===\n");
    gerarNumRandom(tamVet, limiteVet);


    printf("\n\nDeseja continuar no programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}
