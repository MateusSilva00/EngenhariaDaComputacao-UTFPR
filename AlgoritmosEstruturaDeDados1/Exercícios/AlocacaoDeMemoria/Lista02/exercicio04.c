// 4. Crie uma estrutura de dados para armazenar os N pontos (x,y) de um polígono. Implemente
// funções para:
// o Inicializar a estrutura;
// o Inserir pontos;
// o Calcular o perímetro do polígono.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
  int pX;
  int pY;
  int perimetro;
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

booleano ListaVazia(ListaSE *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

no* CriarNo(int x, int y){
  no* novo = (no*) malloc(sizeof(no));
  novo->pX = x;
  novo->pY = y;
  novo->perimetro = 2*(x+y);
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

void ImprimirPos(ListaSE *L, int i){
  no* aux = L->inicio;
  if(!L->quant == 0){
    for(int j = 0; j < i; j++){
      aux = aux->prox;
    }
    printf("\nP(%d,%d) - Perímetro %d", aux->pX, aux->pY, aux->perimetro);
  }
}

void Imprimir(ListaSE *L){
  no* aux;
  aux = L->inicio;
  printf("\n\n=== Lista Completa ===\n");
  if(!L->quant == 0){
    for(int i=0; i < L->quant; i++){
      printf("\nP(%d,%d) - Perímetro %d", aux->pX, aux->pY, aux->perimetro);
      aux = aux->prox;
    }
  }
  else printf("Lista vazia!\n");
}


int main(){

  ListaSE *L;
  L = Definir();

  int opt, x, y;
  do {
    int i = 0;
    printf("\nInsira o valor de x: ");
    scanf("%d", &x);
    printf("Insira o valor de y: ");
    scanf("%d", &y);
    no* n1 = CriarNo(x, y);
    Inserir(L, n1, 0);
    ImprimirPos(L, i);
    i++;
    printf("\nDeseja continuar ? - 0 para sair: ");
    scanf("%d", &opt);
  } while(opt != 0);

  Imprimir(L);

  return 0;
}
