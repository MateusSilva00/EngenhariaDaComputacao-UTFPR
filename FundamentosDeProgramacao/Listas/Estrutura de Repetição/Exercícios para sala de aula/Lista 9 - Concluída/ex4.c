#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int qtnum, i=1, firstDiv, secondDiv, count=0;
  char ch;

  do {
    printf("Quantos valores deseja mostrar.: ");
    scanf("%d", &qtnum);
    do {
      printf("Informe o valor do primeiro divisor (condição x).: ");
      scanf("%d", &firstDiv);
      if(firstDiv <= 0){
          printf("Informe um valor positivo!\n");
      }
      else{
        do {
          printf("Informe o valor do segundo divisor (condição y).: ");
          scanf("%d", &secondDiv);
          if(secondDiv <= 0){
            printf("Informe um valor positivo!\n");
          }
          else{
            do {
              if(i % firstDiv == 0 && i % secondDiv == 0){
                count++;
                printf("%d ", i);
              }
              i++;
            } while(count < qtnum);
            printf("\n\nDeseja repetir o programa (S ou N)? ");
            scanf(" %c", &ch);
            ch = toupper(ch);
            if(ch == 'S'){
              i=1; count=0; printf("\n\n");
            }
          }
        } while(secondDiv <= 0);
      }
    } while(firstDiv <= 0);
  } while(ch == 'S');


  return 0;
}
