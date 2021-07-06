// 1. (4,0) Implemente as seguintes funções para uma lista duplamente encadeada que registra número de
// matrícula e nome de alunos:
// (a) Função que realiza busca pelo número de matrícula. Esta função deve retornar um ponteiro para o nó
// encontrado ou NULL caso não encontre;
// (b) Função “InsereAntesNo”, ou seja, um função que recebe um nó referência (retorno da função acima)
// e um nó novo. O novo nó deve ser inserido na posição exatamente anterior ao nó referência. Caso o nó
// referência seja NULL, o novo nó deve ser colocado no fim da lista.
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
  char nome[25];
  int matricula;
} no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
} ListaDE;

ListaDE* Definir(){
  ListaDE* L = (ListaDE*) malloc(sizeof(ListaDE));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

no* CriarNo(const char *s, int k){
  no* novo = (no*)malloc(sizeof(no));
  novo->matricula = k;
  strcpy(novo->nome, s);
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

booleano InserirUnico(ListaDE *L, no* novo){
  if(L->quant != 0)
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
    printf("Lista Vázia\n");
  else{
    no* aux = L->inicio;
    printf("Aluno\tNº Matrícula\n");
    for(int i = 0 ; i < L->quant; i++){
      printf("%s \t%4d\n", aux->nome, aux->matricula);
      aux = aux->prox;
    }
  }
}

no* buscaMatricula(ListaDE* L, int k){
  no* aux = L->inicio;
  for(int i = 0; i < L->quant; i++){
    if(aux->matricula == k)
      return aux;
    aux = aux->prox;
  }
  return NULL;
}

booleano InsereAntesNo(ListaDE* L, no* referência, no* novo){
  if(referência == NULL){
    L->fim->prox = novo;
    novo->ant = L->fim;
    L->fim = novo;
  }
  else{
    no* aux = L->inicio;
    while (aux != referência) {
      aux = aux->prox;
    }
    aux->ant->prox = novo;
    novo->ant = aux->ant;
    aux->ant = novo;
    novo->prox = aux;
  }
  L->quant++;
  return TRUE;
}

int main(){

  ListaDE* L = Definir();

  no* l1;
  l1 = CriarNo("Pablo Vittar", 1987); InserirPorPosicao(L, l1, 0);
  l1 = CriarNo("Goku Uzumaki", 3187); InserirPorPosicao(L, l1, 1);
  l1 = CriarNo("Santista", 407); InserirPorPosicao(L, l1, 2);
  l1 = CriarNo("Clébio Afonso", 281); InserirPorPosicao(L, l1, 3);
  l1 = CriarNo("Deus", 777); InserirPorPosicao(L, l1, 4);
  l1 = CriarNo("Santanás", 666); InserirPorPosicao(L, l1, 5);
  l1 = CriarNo("Mateus", 2245310); InserirPorPosicao(L, l1, 6);
  l1 = CriarNo("Segredo do Universo", 42); InserirPorPosicao(L, l1, 7);

  Imprimir(L);


  no* ret_busca;

  // INSERINDO NOVO NÓ
  int buscar = 666;
  ret_busca = buscaMatricula(L, buscar);
  char string[] = "Terra";
  if(ret_busca != NULL){
    printf("\nEncontrado o aluno %s pelo número de matricula: %d\n", ret_busca->nome, ret_busca->matricula);
    printf("Inserindo %s antes desse número de matricula\n", string);
  }
  else{
    printf("\nNenhum aluno encontrado pelo número de matricula: %d\n", buscar);
    printf("Inserindo %s no final da lista\n", string);
  }
  l1 = CriarNo(string, 6429); InsereAntesNo(L, ret_busca, l1);
  Imprimir(L);


  // INSERINDO  NOVO NÓ NO FINAL DA LISTA
  buscar = 667;
  char string2[] = "Amoeba de Aço";
  ret_busca = buscaMatricula(L, buscar);
  if(ret_busca != NULL){
    printf("\nEncontrado o aluno %s pelo número de matricula: %d\n", ret_busca->nome, ret_busca->matricula);
    printf("Inserindo %s antes desse número de matricula\n", string2);
  }
  else {
    printf("\nNenhum aluno encontrado pelo número de matricula: %d\n", buscar);
    printf("Inserindo %s no final da lista\n", string2);
  }

  l1 = CriarNo(string2, 7316); InsereAntesNo(L, ret_busca, l1);
  Imprimir(L);

  return 0;
}
