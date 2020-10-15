// Mostrar os valores ímpares e não divisíveis por 5 entre 200 e 1. Apresentar os valores
// em ordem decrescente. Fazer a média dos valores desse intervalo que são divisíveis por
// 3 e por 5.
#include <stdio.h>

int main(){
    int i, count = 0;
    float media = 0;
    for (i=200; i>=1; i--){
      if (i % 5 != 0){
        printf("%d\n", i);
      }
      else if (i%5 == 0 && i%3==0){
        media = media + i;
        count++;
      }
    }

    media = media / count;

    printf("Media dos divisiveis por 3 e por 5.: %.2f", media);

  return 0;
}
