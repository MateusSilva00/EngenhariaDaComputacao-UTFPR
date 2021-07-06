#include <stdio.h>

int main(){
  int qtpessoas, i;
  float preco = 15, vltotal;
  printf("Informe a quantidade pessoas.: ");
  scanf("%d", &qtpessoas);
  printf("Valor do ingresso\tValor total recebido\n");
  for (i = 1; i <= 11; i++){
    vltotal = preco * qtpessoas;
    printf("R$%.2f\t\t\tR$%.2f\n", preco, vltotal);
    preco = preco + 0.50;
  }


  return 0;
}
