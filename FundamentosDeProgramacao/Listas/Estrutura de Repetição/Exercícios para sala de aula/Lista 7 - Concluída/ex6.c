#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){

  int i=1, qtnum, count=0;
  char ch;

  do {
    do {
      printf("Quantos números pares divisíveis por 3 quer mostrar? ");
      scanf("%d", &qtnum);
      if(qtnum == 0){
        printf("Insira um número diferente de zero!\n");
      }
      else{
          if(qtnum < 0){
            qtnum = qtnum * -1;
          }
          do {
            if(count % 2 == 0 && count % 3 == 0){
              printf("%d ", count);
              i++;
            }
            count++;
          } while(i<=qtnum);
          printf("\n\nDeseja repetir o programa <S ou N>? ");
          scanf(" %c", &ch);
          ch = toupper(ch);
          if(ch == 'S'){
            i=1; count=0; printf("\n");
          }
        }
    } while(qtnum == 0);
  } while(ch == 'S');

  return 0;
}
