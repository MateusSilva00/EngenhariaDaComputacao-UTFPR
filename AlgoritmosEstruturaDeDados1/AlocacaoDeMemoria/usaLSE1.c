#include "LSE1.c"
#include <stdio.h>

int main(){

  ListaSE *L;
  L = Definir();

  Imprimir(L);
  no* n1;
  n1 = CriarNo("Refrigerante", 5, 7);
  Inserir(L, n1, 0);

  no* n2;
  n2 = CriarNo("Queijo", 1, 5.20);
  Inserir(L, n2, 1);

  no* n3;
  n3 = CriarNo("Salmão", 1, 35.30);
  Inserir(L, n3, 2);

  Imprimir(L);
  Remover(L);
  Remover(L);
  Imprimir(L);

  return 0;
}
