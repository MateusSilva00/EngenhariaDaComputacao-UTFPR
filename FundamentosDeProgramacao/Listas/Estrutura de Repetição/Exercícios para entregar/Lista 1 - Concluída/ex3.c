// Mostrar os números entre 10 e 0 (ordem decrescente) com intervalo de 0.5.
#include <stdio.h>

int main (){
  int div3;
  float i = 10;
  for (i; i > 0; i = i-0.5) {
    if (i!=10){
      printf("%5.1f\n", i);
    }
  }

  return 0;
}
