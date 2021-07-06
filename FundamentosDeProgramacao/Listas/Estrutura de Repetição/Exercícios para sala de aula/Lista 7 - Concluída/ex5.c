#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){

  setlocale(LC_ALL,"Portuguese");
  int i,j,limSup, countprimo=0;
  char ch;

  do {
    do {
      printf("Informe um valor para o limite superior do intervalo.: ");
      scanf("%d", &limSup);
      if (limSup <= 2){
        printf("O limite superior deve ser maior que 2!\n");
      }
      else{
          for(i=2; i<=limSup; i++){
            for(j=1; j<=i; j++){
              if(i % j == 0){
                countprimo++;
              }
            }
            if(countprimo == 2){
              printf("%2.d   ", i);
            }
            countprimo=0;
          }
          printf("\nDeseja repetir o programa <S ou N>.: ");
          scanf(" %c", &ch);
          ch = toupper(ch);
          if (ch == 'S'){
            countprimo=0; printf("\n");
          }
        }
      } while(limSup <= 2);
    } while(ch == 'S');

  return 0;
}
