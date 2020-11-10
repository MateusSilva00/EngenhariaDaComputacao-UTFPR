#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matrizes.h"

int main(){

  char ch;
  do {
    int matriz[3][3], i, j, maior = 0, linha, coluna;
    GerarMatrizInteiro(3,3, matriz,100);
    printf("\n=== MATRIZ ORIGINAL=== \n");
    MostrarMatrizInteiro(3,3, matriz);

    for(i = 0; i < 3; i++){//linha
      for(j = 0; j < 3; j++){//coluna
        if(i == 0 && j == 0){
          maior = matriz[i][j];
        }
        else if(matriz[i][j] > maior){
          maior = matriz[i][j];
          linha = i+1;
          coluna = j+1;
        }
      }
    }

    printf("O maior elemento da matriz é %d e se encontra na coluna %d da linha %d", maior, coluna, linha);


    printf("\n\nDeseja repetir o programa (S/N) ?");
    // fflush(stdin);
    scanf(" %c", &ch);

  } while(toupper(ch) == 'S');



  return 0;
}
