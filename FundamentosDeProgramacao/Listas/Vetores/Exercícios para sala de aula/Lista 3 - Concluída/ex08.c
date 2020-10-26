#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

int maiorValorVetor(int vetor[], int tamanho){
  int i, maior = 0;
  for(i = 0; i < tamanho; i++){
    if(vetor[i] > maior){
      maior = vetor[i];
    }
  }
  return maior;
}

void VetorDivido(int vetor[], int tamanho, int divisor){
  int i;
  float vetorB[tamanho];
  for(i = 0; i < tamanho; i++){
    vetorB[i] = (float)vetor[i] / divisor;
    printf("%.2f ", vetorB[i]);
  }
}

int main(){

  int vetor[100], divisor;
  char ch;

  do {
    printf("=== VETOR A ===\n");
    gerarVetorInteiroComLimite(vetor, 100, 0, 11);
    mostrarVetorInteiros(vetor, 100);

    divisor = maiorValorVetor(vetor, 100);
    printf("\nMaior Valor.: %d", divisor);

    printf("\n=== VETOR B ===\n");
    VetorDivido(vetor, 100, divisor);

    printf("\n\nDeseja continuar o program (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');


  return 0;
}
