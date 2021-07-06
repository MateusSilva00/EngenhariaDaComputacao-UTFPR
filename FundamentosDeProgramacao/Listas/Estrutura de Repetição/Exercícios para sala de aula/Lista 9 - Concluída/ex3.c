#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int limInf, limSup, i, j, countdiv=0, countlinha=0, countmedia=0;
  float media = 0;
  char ch;

  do {
    do {
      printf("Informe um valor para o limite inferior do intervalo.: ");
      scanf("%d", &limInf);
      if(limInf <= 0){
        printf("Informe um valor positivo!\n");
      }
      else{
        do {
          printf("Informe um valor para o limite superior do intervalo.: ");
          scanf("%d", &limSup);
          if(limSup <= limInf){
            printf("O valor limite superior deve maior do que o inferior!\n");
          }
          else{
            for(i = limInf; i<=limSup; i++){
              printf("\t%2.d = ", i);
              if (i < 6){
                printf("Nenhum ");
              }
              for(j=1; j <= i; j++){
                if(j % 2 == 0 && j % 3 == 0){
                  printf("%d ", j);
                }
              }
              printf("\n");
            }
          }
        } while(limSup <= limInf);
      }
    } while(limInf <= 0);
  } while(ch == 'S');

  return 0;
}
