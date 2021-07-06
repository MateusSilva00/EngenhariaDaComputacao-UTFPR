// 1) Desenvolva uma função chamada dequeueN() para remover N nós a partir do início de
// uma fila. Retorne apenas o nó que possuir a maior chave, e dê free nos demais.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

// FILA DO CLUB
typedef struct elem{
  int id;
  char nome[15];
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
  F-> quant = 0;
  F->ini = NULL;
  F->fim= NULL;
  return TRUE;
}

booleano FilaVazia(Fila *F){
  if(F->quant == 0)
    return TRUE;
  else return FALSE;
}

Fila* CriarFila(){
  Fila* F = (Fila*) malloc(sizeof(Fila));
  if(F==NULL)
    return F;
  F-> quant = 0;
  F->ini = NULL;
  F->fim = NULL;
  return F;
}

void Enqueue(Fila *F, no *novo){
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

booleano Dequeue(Fila *F){
  no *p = F->ini;
  if(!FilaVazia(F)){
    F->ini = F->ini->prox;
    F->quant--;
    free(p);
    return TRUE;
  }
  else return FALSE;
}

booleano DequeueN(Fila *F, int quantidade){
  int i = 0;
  if(!FilaVazia(F)){
    while (i < quantidade) {
      no *aux = F->ini;
      F->ini = F->ini->prox;
      F->quant--;
      free(aux);
      aux = aux->prox;
      i++;
    }
    return TRUE;
  }
  else return FALSE;
}

no* CriarNo(int i, const char *s){
  no* novo;
  novo = (no*)malloc(sizeof(no));
  novo->id = i;
  strcpy(novo->nome, s);
  novo->prox = NULL;
  return novo;
}

void Imprimir(Fila *F){
  no* aux = F->ini;
  if(!FilaVazia(F)){
    while (aux != NULL) {
      printf("%d - %s\n", aux->id, aux->nome);
      aux = aux->prox;
    }
  }
  printf("\n");
}

int main(){

  Fila F;
  Definir(&F);
  Imprimir(&F);

  int n;

  no* n1; no* n2; no* n3; no* n4; no* n5; no* n6;
  n1 = CriarNo(1, "Mateus");
  n2 = CriarNo(2, "Lucas");
  n3 = CriarNo(3, "Éder");
  n4 = CriarNo(4, "Vini");
  n5 = CriarNo(5, "JP");
  n6 = CriarNo(6, "Dan");

  Enqueue(&F, n1);
  Enqueue(&F, n2);
  Enqueue(&F, n3);
  Enqueue(&F, n4);
  Enqueue(&F, n5);
  Enqueue(&F, n6);

  printf("=== FILA DO CLUBE ===\n");
  Imprimir(&F);
  printf("\nQuantos devem entrar: ");
  scanf("%d", &n);
  DequeueN(&F, n);

  Imprimir(&F);

  return 0;
}
