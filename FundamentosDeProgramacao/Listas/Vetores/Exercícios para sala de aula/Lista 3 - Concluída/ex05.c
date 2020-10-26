#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"


int main(){

  int pularlinha;
  char ch, vetorChar[100];

  do {
    printf("Quantos caracteres por linha deseja mostrar.: ");
    scanf("%d", &pularlinha);
    printf("\n\n=== VETOR DE MINUSCULAS ===\n");
    GerarVetorCharMinuscula(vetorChar, 100);
    MostrarVetorChar(vetorChar, 100, pularlinha);
    printf("\n\n=== VETOR DE MAISCULAS ===\n");
    GerarVetorCharMaiuscula(vetorChar, 200);
    MostrarVetorChar(vetorChar, 200, pularlinha);

    printf("\n\nDeseja continuar o program (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');


  return 0;
}

void GerarVetorCharMinuscula(char vetor[], int tamanho){
  int i;
  for(i = 0; i<tamanho; i++){
    vetor[i] = (rand() % 26) + 97;
  }
}

void GerarVetorCharMaiuscula(char vetor[], int tamanho){
  int i;
  for(i = 0; i<tamanho; i++){
    vetor[i] = (rand() % 26) + 65;
  }
}

void MostrarVetorChar(char vetor[], int tamanho, int n){
  int i, countlinha = 0;
  for(i = 0; i<tamanho; i++){
    countlinha++;
    printf("%c ", vetor[i]);
    if(countlinha == n){
      printf("\n");
      countlinha = 0;
    }
  }
}
