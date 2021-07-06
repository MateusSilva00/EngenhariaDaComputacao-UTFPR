// 2. Divida uma lista encadeada circular em duas da seguinte forma: os nós com chave par
// devem permanecer na lista original, enquanto os nós com chave ímpar devem ser inseridos em
// uma nova lista circular.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

typedef int booleano;

typedef struct elem {
  struct elem* prox;
  struct elem* ant;
  char filme[50];
  int key;
}no;

typedef struct {
  int quant;
  no* inicio;
  no* fim;
}LDECirc;


LDECirc* Definir(){
  LDECirc* L = (LDECirc*)malloc(sizeof(LDECirc));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

no* CriarNo(const char *name, int key){
  no* novo = (no*) malloc(sizeof(no));
  strcpy(novo->filme, name);
  novo->prox = NULL;
  novo->ant = NULL;
  novo->key = key;
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
  else {
    if(pos == 0) {
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
    }
    else if(pos == L->quant) {
      L->fim->prox = novo;
      novo->ant = L->fim;
      L->fim = novo;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
    }
    else {
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

no* RemoverUnico(LDECirc* L) {
  no* remov = L->inicio;
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return(remov);
}

no* RemoverPorPosicao(LDECirc* L, int pos) {

  no* aux;

  if(pos < 0 || pos > L->quant || L->quant == 0)
    return FALSE;
  if(L->quant == 1){
    aux = RemoverUnico(L);
    return(aux);
  }
  else {
    if(pos == 0) {
      aux = L->inicio;
      L->inicio = aux->prox;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
    }
    else if(pos == L->quant - 1) {
      aux = L->fim;
      L->fim = aux->ant;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
    }
    else {
      aux = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++)
        aux = aux->prox;
      aux->ant->prox = aux->prox;
      aux->prox->ant = aux->ant;
    }
    L->quant--;
    return(aux);
  }
}

void Imprimir(LDECirc* L) {
  if(!ListaVazia(L)){
    no* aux = L->inicio;
    for(int i = 0; i < L->quant; i++){
      printf("[%d] %s\n", aux->key, aux->filme);
      aux = aux->prox;
    }
  }
  else printf("Lista Vazia!\n");
}

void separaLista(LDECirc* Lpar, LDECirc* Limpar) {
  no* aux = Lpar->inicio;
  no* temp;

  for(int i = 0; i < Lpar->quant; i++){
    if(aux->key % 2 != 0){
      temp = RemoverPorPosicao(Lpar, i);
      InserirPorPosicao(Limpar, temp, i);
    }
    aux = aux->prox;
  }

}

int main(){

  LDECirc *Lpar;
  Lpar = Definir();

  no* f1 = CriarNo("Interestelar", 5);
  no* f2 = CriarNo("Matrix", 10);
  no* f3 = CriarNo("Os trapalhões", 15);
  no* f4 = CriarNo("Tempos Modernos", 20);


  InserirPorPosicao(Lpar, f1, 0);
  InserirPorPosicao(Lpar, f2, 1);
  InserirPorPosicao(Lpar, f3, 2);
  InserirPorPosicao(Lpar, f4, 3);

  Imprimir(Lpar);

  LDECirc *Limpar;
  Limpar = Definir();

  separaLista(Lpar, Limpar);
  printf("\n\n=== LISTA SEPARADA ===\nPares\n");
  Imprimir(Lpar);
  printf("\n");
  printf("Impares\n");
  Imprimir(Limpar);

  return 0;
}
