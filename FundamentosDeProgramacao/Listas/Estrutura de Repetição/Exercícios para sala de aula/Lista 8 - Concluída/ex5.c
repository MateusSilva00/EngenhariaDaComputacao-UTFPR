#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num, i, j, countdiv=0, maiordiv=0;
  char ch;
  do {
    do {
      printf("Informe um número entre 2 e 100.: ");
      scanf("%d", &num);
      if(num < 2 || num > 100){
        printf("Número inválido!\n");
      }
      else{
        for(i=num; i<=num+10; i++){
          printf("%d ==>", i);
          for(j=1; j<=i; j++){
            if(i % j == 0){
              printf(" %d,", j);
              countdiv++;
            }
          }

          if(maiordiv == 0){
            maiordiv = countdiv;
          }
          if(countdiv > maiordiv){
            maiordiv = countdiv;
          }
          printf(" %d divisores\n", countdiv);
          countdiv=0;
        }
      }
    } while(num < 2 || num > 100);

    printf("A maior quantidade de divisores é.: %d", maiordiv);
    printf("\nDeseja continuar o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      countdiv=0, maiordiv=0; printf("\n");
    }
  } while(ch == 'S');

  return 0;
}
