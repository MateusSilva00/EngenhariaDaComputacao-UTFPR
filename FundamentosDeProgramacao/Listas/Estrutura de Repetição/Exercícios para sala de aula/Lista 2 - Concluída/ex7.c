#include <stdio.h>

int main (){
  int i, s;
  s = 0;
  for (i = 0; i<10; i++){
    s = s + 1;
  }
  printf("%d", s);

  return 0;
}
// A variavel foi inicilizada com 0 pois se não atribusse nenhum valor a variavel
// ocuparia o maior espaço possível de memória e o compilador devolveria um valor no sense
