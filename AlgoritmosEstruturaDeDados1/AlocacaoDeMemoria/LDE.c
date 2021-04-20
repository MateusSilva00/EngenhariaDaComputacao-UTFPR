#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
    struct elem* prox;
    struct elem* ant;
    char filme[30];
}no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}ListaDE;

ListaDE* Definir(){
  ListaDE* L = (ListaDE*) malloc(sizeof(ListaDE));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

booleano ListaVazia(ListaDE *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

no* CriarNo(const char *s){
  no* novo = (no*)malloc(sizeof(no));
  strcpy(novo->filme, s);
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

booleano InserirUnico(ListaDE *L, no* novo){
  if(L->quant != 0)
    return FALSE;
  else {
    L->inicio = novo;
    L->fim = novo;
    L->quant = 1;
    return TRUE;
  }
}

booleano InserirPorPosicao(ListaDE* L, no* novo, int pos){
  if(pos < 0 || pos > L->quant)
    return FALSE;
  if(L->quant == 0){
    InserirUnico(L, novo);
  }
  else{
    if(pos == 0){
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
    }
    else if(pos == L->quant){
      L->fim->prox = novo;
      novo-> ant = L->fim;
      L->fim = novo;
    }
    else{
      no* aux;
      int cont = 0;
      for(; cont < pos; cont++){
        aux = aux->prox;
      }
      aux->ant->prox = novo;
      novo->ant = aux->ant;
      aux->ant = novo;
      novo->prox = aux;
    }
    L->quant++;
  }
  return TRUE;
}

void RemoverInicio(ListaDE* L){
  if(!ListaVazia(L)){
    no *atual = L->inicio;
    L->inicio = atual->prox;
    L->inicio->ant = NULL;
    L->quant--;
  }
}

void RemoverFim(ListaDE* L){
  if(!ListaVazia(L)){
    no *atual = L->fim;
    L->fim = atual->ant;
    L->fim->prox = NULL;
    L->quant--;
  }
}

booleano RemoverPorPosicao(ListaDE* L, int pos){
  if(!ListaVazia(L)){
    if(pos < 0 || pos > L->quant)
      return FALSE;
    if(pos == 0){
      RemoverInicio(L);
    }
    else if(pos == L->quant-1){
      RemoverFim(L);
    }
    else{
      no* atual = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++){
        atual = atual->prox;
      }
      atual->ant->prox = atual->prox;
      atual->prox->ant = atual->ant;
      free(atual);
      L->quant--;
    }
    return TRUE;
  }
  else return FALSE;
}

void ImprimirANT(ListaDE* L){
  if(L->quant == 0)
    printf("Lista Vazia!\n\n");
  else{
    no *aux = L->fim;
    for(int i=0; i < L->quant; i++){
      printf("%s\n", aux->filme);
      aux = aux->ant;
    }
  }
}

void ImprimirPROX(ListaDE* L){
  if(L->quant == 0)
    printf("Lista Vazia!\n\n");
  else{
    no *aux = L->inicio;
    for(int i=0; i < L->quant; i++){
      printf("%s\n", aux->filme);
      aux = aux->prox;
    }
  }
}
