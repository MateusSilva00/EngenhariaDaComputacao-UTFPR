#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  if(!ListaVazia(L)){
    L->inicio = novo;
    L->fim = novo;
    L->quant = 1;

    L->inicio->prox = L->fim;
    L->inicio->ant = L->fim;
    return TRUE;
  }
  return FALSE;
}

void RemoverUnico(LDECirc* L) {
  no* remov = L->inicio;
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  free(remov);
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

booleano RemoverPorPosicao(LDECirc* L, int pos){
  if(pos < 0 || pos > L->quant || L->quant == 0)
    return FALSE;
  if (L->quant == 1)
    RemoverUnico(L);
  else{
    if(pos == 0){
      no* aux = L->inicio;
      L->inicio = aux->prox;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
      free(aux);
    }
    else if(pos == L->quant-1){
      no *aux = L->fim;
      L->fim = aux->ant;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
      free(aux);
    }
    else{
      no* aux = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++)
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

    LDECirc *L;
    L = Definir();

    no* f1 = CriarNo('a');
    no* f2 = CriarNo('b');
    no* f3 = CriarNo('c');
    no* f4 = CriarNo('d');


  return 0;
}
