// Exercício do Batman
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;


typedef struct elem{
  struct elem* prox;
  struct elem* ant;
  int chave;
}no;

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

booleano ListaVazia(LDECirc *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

no* CriarNo(int key){
  no* novo = (no*)malloc(sizeof(no));
  novo->chave = key;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
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

void Imprimir(LDECirc *L){
  if(ListaVazia(L))
    printf("Lista Vazia\n\n");
  else {
    no* aux = L->inicio;
    for(int i=0; i < 2*L->quant; i++) {
      char ascii = (char)aux->chave;
      if(i == L->quant)
        printf("\n");
      printf("[%c] ", ascii);
      aux = aux->prox;
    }
  }
}

void Imprimir_possibilidade(LDECirc *L, no* pos, int quant) {
   if(quant < L->quant) {
     printf("%dª tentativa\t", quant+1);
    no* aux = pos;
    for(int i=0; i < L->quant; i++){
      printf("%c ", aux->chave);
      aux = aux->prox;
    }
    quant++;
    pos = pos->prox;
    printf("\n");
    Imprimir_possibilidade(L, pos, quant);
  }
}

void Imprimir_possibilidade2(LDECirc *L, no* pos, int quant) {
   if(quant < L->quant) {
     printf("%dª tentativa\t", quant+1);
    no* aux = pos;
    for(int i=0; i < L->quant; i++){
      printf("%c ", aux->chave);
      aux = aux->ant;
    }
    quant++;
    printf("\n");
    Imprimir_possibilidade2(L, pos->ant, quant);
  }
}

int main(){

  LDECirc *L;
  L = Definir();

  no* f1 = CriarNo(79); no* f2 = CriarNo(83); no* f3 = CriarNo(89);
  no* f4 = CriarNo(72); no* f5 = CriarNo(87); no* f6 = CriarNo(83);
  no* f7 = CriarNo(85); no* f8 = CriarNo(79); no* f9 = CriarNo(73);
  no* f10 = CriarNo(82); no* f11 = CriarNo(69); no* f12 = CriarNo(83);

  InserirPorPosicao(L, f1, 0);
  InserirPorPosicao(L, f2, 1);
  InserirPorPosicao(L, f3, 2);
  InserirPorPosicao(L, f4, 3);
  InserirPorPosicao(L, f5, 4);
  InserirPorPosicao(L, f6, 5);
  InserirPorPosicao(L, f7, 6);
  InserirPorPosicao(L, f8, 7);
  InserirPorPosicao(L, f9, 8);
  InserirPorPosicao(L, f10, 9);
  InserirPorPosicao(L, f11, 10);
  InserirPorPosicao(L, f12, 11);

  no* inicio = L->inicio;
  no* fim = L->fim;
  // Imprimir(L);
  printf("=== Soluções sentido horário ===\n");
  Imprimir_possibilidade(L, inicio, 0);

  printf("\n\n=== Soluções sentido anti-horário ===\n");
  Imprimir_possibilidade2(L, fim, 0);

  return 0;
}
