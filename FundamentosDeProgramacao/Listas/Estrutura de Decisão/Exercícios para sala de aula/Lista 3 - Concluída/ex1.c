// O código a seguir tem o objetivo de obter o resto da divisão do número maior pelo menor
// informados (independentemente da ordem informada) e informar que não é possível realizar a
// divisão caso o divisor seja zero. Faça os ajustes necessários no código para que esses objetivos
// sejam alcançados.
#include <stdio.h>
int main(void){
  int  num1, num2, resto;
  printf("Informe o primeiro valor: ");
  scanf("%d", &num1);
  printf("Informe o segundo valor: ");
  scanf("%d", &num2);

  if (num1 == 0 || num2 == 0) {
    printf("\nNao é possivel realizar divisao por zero");
  }
  else if (num1 > num2){
    resto = num1 % num2;
    printf("O resto da divisao eh %d\n", resto);
  }
  else {
    resto = num2 % num1;
    printf("O resto da divisao eh %d\n", resto);
  }

  return 0;
}
