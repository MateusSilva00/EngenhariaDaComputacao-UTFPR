// 1) Desenvolva uma função chamada PopN() para remover N nós a partir do início de
// uma pilha. Retorne apenas o nó que possuir a maior chave, e dê free nos demais.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

//TABELA DO BRASILEIRÃO
typedef struct elem{
  int id;
  char time[30];
  struct elem* anterior;
} no;

typedef struct{
  int quant;
  no* topo;
}Pilha;

booleano Definir(Pilha *P){
  if(P == NULL)
    return FALSE;
  P->quant = 0;
  P->topo = NULL;
  return TRUE;
}

Pilha* CriarPilha(){
  Pilha* P = (Pilha*)malloc(sizeof(Pilha));
  if(P == NULL)
    return P;
  P->quant = 0;
  P->topo = NULL;
  return P;
}

booleano PilhaVazia(Pilha *P){
  if(P->quant == 0){
    printf("Pilha Vázia\n");
    return TRUE;
  }
  else return FALSE;
}

void Push(Pilha *P, no *novo){
  if(PilhaVazia(P))
    P->topo = novo;
  else{
    novo->anterior = P->topo;
    P->topo = novo;
  }
  P->quant++;
}

booleano Pop(Pilha *P) {
  no *aux = P->topo;
  if(!PilhaVazia(P)){
    P->topo = P->topo->anterior;
    P->quant--;
    free(aux);
    return TRUE;
  }
  else return FALSE;
}

booleano PopN(Pilha *P, int posicao){
  int i=0;
  if(!PilhaVazia(P)){
    while (i < posicao) {
      no* aux = P->topo;
      P->topo = P->topo->anterior;
      P->quant--;
      free(aux);
      aux = aux->anterior;
      i++;
    }
    return TRUE;
  }
  return FALSE;
}

no* CriarNo(int i, const char *team){
  no* novo;
  novo = (no*) malloc(sizeof(no));
  novo->id = i;
  strcpy(novo->time, team);
  novo->anterior = NULL;
  return novo;
}

void Imprimir(Pilha *P){
  if(!PilhaVazia(P)){
    no* aux;
    aux = P->topo;
    while (aux != NULL) {
      printf("%d - %s\n", aux->id, aux->time);
      aux = aux->anterior;
    }
  }
  printf("\n");
}

int main(){

  Pilha P;
  Definir(&P);
  Imprimir(&P);

  int n;

  no* n1; no* n2; no* n3; no* n4; no* n5; no* n6; no* n7;
  n1 = CriarNo(1, "Santos");
  n2 = CriarNo(2, "Santa Cruz");
  n3 = CriarNo(3, "Vasco");
  n4 = CriarNo(4, "Corinthians");
  n5 = CriarNo(5, "Flamengo");
  n6 = CriarNo(6, "Grêmio");
  n7 = CriarNo(7, "São Paulo");

  Push(&P, n1);
  Push(&P, n2);
  Push(&P, n3);
  Push(&P, n4);
  Push(&P, n5);
  Push(&P, n6);
  Push(&P, n7);

  Imprimir(&P);

  printf("\nDeseja desempilhar quantas posições.: ");
  scanf("%d", &n);
  PopN(&P, n);

  Imprimir(&P);


  return 0;
}
