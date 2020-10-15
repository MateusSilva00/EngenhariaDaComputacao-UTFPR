// 7Ler 10 números e desses contar quantos são pares, quantos são ímpares e quantos
// são divisíveis por 7. Apresentar essas quantidades.
#include <stdio.h>

int main (){

  int count=1, num, par=0, impar=0, div7=0;
  while (count <= 10) {
    printf("%d - Insira um número.: ", count);
    scanf("%d", &num);
    count++;
    if (num % 2 == 0){
      par++;
    }
    if (num % 2 != 0){
      impar++;
    }
    if (num % 7 == 0){
      div7++;
    }
  }
  printf("Quantidade de pares.: %d\nQuantidade de ímpares.: %d\nDivisiveis por 7.: %d",par, impar, div7);

  return 0;
}
