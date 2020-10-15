#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){

  setlocale(LC_ALL,"Portuguese");
  int qtprimos, i, num=1, count=0, verifprimo=0;
  char ch;
  do {
    do {
      printf("Informe a quantida de números primos que deverão ser mostrados.: ");
      scanf("%d", &qtprimos);

      if(qtprimos <= 0){
        printf("Insira um número positivo!\n");
      }

      else if(qtprimos > 0){
        do {
          for (i=1; i<=num; i++) {
            if(num % i == 0){
              verifprimo++;
            }
          }
          if (verifprimo == 2){
            printf("%d ", num);
            count++;
          }
          verifprimo=0;
          num++;

        } while(count <= qtprimos);
      }

    } while (qtprimos<=0);
    printf("\nSe deseja continuar digite 'S'.: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if (ch == 'S'){
      num=1, count=0;
    }
    else printf("\t\tGoodbye <3");

  } while(ch == 'S');


  return 0;
}
