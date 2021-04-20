#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
    int id;
    char info[10];
    struct elem* prox;
}no;

typedef struct{
  int quant;
  no* ini;
  no* fim;
}Fila;

booleano Definir(Fila *F){
  if(F == NULL){
    return FALSE;
  }
  F->quant = 0;
  F->ini = NULL;
  F->fim = NULL;
  return TRUE;
}

Fila* CriarFila(int i, char *s){
    Fila* F = (Fila*) malloc(sizeof(Fila));
    if(F==NULL)
      return F;
    F-> quant = 0;
    F->ini = NULL;
    F->fim = NULL;
    return F;
}

booleano FilaVazia(Fila *F){
  if(F->quant == 0)
    return TRUE;
  else return FALSE;
}

void Inserir(Fila *F, no *novo){
  if(F->quant == 0){
    F->ini = novo;
    F->fim = novo;
  }
  else{
      F->fim->prox = novo;
      F->fim = novo;
  }
  F->quant++;
}

booleano Remover(Fila *F){
  no *p = F->ini;
  if(!FilaVazia(F)){
    F->ini = F->ini->prox;
    F->quant--;
    free(p);
    return TRUE;
  }
  else return FALSE;
}

no* CriarNo(int i, char *s){
  no* novo;
  novo = (no*) malloc(sizeof(no));
  novo->id = i;
  strcpy(novo->info, s);
  novo->prox = NULL;
  return novo;
}

void Imprimir(Fila *F){
  no* aux;
  aux = F->ini;

  if(aux == NULL){
    printf("Fila vazia!\n");
  }

  while (aux != NULL) {
    printf("Endereço: %p\n%d %s\n", aux, aux->id, aux->info);
    aux = aux->prox;
  }

  printf("\n");
}

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
