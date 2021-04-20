#include "FilaDinamica.c"
#include <stdio.h>

int main(){

  Fila F;
  Definir(&F);
  Imprimir(&F);


  no* n1;
  n1 = CriarNo(1, "aa");
  no* n2;
  n2 = CriarNo(2, "bb");
  no* n3;
  n3 = CriarNo(3, "fodasse");

  Inserir(&F, n1);
  Inserir(&F, n2);
  Inserir(&F, n3);
  Imprimir(&F);
  Remover(&F);
  Imprimir(&F);
  Remover(&F);
  Imprimir(&F);

  return 0;
}
