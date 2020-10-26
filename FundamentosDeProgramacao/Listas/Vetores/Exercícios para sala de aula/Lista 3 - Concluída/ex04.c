#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void numMenorQue50(float vetor[], int tamanho);
void numMaiorQue50(float vetor[], int tamanho);

int main(){

  float vetA[10], vetB[50];
  char ch;

  do {
    printf("=== VETOR 1 ===\n");
    GerarVetorFloat0a1(vetA, 10);
    MostrarVetorFloat(vetA, 10);
    printf("\n\nSoma %.2f", SomarVetorFloat(vetA, 10));
    printf("\n\n=== VETOR 2 ===\n");
    GerarVetorFloat0a100(vetB, 50);
    MostrarVetorFloat(vetB, 50);
    printf("\n\n=== VETOR 3 ===\n");
    numMenorQue50(vetB, 50);
    printf("\n\n=== VETOR 4 ===\n");
    numMaiorQue50(vetB, 50);

    printf("\n\nDeseja continuar o program (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');


  return 0;
}

void GerarVetorFloat0a1(float vetor[], int tamanho){
  srand(time(0));
  int i;
  for(i=0; i<tamanho; i++){
    vetor[i] = ((float)rand() / RAND_MAX);
  }
}

void GerarVetorFloat0a100(float vetor[], int tamanho){
  srand(time(0));
  int i;
  for(i=0; i<tamanho; i++){
    vetor[i] = ((float)rand() / RAND_MAX)*100;
  }
}

void MostrarVetorFloat(float vetor[], int tamanho){
  int i;
  for(i=0; i<tamanho; i++){
    printf("%.1f ", vetor[i]);
  }
}

float SomarVetorFloat(float vetor[], int tamanho){
  int i;
  float soma = 0;
  for(int i=0; i<tamanho; i++){
    soma = soma + vetor[i];
  }
  return soma;
}

void numMenorQue50(float vetor[], int tamanho){
  int i;
  for(i = 0; i<tamanho; i++){
    if(vetor[i] < 50){
      printf("%.2f ", vetor[i]);
    }
  }
}

void numMaiorQue50(float vetor[], int tamanho){
  int i;
  for(i = 0; i<tamanho; i++){
    if(vetor[i] > 50){
      printf("%.2f ", vetor[i]);
    }
  }
}
