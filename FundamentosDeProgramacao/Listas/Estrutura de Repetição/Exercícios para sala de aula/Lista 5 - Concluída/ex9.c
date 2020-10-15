#include <stdio.h>

int main (){

  int num, j=0, i=1, count=0, resultado;
  float media=0;
  printf("Quanto numero impares e multiplos de 5 quer mostrar.: ");
  scanf("%d", &num);
  if (num < 0){
    num = num * -1;
  }
  do {
    j++;
    if(j % 2 != 0 && j % 5 == 0){
      printf("%d\n", j);
      i++;
    }
    if(j % 3 == 0){
      media = media + j;
      count++;
    }

  } while(i<=num);
  media = media / count;
  printf("A media dos numeros multiplos de 3 e %.2f", media);

  return 0;
}
