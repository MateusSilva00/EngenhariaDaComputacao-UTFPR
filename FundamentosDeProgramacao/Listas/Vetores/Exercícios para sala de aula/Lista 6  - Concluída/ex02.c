#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matrizes.h"

int main(){

  char ch;
  do {
    int matriz[5][5], i, j, somalinha[5] = {0,0,0,0,0}, somacoluna[5] = {0,0,0,0,0};
    GerarMatrizInteiro(5,5, matriz,5);
    printf("\n=== MATRIZ === \n");
    MostrarMatrizInteiro(5,5, matriz);

    for(i = 0; i < 5; i++){//linha
      for(j = 0; j < 5; j++){//coluna
        somacoluna[j] = somacoluna[j] + matriz[i][j];
        somalinha[i] = somalinha[i] + matriz[i][j];
      }
    }

    printf("\n\n=== SOMA DAS LINHAS ===\n");
    for(i = 0; i < 5; i++){
      printf("%d\t", somalinha[i]);
    }

    printf("\n\n=== SOMA DAS COLUNAS ===\n");
    for(i = 0; i < 5; i++){
      printf("%d\t", somacoluna[i]);
    }


    printf("\n\nDeseja repetir o programa (S/N) ?");
    // fflush(stdin);
    scanf(" %c", &ch);

  } while(toupper(ch) == 'S');

  return 0;
}
