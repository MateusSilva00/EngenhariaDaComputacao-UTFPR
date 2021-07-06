#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main (){
  setlocale(LC_ALL, "Portuguese");
  int num, positivo=0, negpar=0, count=0;
  float media=0;

  do {
    printf("Informe um número.: ");
    scanf("%d", &num);

    if (num > 0){
      positivo++;
    }
    else if (num < 0 && num % 2 == 0){
      negpar++;
    }

    else if (num % 3 == 0 && num != 0){
      media = media + num;
      count++;
    }

    else if (num == 0){
      break;
    }

  } while(num != 0);
  media = abs(media)/count;
  printf("Números positivo.:%d\nNúmeros negativos que são pares.:%d\nA media dos números divisíveis por 3 é.: %.2f", positivo, negpar, media);

  return 0;
}
