#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int num, digit, divisor = 1, result, countdigit=0;
  char ch;

  do {
    do {
      printf("Digite um número.: ");
      scanf("%d", &num);
      if (num <= 0){
        printf("Numero Inválido! O número deve ser positivo\n");
      }
      else{
        do {
          printf("Digite um digito.: ");
          scanf("%d", &digit);
          if (digit <= 0){
            printf("Numero Inválido! O número deve ser positivo\n");
          }
          else{
            for(divisor; divisor <= num; divisor*=10){
              ///111
              result = (num%(divisor*10))/divisor;
              if(result == digit){
                countdigit++;
              }
            }
            if (countdigit > 0){
              printf("O numero %d tem %d digitos iguais a %d", num,countdigit, digit);
            }
            else printf("O numero %d não tem digitos iguais a %d", num, digit);
            printf("\nDeseja continuar o programa <S ou N>.: ");
            scanf(" %c", &ch);
            ch = toupper(ch);
            if(ch == 'S'){
              divisor = 1, countdigit=0; printf("\n");
            }
          }
        } while(digit <= 0);
      }

    } while(num <= 0);
  } while(ch == 'S');

  return 0;
}
