// 5) Repita o exercício 4 para uma lista duplamente encadeada
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
  if(!ListaVazia(L))
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

void Imprimir(ListaDE* L){
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

// Inverte os elementos da lista
void inverteLista(no *atual, no* anterior){
  if(atual->prox != NULL)
    inverteLista(atual->prox, atual);
  atual->prox = anterior;
}

// Inverte as referências de inicio e fim
void inverter(ListaDE *L){
  inverteLista(L->inicio, NULL);

  no* aux = L->inicio;
  L->inicio = L->fim;
  L->fim = aux;
}

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

  Imprimir(L);
  inverter(L);
  printf("\n=== LISTA INVERTIDA ===\n");
  Imprimir(L);
  return 0;
}
