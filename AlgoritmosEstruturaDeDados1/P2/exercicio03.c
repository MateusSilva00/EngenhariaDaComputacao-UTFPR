// 3. (2,0) Implementar uma função “RemoveN” que remove o N-ésimo elemento de uma lista circular
// encadeada. Comece a contar a partir do nó início. Caso N seja igual a 0, o início deve ser removido. A lista
// pode ser tanto simples quanto duplamente encadeada. Observe que, sendo a lista circular, não há problema de N
// ter valor maior que a quantidade de nó
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

typedef int booleano;

typedef struct elem{
  struct elem* prox;
  struct elem* ant;
  char letra;
} no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}LDECirc;

LDECirc* Definir(){
  LDECirc* L = (LDECirc*) malloc(sizeof(LDECirc));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

no* CriarNo(char c){
  no* novo = (no*) malloc(sizeof(no));
  novo->letra = c;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

booleano ListaVazia(LDECirc *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

booleano InserirUnico(LDECirc *L, no* novo){
  if(ListaVazia(L)){
    L->inicio = novo;
    L->fim = novo;
    L->quant = 1;

    L->inicio->prox = L->fim;
    L->inicio->ant = L->fim;
    return TRUE;
  }
  return FALSE;
}

booleano InserirPorPosicao(LDECirc* L, no* novo, int pos){
  if(pos < 0 || pos > L->quant)
    return FALSE;
  if(L->quant == 0)
    InserirUnico(L, novo);
  else{
    if(pos == 0){
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
    }
    else if(pos == L->quant){
      L->fim->prox = novo;
      novo->ant = L->fim;
      L->fim = novo;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
    }
    else{
      no* aux = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++)
        aux = aux->prox;

      aux->ant->prox = novo;
      novo->ant = aux->ant;
      aux->ant = novo;
      novo->prox = aux;
    }
    L->quant++;
  }
  return TRUE;
}

void imprimir(LDECirc *L){
  if(ListaVazia(L))
    printf("Lista vázia!\n");
  else {
    no* aux = L->inicio;
    for(int i = 0; i < L->quant; i++){
      printf("[%d]%c ", i,aux->letra);
      aux = aux->prox;
    }
  }
}

void RemoverUnico(LDECirc *L){
  no* aux = L->inicio;
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  free(aux);
}

booleano RemoveN(LDECirc *L, int N){
  if(N < 0 || L->quant == 0)
    return FALSE;
  if(L->quant == 0){
    RemoverUnico(L);
    return TRUE;
  }
  else{
    if(N == 0){
      no* aux = L->inicio;
      L->inicio = aux->prox;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
      free(aux);
    }
    else if(N == L->quant){
      no* aux = L->fim;
      L->fim = aux->ant;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
      free(aux);
    }
    else{
      no* aux = L->inicio;
      int cont = 0;
      for(; cont < N; cont++)
        aux = aux->prox;
      aux->ant->prox = aux->prox;
      aux->prox->ant = aux->ant;
      free(aux);
    }
    L->quant--;
  }
  return TRUE;
}

int main(){

  LDECirc *L = Definir();

  no* f1;
  srand(time(0));
  int remover, j = 0;

  for(int i = 0; i < 10; i++) {
    f1  = CriarNo(i+97);
    InserirPorPosicao(L, f1, i);
  }

  printf("\n=== Lista completa ===\n");
  imprimir(L);
  while(j < 5){
    remover = rand() % 20;
    RemoveN(L, remover);
    printf("\n\n=== Apos remover o elemento %d\n", remover);
    imprimir(L);
    j++;
  }

  return 0;
}
