// Elabore um programa que permita ao usuário fornecer 30 números quaisquer e
// apresente:
// a) A soma dos 10 primeiros números.
// b) A soma do 11o número até o 20o número.
// c) A soma do 21o número até o 30o número.
// d) A soma de todos os números.
#include <stdio.h>

int main (){
    int i=1, num,sum10=0, sum20=0, sum30=0, sum_all;
    printf("Insira 30 números\n");
    for (i; i<=30; i++) {
      printf("\nNúmero %d: ", i);
      scanf("%d", &num);
      if (i <= 10){
        sum10 = num + sum10;
      }

      else if(i <= 20){
        sum20 = num + sum20;
      }

      else if(i <=30){
        sum30 = num + sum30;
      }
    }
    sum_all = sum10 + sum20 + sum30;
    printf("Soma dos 10 primeiros: %d\nSoma do 11o ao 22o número: %d\nSoma do 21o ao 30o número: %d\nSoma de todos os números: %d", sum10, sum20, sum30, sum_all);

  return 0;
}
