#include <stdio.h>
#include <locale.h>
#include <ctype.h>

void matriz(int x, int y, char caracter){
  int i, j;
  printf("\n");
  for(i=1; i<=x; i++){
    for(j=1; j<=y; j++){
      printf(" %c ", caracter);
    }
    printf("\n");
  }
  printf("\n");
}


int main(){
  int linha, coluna;
  char caracter, ch;

  do {
    printf("Informe o numero de linhas.: ");
    scanf("%d", &linha);
    printf("Informe o numero de colunas.: ");
    scanf("%d", &coluna);
    printf("Informe o caracter.: ");
    scanf(" %c", &caracter);
    matriz(linha,coluna,caracter);
    printf("\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);


  } while(ch == 'S');

  return 0;
}
