// 7) Implemente uma busca por chave para uma lista duplamente encadeada sabendo que
// seus elementos estão ordenados por chave. Se a chave buscada for mais parecida com a
// chave do 1º nó, faça uma busca sentido início->fim; caso a chave buscada seja mais
// parecida com a chave do último nó, faça uma busca no sentido fim→início.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
    struct elem* prox;
    struct elem* ant;
    char filme[30];
    int key;
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

no* CriarNo(const char *s, int key){
  no* novo = (no*)malloc(sizeof(no));
  strcpy(novo->filme, s);
  novo->prox = NULL;
  novo->ant = NULL;
  novo->key = key;
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
  if(pos < 0 || pos > L->quant)
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

void Imprimir(ListaDE* L){
  if(L->quant == 0)
    printf("Lista Vazia!\n\n");
  else{
    no *aux = L->inicio;
    for(int i=0; i < L->quant; i++){
      printf("[%d] %s\n", aux->key, aux->filme);
      aux = aux->prox;
    }
  }
}

void search(ListaDE* L, int find) {

  if(find < 0)
    find = find*(-1);
  int tentativas = 1;

  int inicio = L->inicio->key;
  int fim = L->fim->key;

  if(-1*(find - fim) < find - inicio){
    no* aux = L->fim;
    while (aux->key != find) {
      aux = aux->ant;
      tentativas++;
      if(tentativas > L->quant/2+1){
        printf("Filme não encontrado!\n");
        return;
      }
    }
    printf("\nFilme encontrado em %d tentativas!\n[%d] [%s]", tentativas,aux->key, aux->filme);
  }
  else {
    no* aux = L->inicio;
    while (aux->key !=find) {
      aux = aux->prox;
      tentativas++;
      if(tentativas > L->quant/2+1){
        printf("Filme não encontrado!\n");
        return;
      }
    }
    printf("\nFilme encontrado em %d tentativas!\n[%d] [%s]", tentativas,aux->key, aux->filme);
  }
}

int main(){
  ListaDE *L;
  L = Definir();

  no* f1 = CriarNo("Forrest Gump", 15);
  no* f2 = CriarNo("Mente Brilhante", 20);
  no* f3 = CriarNo("Indiana Jones", 25);
  no* f4 = CriarNo("Estrelas Além do Tempo", 30);
  no* f5 = CriarNo("Sua mãe é minha futura esposa", 35);
  no* f6 = CriarNo("O pior aluno da escola", 40);
  no* f7 = CriarNo("As branquelas", 45);
  no* f8 = CriarNo("Os 3 patetas", 50);
  no* f9 = CriarNo("O chupa-cabra", 55);

  InserirPorPosicao(L, f1, 0);
  InserirPorPosicao(L, f2, 1);
  InserirPorPosicao(L, f3, 2);
  InserirPorPosicao(L, f4, 3);
  InserirPorPosicao(L, f5, 4);
  InserirPorPosicao(L, f6, 5);
  InserirPorPosicao(L, f7, 6);
  InserirPorPosicao(L, f8, 7);
  InserirPorPosicao(L, f9, 8);

  printf("\t=== LISTA ===\n");
  Imprimir(L);


  int pos;

  printf("\nDeseja buscar por qual chave? ");
  scanf("%d", &pos);
  search(L, pos);

  return 0;
}
