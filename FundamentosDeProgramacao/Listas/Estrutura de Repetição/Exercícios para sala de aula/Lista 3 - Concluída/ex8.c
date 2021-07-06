// 8  Apresentar os números pares entre 100 e 200. Contar quantos são ímpares e não
// divisíveis por 3 nesse intervalo. Fazer a média dos valores pares e divisíveis por 5 do
// intervalo.
#include <stdio.h>

int main (){
  int i, imparn3=0, count = 0;
  float media=0;
  for (i = 100; i <=200; i++){
    if (i%2==0){
      printf("%d\n", i);
      if (i % 5 == 0){
        media = media + i;
        count++;
      }
    }

    else if (i % 2 != 0 && i % 3 != 0){
      imparn3++;
    }
  }
  media = media / count;
  printf("Impares nao diviseis por 3.:%d\nMedia de pares e diviseis por 5.:%.2f", imparn3, media);

  return 0;
}
