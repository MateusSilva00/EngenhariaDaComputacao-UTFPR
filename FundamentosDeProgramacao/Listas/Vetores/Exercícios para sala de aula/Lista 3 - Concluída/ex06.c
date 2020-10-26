#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

int mostrarQuantidades(char vetor[], int tamanho, int opcao);

int main(){
  srand(time(0));
  int pularlinha, vetorQuantidade[2];
  char ch, vetorAlfanumerico[200];

  do {

    printf("Quantos caracteres por linha deseja mostrar.: ");
    scanf("%d", &pularlinha);
    GerarVetorCharAlfanumerico(vetorAlfanumerico, 200);
    MostrarVetorCharAlfanumerico(vetorAlfanumerico, 200, pularlinha);

    printf("\nCaracteres alfabetico maiusculos.: %d", mostrarQuantidades(vetorAlfanumerico, 200, 0));
    printf("\nCaracteres alfabetico minusculos.: %d", mostrarQuantidades(vetorAlfanumerico, 200, 1));
    printf("\nCaracteres númericos.: %d", mostrarQuantidades(vetorAlfanumerico, 200, 2));

    printf("\n\nDeseja continuar o program (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');


  return 0;
}

void GerarVetorCharAlfanumerico(char vetor[], int tamanho){
  int i;
  for(i = 0; i<tamanho; i++){
    vetor[i] = rand() % 127 + 33;
  }
}

void MostrarVetorCharAlfanumerico(char vetor[], int tamanho, int n){
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

int mostrarQuantidades(char vetor[], int tamanho, int opcao){
  int i, vetorQuantidade[3] = {0,0,0};
  for(i = 0; i<tamanho; i++){
    //NÚMEROS
    if(vetor[i] >= 48 && vetor[i] <= 57){
      vetorQuantidade[2] = vetorQuantidade[2] + 1;
    }
    // LETRAS MAISCULAS
    else if(vetor[i] >= 65 && vetor[i] <= 90){
      vetorQuantidade[1] = vetorQuantidade[1] + 1;
    }
    // LETRAS MINUSCULAS
    else if(vetor[i] >= 97 && vetor[i] <= 122 ){
      vetorQuantidade[0] = vetorQuantidade[0] + 1;
    }
  }

  switch (opcao) {
    case 0:
      // LETRAS MINUSCULAS
      return vetorQuantidade[0];
      break;
    case 1:
      // LETRAS MAISCULAS
      return vetorQuantidade[1];
      break;
    case 2:
      //NÚMEROS
      return vetorQuantidade[2];
      break;
  }
}
