// 5. A seguir, crie um programa que leia esse arquivo utilizando no prompt “programa.exe <
// entrada.txt”. Considerando que cada linha tem 3 números e 1 string no formato “A B C S”, seu
// programa deve:
// - Sempre que A = 1, insira um elemento em uma lista dinâmica duplamente encadeada (LDDE)
// com chave=C e info=S na posição B;
// - Sempre que A = 2, remova o elemento da LDDE com chave = B (ignore C e S, neste caso);
// - Sempre que A = 3, imprima todos nós da LDDE (ignore B, C e S, neste caso).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
    struct elem* prox;
    struct elem* ant;
    char info[5];
    int chave;
}no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}ListaDE;

ListaDE* Definir(){
  ListaDE* L = (ListaDE*) malloc(sizeof(ListaDE));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

booleano ListaVazia(ListaDE *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

no* CriarNo(char *s, int k){
  no* novo = (no*)malloc(sizeof(no));
  strcpy(novo->info, s);
  novo->chave = k;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

booleano InserirUnico(ListaDE *L, no* novo){
  if(!ListaVazia(L))
    return FALSE;
  else {
    L->inicio = novo;
    L->fim = novo;
    L->quant = 1;
    return TRUE;
  }
}

booleano InserirPorPosicao(ListaDE* L, no* novo, int pos){
  if(pos < 0 || (pos > L->quant && L->quant > 1))
    return FALSE;
  if(L->quant == 0){
    InserirUnico(L, novo);
  }
  else{
    if(pos == 0){
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
    }
    else if(pos == L->quant){
      L->fim->prox = novo;
      novo-> ant = L->fim;
      L->fim = novo;
    }
    else{
      no* aux;
      int cont = 0;
      for(; cont < pos; cont++){
        aux = aux->prox;
      }
      aux->ant->prox = novo;
      novo->ant = aux->ant;
      aux->ant = novo;
      novo->prox = aux;
    }
    L->quant++;
  }
  return TRUE;
}

void RemoverInicio(ListaDE* L){
  if(!ListaVazia(L)){
    no *atual = L->inicio;
    L->inicio = atual->prox;
    L->inicio->ant = NULL;
    L->quant--;
  }
}

void RemoverFim(ListaDE* L){
  if(!ListaVazia(L)){
    no *atual = L->fim;
    L->fim = atual->ant;
    L->fim->prox = NULL;
    L->quant--;
  }
}

booleano RemoverPorPosicao(ListaDE* L, int pos){
  if(!ListaVazia(L)){
    if(pos < 0 || pos > L->quant)
      return FALSE;
    if(pos == 0){
      RemoverInicio(L);
    }
    else if(pos == L->quant-1){
      RemoverFim(L);
    }
    else{
      no* atual = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++){
        atual = atual->prox;
      }
      atual->ant->prox = atual->prox;
      atual->prox->ant = atual->ant;
      free(atual);
      L->quant--;
    }
    return TRUE;
  }
  else return FALSE;
}

void Imprimir(ListaDE* L){
  if(L->quant == 0)
    printf("Lista Vazia!\n\n");
  else{
    no *aux = L->inicio;
    for(int i=0; i < L->quant; i++){
      printf("[%d] %s\n", aux->chave,aux->info);
      aux = aux->prox;
    }
  }
}

int main(){

  ListaDE *L;
  L = Definir();

  int A, B, C, cont = 0;
  char s[5];
  no* aux;

  while (cont < 8) {
    scanf("%d %d %d", &A, &B, &C);
    scanf("%s", s);
    if (A == 1){
      aux = CriarNo(s, C);
      InserirPorPosicao(L, aux, B);
    }
    else if(A == 2){
      RemoverPorPosicao(L, B);
    }
    else if(A == 3){
      Imprimir(L);
    }
    cont++;
  }

  return 0;
}
