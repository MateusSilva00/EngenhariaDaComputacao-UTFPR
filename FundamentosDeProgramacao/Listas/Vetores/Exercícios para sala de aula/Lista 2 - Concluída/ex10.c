#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void menorValor(int vetor[], int tamanho);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos=80, vet[elementos];
  char ch;
    do {

      gerarVetorInteiroComLimite(vet,elementos,0,100);
      printf("=== VETOR A ===\n");
      mostrarVetorInteiros(vet, elementos);
      menorValor(vet, elementos);


      printf("\n\nDeseja continuar o programa (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}

void menorValor(int vetor[], int tamanho){
  int i, menor=vetor[0], posicao;
  for(i=0; i<tamanho; i++){
    if(vetor[i] < menor){
      menor = vetor[i];
      posicao = i;
    }
  }
  printf("\n\nO menor valor é %d e está na posição %d", menor,posicao);
}
