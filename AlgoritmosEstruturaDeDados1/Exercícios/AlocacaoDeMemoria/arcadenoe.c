// Um dilúvio está a caminho, e você foi encarregado de ser o porteiro da arca de Noé versão 2.0. Toda vez que um animal entrar na
// arca, você deve cadastrá-lo em uma lista. Entretanto, Noé já está consciente que a arca moderna não vai aguentar todos os animais
// (a madeira hoje em dia é de péssima qualidade). Sendo assim, além do cadastro, você conseguir descobrir facilmente qual é o
// animal mais pesado e também o mais leve, para que estes sejam jogados na água sempre que for necessário aliviar o peso
// (o novo Noé não deve processado por bullying com os gordinhos)
// a. Implemente o cadastro destes animais através de uma lista encadeada. Todos os nós devem conter a espécie de um animal
// e seu peso. Além do ponteiro de inicio, sua lista deve ter sempre atualizados 2 ponteiros para, respectivamente, o animal
// mais leve e o animal mais pesado.
// b. Crie uma função DiminuirOcupacao que remove da lista os animais mais leve e mais pesado. Imprima a espécie destes
// animais e atualize os ponteiros
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
  char especie[30];
  float peso;
  struct elem* prox;
  struct elem*ant;
}no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
  no* pesado;
  no* leve;
} ListaDE;

ListaDE* Definir(){
  ListaDE *L = (ListaDE*) malloc(sizeof(ListaDE));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  L->pesado = NULL;
  L->leve = NULL;
  return L;
}

no* CriarNo(const char *s, float f){
  no* novo = (no*) malloc(sizeof(no));
  strcpy(novo->especie, s);
  novo->peso = f;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

booleano InserirUnico(ListaDE *L, no* novo){
  if (L->quant != 0){
      return FALSE;
  } else {
      L->inicio = novo;
      L->fim = novo;
      L->quant = 1;
      L->pesado = novo;
      L->leve = novo;
      return TRUE;
  }
}

void verificaPeso(ListaDE *L){
  no* aux = L->inicio;

  while (aux != NULL) {
    if(L->pesado->peso < aux->peso){
      L->pesado = aux;
    }
    if(L->leve->peso > aux->peso){
      L->leve = aux;
    }
    aux = aux->prox;
  }
}

void Inserir(ListaDE *L, no* novo){
  if(L->quant == 0){
    InserirUnico(L, novo);
    // return TRUE;
  }
  else {
    L->fim->prox = novo;
    novo->ant = L->fim;
    L->fim = novo;
    L->quant++;
    verificaPeso(L);
    // return TRUE;
  }
}

void Imprimir(ListaDE *L){
  no* aux;
  aux = L->inicio;
  printf("\n=== ANIMAIS DA ARCA ===\n");
  if(!L->quant == 0){
    for(int i=0; i < L->quant; i++){
      printf("|%s | %.2fKgs|\n", aux->especie, aux->peso);
      aux = aux->prox;
    }
  }
  else printf("Lista vazia!\n");
}

void DiminuirOcupacao(ListaDE* L) {
  no *aux;

  if(L->pesado == L->inicio){
    aux = L->pesado;
    L->inicio->ant = NULL;
    printf("\nExpurgando %s - %.2fKgs", L->pesado->especie, L->pesado->peso);
    L->quant--;
    free(aux);
    verificaPeso(L);
  }

  else if(L->pesado == L->fim){
    aux = L->pesado;
    L->fim = L->fim->ant;
    L->fim->prox = NULL;
    printf("\nExpurgando %s - %.2fKgs", L->pesado->especie, L->pesado->peso);
    L->quant--;
    free(aux);
    verificaPeso(L);
  }

  else {
    aux = L->pesado;
    aux->ant->prox = aux->prox;
    printf("\nExpurgando %s - %.2fKgs", L->pesado->especie, L->pesado->peso);
    L->quant--;
    free(aux);
    verificaPeso(L);
  }

  if(L->leve == L->fim){
    aux = L->leve;
    L->fim = aux->ant;
    L->fim->prox = NULL;
    printf("\nExpurgando %s - %.2fKgs", L->leve->especie, L->leve->peso);
    L->quant--;
    free(aux);
    verificaPeso(L);
  }

  else if(L->leve == L->inicio){
    aux = L->leve;
    L->inicio = aux->prox;
    L->inicio->ant = NULL;
    printf("\nExpurgando %s - %.2fKgs", L->leve->especie, L->leve->peso);
    L->quant--;
    free(aux);
    verificaPeso(L);
  }

  else {
    aux = L->leve;
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    printf("\nExpurgando %s - %.2fKgs", L->leve->especie, L->leve->peso);
    free(aux);
    verificaPeso(L);
  }

}


int main(){

  ListaDE *L;
  L = Definir();

  no* n1;

  n1 = CriarNo("Asno selvagem africano", 76.30); Inserir(L, n1);
  n1 = CriarNo("Foca monge do Havaí", 84); Inserir(L, n1);
  n1 = CriarNo("Lobo vermelho", 51); Inserir(L, n1);
  n1 = CriarNo("Elefante asiático", 1300); Inserir(L, n1);
  n1 = CriarNo("Tigre de bengala", 210); Inserir(L, n1);
  n1 = CriarNo("Atum azul", 160); Inserir(L, n1);
  n1 = CriarNo("Lince ibérico", 98); Inserir(L, n1);
  n1 = CriarNo("Diabo da tasmânia", 28); Inserir(L, n1);
  n1 = CriarNo("Kakapo", 25); Inserir(L, n1);
  n1 = CriarNo("Gorila das montanhas", 348.80); Inserir(L, n1);

  Imprimir(L);

  printf("\nAnimal mais pesado: %s - %.2fKgs\nAnimal mais leve: %s - %.2fKgs\n\n", L->pesado->especie, L->pesado->peso, L->leve->especie, L->leve->peso);
  DiminuirOcupacao(L);
  Imprimir(L);

  return 0;
}
