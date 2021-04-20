#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
  char produtos[20];
  int unidade;
  float valor;
  struct elem* prox;
}no;

typedef struct{
  int quant;
  no* inicio;
} ListaSE;

ListaSE* Definir(){
  ListaSE *L;
  L = (ListaSE*) malloc(sizeof(ListaSE));
  if(L == NULL)
    return NULL;
  L->quant = 0;
  L->inicio = NULL;
  return L;
}

no* CriarNo(char *s, int i, float f){
  no* novo;
  novo = (no*) malloc(sizeof(no));
  strcpy(novo->produtos, s);
  novo->unidade = i;
  novo->valor = f;
  novo->prox = NULL;
  return novo;
}

booleano Inserir(ListaSE *L, no* novo, int posicao){
  if(posicao < 0 || posicao > L->quant)
    return FALSE;
  if(posicao == 0){
    novo->prox = L->inicio;
    L->inicio = novo;
  }
  else{
    no* aux = L->inicio;
    int cont = 0;
    while (cont != posicao - 1) {
      aux = aux->prox;
      cont++;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
  }
  L->quant++;
  return TRUE;
}

void Imprimir(ListaSE *L){
  no* aux;
  aux = L->inicio;
  printf("\n== Lista ==\n");
  if(!L->quant == 0){
    for(int i=0; i < L->quant; i++){
      printf("\nItem: %s\nQuantidade: %d\nPreço: %.2f\n", aux->produtos, aux->unidade, aux->valor);
      aux = aux->prox;
    }
  }
  else printf("Lista vazia!\n");
}

int main(){

  ListaSE *L;
  L = Definir();

  Imprimir(L);
  no* n1;
  n1 = CriarNo("Refrigerante", 5, 7);
  Inserir(L, n1, 0);
  Imprimir(L);

  no* n2;
  n2 = CriarNo("Queijo", 1, 5.20);
  Inserir(L, n2, 1);
  Imprimir(L);


  return 0;
}
