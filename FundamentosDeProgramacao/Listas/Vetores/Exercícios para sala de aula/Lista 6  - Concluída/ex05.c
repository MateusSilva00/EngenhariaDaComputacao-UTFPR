#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matrizes.h"

int main(){

  char ch;
  do {
    int matriz[10][2], i, j, x, resultado, exponte, base, cont;
    GerarMatrizInteiro(10,2, matriz,6);
    printf("\n=== MATRIZ === \n");
    MostrarMatrizInteiro(10,2, matriz);

    printf("\nBASE \tEXPOENTE\t RESULTADO\n");

    for(i=0; i < 10; i++){
        cont = 0;
        resultado = 1;
        for(j=0; j < 2; j++){
          printf("%3d\t", matriz[i][j]);
          exponte = matriz[i][j];
          base = matriz[i][j-1];
      }
      while (cont < exponte) {
        resultado = resultado * base;
        cont++;
      }
      printf("\t%4d", resultado);

      printf("\n");
    }

    printf("\n\nDeseja repetir o programa (S/N) ?");
    // fflush(stdin);
    scanf(" %c", &ch);

  } while(toupper(ch) == 'S');



  return 0;
}
