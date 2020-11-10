#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matrizes.h"

int main(){

  char ch;
  do {
    int matriz[3][3], i, j, soma = 0, diagonalPrincipal = 0, diagonalSecundaria=0;
    GerarMatrizInteiro(3,3, matriz,10);
    printf("\n=== MATRIZ === \n");
    MostrarMatrizInteiro(3,3, matriz);

    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
        soma = soma + matriz[i][j];
        if(i == j){
          diagonalPrincipal = diagonalPrincipal + matriz[i][j];
        }
        if(i+j == 2){
          diagonalSecundaria = diagonalSecundaria + matriz[i][j];
        }
      }
    }

    printf("\nSoma dos elementos da matriz: %d\n", soma);
    printf("Soma dos elementos da diagonal principal: %d\n", diagonalPrincipal);
    printf("Soma dos elementos da diagonal secundaria: %d\n", diagonalSecundaria);

    printf("\n\nDeseja repetir o programa (S/N) ?");
    // fflush(stdin);
    scanf(" %c", &ch);

  } while(toupper(ch) == 'S');

  return 0;
}
