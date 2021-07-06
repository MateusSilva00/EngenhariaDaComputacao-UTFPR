#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  // 4562 2654
  int a, div_milhar, div_centena, div_dezena, div_unidade, numero_invertido;
  printf("Insira um número.: ");
  scanf("%d", &a);
  div_milhar = a / 1000;
  div_centena = (a/100)%10;
  div_dezena = (a/10)%10;
  div_unidade = ((a%1000)%100)%10;
  numero_invertido = (div_unidade*1000) + (div_dezena*100) + (div_centena*10) + div_milhar;
  printf("\nNúmero Invertido = %d", numero_invertido );
  if (a == numero_invertido){
    printf("\nEsse número é um palíndromo");
  }
  else{
    printf("\nEsse número não é um palíndromo");
  }

  return 0;
}
