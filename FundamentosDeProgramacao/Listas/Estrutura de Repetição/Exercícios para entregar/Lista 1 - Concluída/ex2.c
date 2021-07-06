// Elaborar um programa para mostrar, em ordem decrescente, os números divisíveis por
// 3 entre 200 e 100.
#include <stdio.h>

int main (){
  int div3, i = 200;
  for (i; i >= 100; i--) {
    div3 = i % 3;
    if (div3 == 0){
      printf("%d ", i);
    }

  }

  return 0;
}
