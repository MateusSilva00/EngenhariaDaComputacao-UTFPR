#include "PilhaDinamica.c"
#include <stdio.h>

int main(){

  Pilha P;
  Definir(&P);
  Imprimir(&P);


  no* n1;
  n1 = CriarNo(1, "aa");
  no* n2;
  n2 = CriarNo(2, "Neymar");
  no* n3;
  n3 = CriarNo(3, "Santos");
  no* n4;
  n4 = CriarNo(4, "PSG");

  Empilha(&P, n1);
  Empilha(&P, n2);
  Empilha(&P, n3);
  Empilha(&P, n4);
  Imprimir(&P);
  Desempilha(&P);
  Imprimir(&P);
  Desempilha(&P);
  Imprimir(&P);

  return 0;
}
