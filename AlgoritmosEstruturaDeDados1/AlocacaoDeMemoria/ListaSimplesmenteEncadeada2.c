#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;


typedef struct{
  int chave;
  char produto[20];
  int unidade;
  float valor;
}REGISTRO;

typedef struct aux{
  REGISTRO reg;
  struct aux* prox;
}ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
  int quant;
  PONT inicio;
}ListaSE;

ListaSE* Definir(){
  ListaSE *L;
  L = (ListaSE*) malloc(sizeof(ListaSE));
  if(L != NULL){
    L->quant = 0;
    L->inicio = NULL;
    return L;
  }
  return NULL;
}

ELEMENTO* CriarReg(int chave, char *s, int i, float f){
  ELEMENTO* novo_produto;
  novo_produto = (ELEMENTO*) malloc(sizeof(ELEMENTO));
  novo_produto->reg.chave = chave;
  strcpy(novo_produto->reg.produto, s);
  novo_produto->reg.unidade = i;
  novo_produto->reg.valor = f;
  novo_produto->prox = NULL;
  return novo_produto;
}

booleano Inserir(ListaSE *L, ELEMENTO* novo_produto, int posicao){
  if(posicao < 0 || posicao > L->quant){
    return FALSE;
  }
  if (posicao == 0) {
    novo_produto->prox = L->inicio;
    L->inicio = novo_produto;
  }
  else{
    ELEMENTO* aux = L->inicio;
    int cont = 0;
    while (cont != posicao - 1) {
      aux = aux->prox;
      cont++;
    }
    novo_produto->prox = aux->prox;
    aux->prox = novo_produto;
  }
  L->quant++;
  return TRUE;
}

booleano Excluir(ListaSE *L, int posicao){
  PONT pos = L->inicio;
  if(L->quant <= 1 || posicao < 1 || posicao >= L->quant)
    return FALSE;
  while(pos != NULL && pos->reg.chave < posicao)
    pos = pos->prox;
  if(pos->reg.chave == posicao){
    free(pos);
  }
  return TRUE;
}


int tamanho(ListaSE *L){
  PONT end = L->inicio;
  int tam = 0;
  while (end != NULL) {
    tam++;
    end = end->prox;
  }
  return tam;
}

void Imprimir(ListaSE *L){
  PONT end = L->inicio;
  if(!L->quant == 0){
      printf("Lista:\n");
    for(int i = 0; i < L->quant; i++){
      printf("Chave:%i\nItem: %s\nQuantidade: %d\nPreço: %.2f\n\n", end->reg.chave, end->reg.produto, end->reg.unidade, end->reg.valor);
      end = end->prox;
    }
    printf("\n");
  }
  else printf("Lista Vazia!\n");
}

PONT buscaSeq(ListaSE *L, int chave){
  PONT pos = L->inicio;
  while (pos != NULL) {
    if(pos->reg.chave ==  chave) return pos;
    pos = pos->prox;
  }
  return NULL;
}


int main(){
  srand(time(0));

  ListaSE *L;
  L = Definir();
  Imprimir(L);

  ELEMENTO* reg1;
  reg1 = CriarReg(10, "Refrigerante", 5, 7);
  Inserir(L, reg1, 2);

  ELEMENTO* reg2;
  reg2 = CriarReg(20, "Queijo", 1, 3.85);
  Inserir(L, reg2, 1);

  ELEMENTO* reg3;
  reg3 = CriarReg(30, "Coca-Cola 2 litros", 2, 15);
  Inserir(L, reg3, 0);
  Imprimir(L);

  // PONT aux = buscaSeq(L, 30);


  return 0;
}
