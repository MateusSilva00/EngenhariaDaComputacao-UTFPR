// Ler um número maior que 2 e imprimir todos os pares entre 2 e o número lido. Imprimir
// a soma dos pares, o produto dos ímpares que são divisíveis por 9 e a média de todos os
// números do intervalo.
#include <stdio.h>
#include <locale.h>


int main () {
  setlocale(LC_ALL,"Portuguese");
  int num, sumpar = 0, prodnove = 1, media=0, count = 0;;
  printf("Insira um número maior que 2.: ");
  scanf("%d", &num);

  for(num; num>=2; num--){

    if( num%2 == 0){
      sumpar = sumpar + num;
      printf("%d\n", num);
    }
    if (num%9 == 0) {
      prodnove = prodnove * num;
    }
    count++;
    media = media + num;
  }
  media = media/count;
  printf("Soma dos números pares = %d\nProduto dos ímpares dos divisíveis por 9 = %d\nMédia de todos os números do intervalo = %d", sumpar, prodnove,media);

  return 0;
}
