#include <stdio.h>

int main(){
  int sequencias;
  float i, resultado = 1;
  printf("Informe a quantidade de sequências.: ");
  scanf("%d", &sequencias);
  for (i = 1; i<=sequencias; i++){
    if ( i == 1 ){
      printf("Resultado <%.0f>: %.4f\n", i,resultado);
    }
    else{
    resultado = resultado + (1/i);
    printf("Resultado <%.0f>: %.4f\n", i,resultado);
    }
  }

  return 0;
}
