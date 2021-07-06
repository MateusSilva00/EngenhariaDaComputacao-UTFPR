#include <stdio.h>

int main (){

  int num, soma=0;
  do {
    printf("Informe um numero positivo.: ");
    scanf("%d", &num);
    soma = soma + num;
  } while(num > 0);

  printf("Soma dos numeros positivos.: %d", soma);

  return 0;
}
