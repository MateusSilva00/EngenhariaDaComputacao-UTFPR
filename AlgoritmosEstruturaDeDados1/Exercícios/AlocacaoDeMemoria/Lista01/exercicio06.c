// 6) Escreva um método para ordenar uma lista. A escolha entre simplesmente ou duplamente
// encadeada é sua. A escolha de qual método tamém.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
  int letra;
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


no* CriarNo(int s){
  no* novo;
  novo = (no*) malloc(sizeof(no));
  novo->letra = s;
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
      printf("|%d|  ", aux->letra);
      aux = aux->prox;
    }
  }
  else printf("Lista vazia!\n");
}

void swap(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

void bubble_sort(ListaSE *L){
  int change = 1, i;
  while (change == 1) {
    change = 0;
    no* atual = L->inicio;
    no* aux = atual->prox;
    // printf("\natual = %d aux = %d\n", atual->letra, aux->letra);
    for(i = 0; i < L->quant - 1; i++){
      if(atual->letra > aux->letra){
        swap(&atual->letra, &aux->letra);
        change = 1;
      }
      atual = atual->prox;
      aux = aux->prox;
    }
  }
}


int main(){

  ListaSE *L;
  L = Definir();

  srand(time(0));

  no* n1; no* n2; no* n3; no* n4;
  no* n5; no* n6; no* n7; no* n8;

  n1 = CriarNo(rand() % 1000);
  n2 = CriarNo(rand() % 1000);
  n3 = CriarNo(rand() % 1000);
  n4 = CriarNo(rand() % 1000);
  n5 = CriarNo(rand() % 1000);
  n6 = CriarNo(rand() % 1000);
  n7 = CriarNo(rand() % 1000);
  n8 = CriarNo(rand() % 1000);

  Inserir(L, n1, 0);
  Inserir(L, n2, 1);
  Inserir(L, n3, 2);
  Inserir(L, n4, 3);
  Inserir(L, n5, 4);
  Inserir(L, n6, 5);
  Inserir(L, n7, 6);
  Inserir(L, n8, 7);


  Imprimir(L);
  bubble_sort(L);
  Imprimir(L);


  return 0;
}
