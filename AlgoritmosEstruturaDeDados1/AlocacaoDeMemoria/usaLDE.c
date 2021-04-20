#include "LDE.c"
#include <stdio.h>

int main(){
  ListaDE *L;
  L = Definir();

  no* f1 = CriarNo("Forrest Gump");
  no* f2 = CriarNo("Mente Brilhante");
  no* f3 = CriarNo("Indiana Jones");
  no* f4 = CriarNo("Estrelas Além do Tempo");

  InserirPorPosicao(L, f1, 0);
  InserirPorPosicao(L, f2, 1);
  InserirPorPosicao(L, f3, 2);
  InserirPorPosicao(L, f4, 3);

  printf("Lista em Ordem Crescente\n");
  ImprimirPROX(L);

  printf("\nLista em Ordem Decrescente\n");
  ImprimirANT(L);
  printf("\n\n");

  RemoverPorPosicao(L, 0);
  printf("Após remover posicao 0!\n");
  ImprimirPROX(L);

  RemoverPorPosicao(L, 0);
  printf("\nApós remover nova posicao 0!\n");
  ImprimirPROX(L);

  RemoverPorPosicao(L, 1);
  printf("\nApós remover nova posicao 1!\n");
  ImprimirPROX(L);

  return 0;
}
