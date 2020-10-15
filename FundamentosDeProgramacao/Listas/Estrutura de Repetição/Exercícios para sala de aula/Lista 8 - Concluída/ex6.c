#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num, i, j, soma=0;
  char ch;
  do {
    do {
      printf("Informe um número entre 10 e 20.: ");
      scanf("%d", &num);
      if(num < 2 || num > 100){
        printf("Número inválido!\n");
      }
      else{
        for(i=num; i<=num+6; i++){
          printf("%d ==>", i);
          for(j=1; j<=i; j++){
            if(j % 2 == 0){
              printf(" %d", j);
              soma = soma + j;
            }
          }
          printf(" <--- SOMA = %d\n", soma);
          soma=0;
        }
      }
    } while(num < 10 || num > 20);

    printf("\nDeseja continuar o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      soma = 0; printf("\n");
    }
  } while(ch == 'S');

  return 0;
}
