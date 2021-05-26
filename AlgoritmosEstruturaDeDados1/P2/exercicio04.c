// 4. (2,0) Implementar uma função de inserir nós em uma pilha encadeada com as seguintes regras:
// a) Quando o “id” do novo nó for par, este nó é inserido no topo da pilha;
// b) Quando o “id” do novo nó for ímpar, o atual nó no topo é removido antes que o novo nó seja colocado no
// lugar
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE  0
typedef int booleano;

typedef struct elem{
  int id;
  struct elem* anterior;
} no;

typedef struct{
  int quant;
  no* topo;
} Pilha;


Pilha *CriarPilha(){
  Pilha *P = (Pilha*) malloc(sizeof(Pilha));
  P->quant = 0;
  P->topo = NULL;
  return P;
}

no* CriarNo(int i){
  no* novo = (no*) malloc(sizeof(no));
  novo->id = i;
  novo->anterior = NULL;
  return novo;
}

void Desempilha(Pilha *P){
  no *aux = P->topo;
  P->topo = P->topo->anterior;
  P->quant--;
  free(aux);
}

void Empilha(Pilha *P, no* novo){
  if(P->quant == 0){
    P->topo = novo;
  }
  else{
    if(novo->id % 2 == 0){
      novo->anterior = P->topo;
      P->topo = novo;
    }
    else{
      Desempilha(P);
      novo->anterior = P->topo;
      P->topo = novo;
    }
  }
  P->quant++;
}

void Imprimir(Pilha *P){
  no* aux = P->topo;
  if(aux == NULL)
    printf("Pilha Vázia\n");
  else{
    for(int i = 0; i < P->quant; i++){
      printf("[%d]  ", aux->id);
      aux = aux->anterior;
    }
    printf("\n");
  }
}

int main(){

  srand(time(0));

  Pilha *P = CriarPilha();
  no* n1;
  int randomico;
  n1 = CriarNo(10); Empilha(P, n1);
  n1 = CriarNo(20); Empilha(P, n1);
  n1 = CriarNo(30); Empilha(P, n1);
  n1 = CriarNo(40); Empilha(P, n1);
  n1 = CriarNo(50); Empilha(P, n1);

  printf("Pilha padrão\n");
  Imprimir(P);

  for(int i = 0; i < 6; i++){
    randomico = rand() % 100;
    n1 = CriarNo(randomico); Empilha(P, n1);
    printf("\nInserindo: %d\n", randomico);
    Imprimir(P);
  }

  return 0;
}
