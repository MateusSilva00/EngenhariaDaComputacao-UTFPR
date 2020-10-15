#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int  main(){

  setlocale(LC_ALL,"Portuguese");
  int num, nlinha, count=1, result=1, aux = 0;
  char ch;
  do {
    do {
      printf("Informe a quantida de números divisíveis por 5.: ");
      scanf("%d", &num);
      if(num <= 0){
        printf("\nInsira um numero positivo e maior que zero!\n");
      }
      else{
        do {
          printf("Insira a quantidade de repetição por linha.: ");
          scanf("%d", &nlinha);
          if (nlinha <=0){
            printf("Insira um número positivo!\n");
          }
          else{
            while (count <= num) {
              result = 5 * count;
              count++, aux++;
              printf("%d ", result);
              if(aux == nlinha){
                printf("\n");
                aux = 0;
              }
            }
          }
        } while(nlinha <=0);
      }
      printf("\nDeseja continuar? Digite 'S' para continuar.: ");
      scanf(" %c",&ch);
      fflush(stdin);
      ch = toupper(ch);
      if(ch == 'S'){
        count=1, result=1, aux = 0;
      }
      else printf("\t\tGoodbye <3");
    } while(num<=0);
  } while(ch == 'S');

  return 0;
}
