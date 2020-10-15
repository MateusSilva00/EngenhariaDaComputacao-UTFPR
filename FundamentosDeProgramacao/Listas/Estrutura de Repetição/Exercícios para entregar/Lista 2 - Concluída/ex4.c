#include <stdio.h>

int main (){

  int i, count=0;
  float media=0;

  for (i=500; i>=0; i--){
    if (i % 2 != 0 && i % 7 == 0){
      printf("%d ", i);
    }
    else if (i % 2 == 0 && i % 3 == 0){
      media = media + i;
      count ++;
    }
  }
  media = media / count;
  printf("\nMedia dos pares e divisíveis por 3.: %2.f", media);


  return 0;
}
