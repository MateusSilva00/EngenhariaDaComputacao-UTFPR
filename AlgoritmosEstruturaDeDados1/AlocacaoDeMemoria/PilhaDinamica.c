#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
    int id;
    char info[10];
    struct elem* anterior;
}no;

typedef struct{
  int quant;
  no* topo;
}Pilha;

booleano Definir(Pilha *P){
  if(P == NULL){
    return FALSE;
  }
  P->quant = 0;
  P->topo = NULL;
  return TRUE;
}

Pilha* CriarPilha(){
    Pilha* P = (Pilha*) malloc(sizeof(Pilha));
    if(P==NULL)
      return P;
    P-> quant = 0;
    P-> topo = NULL;
    return P;
}

booleano PilhaVazia(Pilha *F){
  if(F->quant == 0)
    return TRUE;
  else return FALSE;
}

void Empilha(Pilha *P, no *novo){
  if(P->quant == 0){
    P->topo = novo;
  }
  else{
      novo->anterior = P->topo;
      P->topo = novo;
  }
  P->quant++;
}

booleano Desempilha(Pilha *P){
  no *aux = P->topo;
  if(!PilhaVazia(P)){
    P->topo = P->topo->anterior;
    P->quant--;
    free(aux);
    return TRUE;
  }
  else return FALSE;
}

no* CriarNo(int i, const char *s){
  no* novo;
  novo = (no*) malloc(sizeof(no));
  novo->id = i;
  strcpy(novo->info, s);
  novo->anterior = NULL;
  return novo;
}

void Imprimir(Pilha *P){
  no* aux;
  aux = P->topo;

  if(aux == NULL){
    printf("Pilha vazia!\n");
  }

  while (aux != NULL) {
    printf("%d %s\n", aux->id, aux->info);
    aux = aux->anterior;
  }
  printf("\n");
}
