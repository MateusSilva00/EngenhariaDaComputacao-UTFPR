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

booleano ListaVazia(ListaSE *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

no* CriarNo(const char *s, int i, float f){
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

booleano Remover(ListaSE *L){
  if(!ListaVazia(L)){
    no* atual = L->inicio;
    L->inicio = atual->prox;
    L->quant--;
    return TRUE;
  }
  return FALSE;
}

void Imprimir(ListaSE *L){
  no* aux;
  aux = L->inicio;
  printf("\n== Lista ==\n");
  if(!L->quant == 0){
    for(int i=0; i < L->quant; i++){
      printf("\nItem: %s\nQuantidade: %d\tPreço: %.2f\n", aux->produtos, aux->unidade, aux->valor);
      aux = aux->prox;
    }
  }
  else printf("Lista vazia!\n");
}
