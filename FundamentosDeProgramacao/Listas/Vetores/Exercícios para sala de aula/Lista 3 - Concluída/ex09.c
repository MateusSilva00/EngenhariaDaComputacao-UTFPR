#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void qtLocacaoGratis(int vetor[], int tamanho){
  int i, vetorB[tamanho];
  for(i = 0; i < tamanho; i++){
    vetorB[i] = vetor[i] / 10;
    printf("%d ", vetorB[i]);
  }
}


int main(){

  int vetor[300], divisor;
  char ch;

  do {
    printf("=== VETOR A ===\n");
    gerarVetorInteiroComLimite(vetor, 300, 0, 101);
    mostrarVetorInteiros(vetor, 300);
    printf("\n\nVETOR B ===\n");
    qtLocacaoGratis(vetor, 300);


    printf("\n\nDeseja continuar o program (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');


  return 0;
}
