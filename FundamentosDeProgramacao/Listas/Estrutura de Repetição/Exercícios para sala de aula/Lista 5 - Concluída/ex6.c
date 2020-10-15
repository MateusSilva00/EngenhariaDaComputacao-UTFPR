#include <stdio.h>

int main (){

  int num, qtDigito=1, divisor = 10, aux;
  do {
    printf("Informe um numero.: ");
    scanf("%d", &num);
    if(num < 0){
      printf("\nValor inválido!");
      break;
    }
    else{
      do {
        aux = num / divisor;
        if (aux > 0){
          qtDigito++;
          divisor = divisor * 10;
        }
        else {
          break;
        }
        aux = 0;

      } while(divisor != 0);
    }

  printf("O numero tem %d digito(s)!\n", qtDigito);
  qtDigito = 1;
  divisor = 10;

  } while(num >= 0);


  return 0;
}
