// Elaborar um programa que determine a potência de um número. O usuário informa a base e o
// expoente e o programa informa o resultado da base elevada ao expoente. Não usar funções
// prontas do C para fazer o cálculo da potência.
#include <stdio.h>

int main (){

  int i, base, expoente, resultado=1;
  printf("Informe o valor da base.: ");
  scanf("%d", &base);
  printf("Informe o valor do expoente.: ");
  scanf("%d", &expoente);

  for (i=1; i<=expoente; i++){
      printf("%d * ",base);
      resultado = resultado * base;
  }
  printf(" = %d", resultado);

  return 0;
}
