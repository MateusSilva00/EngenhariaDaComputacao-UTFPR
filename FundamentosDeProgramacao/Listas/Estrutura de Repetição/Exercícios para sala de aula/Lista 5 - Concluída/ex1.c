// Ler um número maior ou igual a 0 que representa a quantidade de valores pares que devem ser
// mostrados. Apresentar esses valores n por linha, sendo n um número positivo, informado pelo
// usuário. Os valores são apresentados separados por tabulação.
#include <stdio.h>

int main (){

  int i, qtpares, par, qtlinha, count = 0;
  do {
    printf("Quantida de valores pares.: ");
    scanf("%d", &qtpares);
    printf("Quantidade por linha.:");
    scanf("%d", &qtlinha);
    if (qtpares < 0){
      printf("Valor inválido. Digite novamente\n");
    }
    else {
      for (i=1; i<=qtpares; i++){
        par = i * 2;
        printf("\t%d ", par);
        count++;
        if (count == qtlinha){
          count=0;
          printf("\n");
        }
      }

    }

  } while(qtpares < 0);

  return 0;
}
