// Uma pessoa aplicou R$ 1000,00 com rendimento de 5% ao mês. Quantos meses serão necessários para
// que o capital investido ultrapasse R$ 1200,00.
#include <stdio.h>

int main (){

  int num, count=0;
  do {
    printf("Insira um número.: ");
    scanf("%d", &num);
    if(num <= 0){
      break;
    }
    else if (num % 2 == 0 && num % 5 == 0){
      count++;
    }

  } while(num > 0);

  printf("Quantidade numeros pares e diviseis por 5.: %d", count);

  return 0;
}
