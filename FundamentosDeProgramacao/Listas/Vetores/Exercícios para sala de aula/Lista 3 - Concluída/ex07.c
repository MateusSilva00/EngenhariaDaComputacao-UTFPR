#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void GerarVetorPositivo(int vetor[], int vetorB[], int tamanho);

int main(){

  int vetor[100], vetorB[100];
  char ch;

  do {
    printf("=== VETOR A ===\n");
    GerarVetorPositivoNegativo(vetor, 100, -50, 50);
    MostrarVetorPositivoNegativo(vetor, 100);
    printf("\n\n===VETOR B === \n");
    GerarVetorPositivo(vetor, vetorB, 100);

    printf("\n\nDeseja continuar o program (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');


  return 0;
}

void GerarVetorPositivoNegativo(int vetor[], int tamanho, int limNegativo, int limPositivo){
   int i;
   for(i=0; i < tamanho; i++){
     vetor[i] = rand() % (limPositivo - limNegativo + 1) - limPositivo;
   }
 }

void MostrarVetorPositivoNegativo(int vetor[], int tamanho){
   int i;
   for(i = 0; i < tamanho; i++){
     printf("%d ", vetor[i]);
   }
 }

void GerarVetorPositivo(int vetor[], int vetorB[], int tamanho){
  int i, k=0;
  for(i=0; i<tamanho; i++){
    if(vetor[i] >= 0){
      vetorB[k] = vetor[i];
      k++;
    }
  }

  for(i=0; i < k; i++){
    printf("%d ", vetorB[i]);
  }

 }
