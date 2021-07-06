#include <stdio.h>

int main (){
  int num, altA=0, impar = 0, div10=0, btwdezcem=0, num30=0, diff102030 = 0;

  do {
    printf("Insira um número.: ");
    scanf("%d", &num);

    if ((num < 10 || num > 100) && num != 0){
      altA++;
    }

    if(num % 2 != 0 && num != 0){
      impar++;
    }

    if(num % 10 == 0 && num !=0){
      div10++;
    }

    if(num >= 10 && num <= 100){
      btwdezcem++;
    }

    if (num == 30){
      num30++;
    }

    if (num != 10 && num != 20 && num != 30){
      diff102030++;
    }

  } while(num > 0);

  printf("\tResultados Obtidos\n");
  printf("\tMaior que cem ou Menor que dez.: %d \n", altA);
  printf("\tNúmeros ímpares.: %d \n", impar);
  printf("\tDivisíveis por 10.: %d \n", div10);
  printf("\tEntre 10 e 100.: %d \n", btwdezcem);
  printf("\tÉ o numero 30.: %d \n", num30);
  printf("\tDiferente de 10, 20 ou 30.: %d \n", diff102030);

  return 0;
}
