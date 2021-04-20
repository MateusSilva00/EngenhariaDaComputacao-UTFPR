#include "PilhaDinamica.c"
#include <stdio.h>

int main(){

  Pilha F;
  Definir(&F);
  Imprimir(&F);


  no* n1;
  n1 = CriarNo(1, "aa");
  no* n2;
  n2 = CriarNo(2, "Neymar");
  no* n3;
  n3 = CriarNo(3, "Santos");
  no* n4;
  n4 = CriarNo(4, "PSG");

  Empilha(&F, n1);
  Empilha(&F, n2);
  Empilha(&F, n3);
  Empilha(&F, n4);
  Imprimir(&F);
  Desempilha(&F);
  Imprimir(&F);
  Desempilha(&F);
  Imprimir(&F);

  return 0;
}
