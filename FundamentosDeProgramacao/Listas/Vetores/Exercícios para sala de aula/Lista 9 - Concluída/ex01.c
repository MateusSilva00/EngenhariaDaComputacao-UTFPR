#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int procuraNumeroNaMatriz(int matriz[][5], int linhas, int numero);

int main(){

  srand(time(0));

  int matriz[5][5], i, j, num, retornoFuncao;
  char ch;

  do {
    printf("\n=== MATRIZ ===\n\n");
    for(i=0; i < 5; i++){
      for(j=0; j < 5; j++){
        matriz[i][j] = (rand() % 50 + 1);
        printf("%2d ", matriz[i][j]);
      }
      printf("\n");
    }

    printf("\nInforme um valor.: ");
    scanf("%d", &num);

    retornoFuncao = procuraNumeroNaMatriz(matriz, 5, num);
    if(retornoFuncao == 1){
      printf("%d Existe na matriz", num);
    }
    else printf("%d Não existe na matriz", num);

    printf("\nDeseja repetir o programa (S/N) ? ");
    __fpurge(stdin);
    scanf("%c", &ch);

  } while(toupper(ch) == 'S');


  return 0;
}

int procuraNumeroNaMatriz(int matriz[][5], int linhas, int numero){

  int i, j;

  for(i=0; i < linhas; i++){
    for(j=0; j < 5; j++){
      if(matriz[i][j] == numero){
        return 1;
        break;
      }
    }
  }
  return 0;
}
