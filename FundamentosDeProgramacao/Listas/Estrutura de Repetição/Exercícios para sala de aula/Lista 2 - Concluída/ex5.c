#include <stdio.h>

int main (){
  int valor, maior=0;
  for (int j = 0; j < 4; j++){
    printf("Insira o valor.: ");
    scanf("%d", &valor);
    if (maior == 0){
      maior = valor;
    }
    else if (valor > maior){
      maior = valor;
    }
  }

  printf("O maior valor digitado foi.: %d", maior);

  return 0;
}
