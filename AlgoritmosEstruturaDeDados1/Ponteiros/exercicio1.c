// 1) Implemente uma função que recebe 2 números “float” e retorna a multiplicação e a divisão entre eles.
// Trate possíveis erros. Imprima esses valores calculados fora do escopo da função (na main).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multDiv(float num1, float num2, float *divisao, float *multiplicacao){

  *multiplicacao = num1 * num2;
  if(num2 != 0){
    *divisao = num1 / num2;
  }

}

int main(){

  float num1 = 7.4, num2 = 57.63;
  float divisao, multiplicacao;

  multDiv(num1, num2, &divisao, &multiplicacao);

  printf("O resultado da multiplicacao é: %.2f\nO resultado da divisão é: %.2f\n", multiplicacao, divisao);

  return 0;
}
