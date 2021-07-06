// Apresentar os números entre 0 e 4, com intervalo de 0.25 entre eles, separados por
// tabulação.
#include <stdio.h>

int main () {

  for(float i=0; i<=4; i=i+0.25){
    printf("%.2f\t", i);
  }

  return 0;
}
