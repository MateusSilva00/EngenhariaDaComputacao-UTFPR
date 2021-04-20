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

Pilha* CriarPilha(int i, char *s){
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

no* CriarNo(int i, char *s){
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
    printf("Endereço: %p\n%d %s\n", aux, aux->id, aux->info);
    aux = aux->anterior;
  }

  printf("\n");
}

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
