// Apresentar os números entre 10 e 0, ou seja, em ordem decrescente, separados por
// tabulação.
#include <stdio.h>

int main () {

  for(int i=10; i>=0; i--){
    printf("%d\t", i);
  }

  return 0;
}
