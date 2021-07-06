#include <stdio.h>

int main (){

  int num = 100;
  float media;
  while (num >= 0) {
    printf("%d ", num);
    media = media + num;
    num--;
  }
  media = media / 100;
  printf("\nMedia aritmética %.2f", media);

  return 0;
}
