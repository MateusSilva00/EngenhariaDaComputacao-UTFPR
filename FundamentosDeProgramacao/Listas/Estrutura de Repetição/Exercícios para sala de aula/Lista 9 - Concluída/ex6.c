#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int limInf, limSup, j;
  char ch;

  do {
    do {
      printf("Informe um valor para o limite inferior do intervalo.: ");
      scanf("%d", &limInf);
      if(limInf <= 0){
        printf("O limite inferior deve ser maior que zero\n");
      }
      else{
        do {
          printf("Informe um valor para o limite superior do intervalo.: ");
          scanf("%d", &limSup);
          if(limSup <= limInf){
            printf("O limite superior deve ser maior do que o inferior!\n");
          }
          else{
            printf("=== VALORES PARES E DIVISIVEIS POR 5 EM ORDEM DECRESCENTE ===\n");
            for(j=limSup; j>=limInf; j--){
              if(j % 5 == 0 & j % 2 == 0){
                printf("%d ", j);
              }
            }
            printf("\nDeseja repetir o programa (S ou N).: ");
            scanf(" %c", &ch);
            ch = toupper(ch);
          }
        } while(limSup <= limInf);
      }
    } while(limInf <= 0);
  } while(ch == 'S');

  return 0;
}
