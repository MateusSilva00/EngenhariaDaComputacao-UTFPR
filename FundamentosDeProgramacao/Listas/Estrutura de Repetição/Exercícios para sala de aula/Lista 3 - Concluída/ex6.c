// 6Apresente os pares entre 0 e 100, sem utilizar if dentro do for. Também calcule e
// forneça a média dos pares.
#include <stdio.h>

int main (){
  int i, count = 0;
  float media = 0;
  for (i=0; i<=100; i=i+2){
      printf("%d\n",i);
      media = media + i;
      count++;
  }
  media = media / count;
  printf("\nMedia.: %.2f", media);

  return 0;
}
