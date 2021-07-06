#include <stdio.h>
#include <math.h>
int main (){

  int num, qtDigito=1, divisor = 10, aux, soma=0, divisorDois;
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

      printf("\nNumero:%d\nQuantidade de digitos %d",num, qtDigito);
      // 2 digitos
      do {
        //18
        qtDigito--;
        divisorDois = pow(10, qtDigito); //10
        soma = soma + (num / divisorDois); // 18 / 10 = 1
        num = num % divisorDois; // 18 % 10 = 8

      } while(qtDigito > 0);

      printf("\nA soma dos numeros digitados e.: %d\n\n", soma);
      qtDigito=1; divisor=10; soma = 0;
    }

  } while(num >= 0);

  return 0;
}
