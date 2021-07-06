#include <stdio.h>

int main (){
  int i, s;
  s = 1;
  for (i = 1; i<5; i++){
    s = s * i;
  }
  printf("%d", s);

  return 0;
}
//a) A variavel foi inicilizada com 1 pois se não atribusse nenhum valor a variavel
// ocuparia o maior espaço possível de memória e o compilador devolveria um valor no sense
// b) O resultado deu 0
// c) Inicilizar o contador em i = 1
