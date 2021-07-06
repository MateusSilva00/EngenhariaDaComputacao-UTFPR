#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matrizes.h"

int main(){

  char ch;
  do {
    int matriz[10][10], i, j;
    GerarMatrizInteiro(10,10, matriz,1);
    printf("\n=== MATRIZ ORIGINAL=== \n");
    MostrarMatrizInteiro(10,10, matriz);

    for(i = 0; i < 10; i++){//linha
      for(j = 0; j < 10; j++){//coluna
        if(i == j){
          matriz[i][j] = 0;
        }
        if(i+j == 9){
          matriz[i][j] = 0;
        }
      }
    }
    printf("\n=== MATRIZ ATUAL === \n");
    MostrarMatrizInteiro(10,10, matriz);


    printf("\n\nDeseja repetir o programa (S/N) ?");
    // fflush(stdin);
    scanf(" %c", &ch);

  } while(toupper(ch) == 'S');



  return 0;
}
