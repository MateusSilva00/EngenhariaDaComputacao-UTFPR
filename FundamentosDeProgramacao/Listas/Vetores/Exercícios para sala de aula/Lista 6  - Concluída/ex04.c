#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "matrizes.h"

int main(){

  char ch;
  do {
    int matriz[50][10], i, j, gabarito[10], notas[50];
    GerarMatrizInteiro(50, 10, matriz, 5);
    printf("\n=== RESPOSTAS DOS ALUNOS === \n");
    for(i=0; i < 50; i++){
      printf("Aluno %3d ==> ", i+1);
      for(j=0; j < 10; j++){
        printf("%2d ", matriz[i][j]);
      }
      printf("\n");
    }


    printf("\n\n=== Gabarito ===\n");
    for(i = 0; i < 10; i++){
      gabarito[i] = (rand() % 5) + 1;
      printf("%d\t", gabarito[i]);
    }

    for(i = 0; i < 50; i++){
      notas[i] = 0;
      for(j = 0; j < 10; j++){
        if(matriz[i][j] == gabarito[j]){
          notas[i] = notas[i] + 1;
        }
      }
    }

    printf("\n\n=== Pontuação Obtida ===\n");
    for(i = 0; i < 50; i++){
      printf("Aluno %3d ==> %d pontos\n", i+1, notas[i]);
    }



    printf("\n\nDeseja repetir o programa (S/N) ?");
    // fflush(stdin);
    scanf(" %c", &ch);

  } while(toupper(ch) == 'S');



  return 0;
}
