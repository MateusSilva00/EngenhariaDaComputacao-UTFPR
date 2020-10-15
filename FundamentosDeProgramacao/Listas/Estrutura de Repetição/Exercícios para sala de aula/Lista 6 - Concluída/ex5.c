#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int i, j, num;
  char ch;
  do {
    do {
      printf("Informe um numero positivo.: ");
      scanf("%d", &num);
      if(num <= 0){
        printf("Insira um número positivo!\n");
      }
      else{
        for(i=1; i<=num; i++){
          for(j=1; j<=num; j++){
            printf(" %d ", i);
          }
          printf("\n");
        }
        printf("Deseja continuar? Digite 'S' para Sim.: ");
        fflush(stdin);
        scanf(" %c", &ch);
        ch = toupper(ch);
        if (ch != 'S') {
          printf("\n\t\tGoodbye <3");
        }
      }
  } while(ch == 'S');

  } while(num <=0);
}
