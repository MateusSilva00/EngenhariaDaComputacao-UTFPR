#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){

  setlocale(LC_ALL,"Portuguese");
  float num;
  char ch;
  do {
    do {
      printf("Informe um número da faixa de 1 a 50.: ");
      scanf("%f", &num);
      if (num < 1 || num > 50){
        printf("Número inválido!Deve estar na faixa de 1 a 50!\n");
      }
      else{
        while (num <= 250) {
          num = num * 2;
          if(num >= 250){
            break;
          }
          printf("N * 2 = %.2f\n", num);
        }
        printf("\nDeseja continuar o programa <S ou N> ?");
        scanf(" %c", &ch);
        ch = toupper(ch);
        if (ch == 'S') printf("\n\n");
      }
    } while(num < 1 || num > 50);
  } while(ch == 'S');

  return 0;
}
