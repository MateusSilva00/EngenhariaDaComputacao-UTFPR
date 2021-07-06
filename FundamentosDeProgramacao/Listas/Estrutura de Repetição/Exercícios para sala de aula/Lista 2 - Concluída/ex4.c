// Apresentar os números divisíveis por 4 ou múltiplos de 10 entre 500 e 0 e a média
// desses múltiplos.
#include <stdio.h>

int main (){
  int i, media = 0, count = 0;
  for (i = 500; i>=0; i--){
    if (i % 4 == 0 || i % 10 == 0){
      printf("\n%d", i);
      if (i % 10 == 0 && i != 0){
        count++;
        printf("\t Múltiplo de 10");
        media = media + i;
      }
      else printf("\tDivisível por 4");
    }
  }
  printf("\nSoma dos múltiplos %d\nContador %d", media,count);

  media = (float)media / (float)count;
  printf("\nMédia dos múltiplos de 10 é %d", media);

  return 0;
}
