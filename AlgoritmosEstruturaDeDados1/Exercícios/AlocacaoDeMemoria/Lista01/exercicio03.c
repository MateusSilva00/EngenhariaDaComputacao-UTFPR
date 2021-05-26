// 3) Um supermercado possui 3 caixas, os quais podem ter filas de no máximo 3 clientes (o
// que está sendo atendido mais 2). Além desses, todos demais clientes devem formar uma
// única fila (veja figura abaixo). A medida que um dos caixas libera um cliente, o primeiro da
// "fila do povão" é encaminhado para uma das filas específicas. Simule o funcionamento
// destas filas computacionalmente. A liberação dos clientes deve ser feita de forma aleatória
// (sorteio de 1 a 3, por exemplo).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct elem{
  int id;
  char nome[20];
  struct elem* prox;
}no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}Fila;

Fila* CriarFila(){
    Fila* F = (Fila*) malloc(sizeof(Fila));
    F->quant = 0;
    F->inicio = NULL;
    F->fim = NULL;
    return F;
}

no* CriarNo(int pos){
  no* novo = (no*) malloc(sizeof(no));
  novo->id = pos;
  novo->nome[0] = (char)(rand()%26+97);
  novo->nome[1] = '\0';
  novo->prox = NULL;
  return novo;
}

void ImprimirFila(Fila *F){
  no *aux = F->inicio;
  if(aux == NULL)
    printf("\nFila Vázia!\n");
  while (aux != NULL) {
    printf("\nNome: %s\n", aux->nome);
    printf("ID: %d", aux->id);
    aux = aux->prox;
  }
}

void Inserir(Fila *F, no* aux){
  if(F->quant == 0)
    F->inicio = aux;
  else
    F->fim->prox = aux;
  F->fim = aux;
  F->quant++;
}

int Remover(Fila *F){
  if(F->quant == 0)
    return 0;
  no* aux = F->inicio;
  F->inicio = F->inicio->prox;
  free(aux);
  F->quant--;
  return 1;
}

int main(){

  srand(time(0));

  Fila *F = CriarFila();

  int i;
  for(i=0; i < 15; i++){
    no* aux = CriarNo(i);
    Inserir(F, aux);
  }

  Fila *c1 = CriarFila();
  Fila *c2 = CriarFila();
  Fila *c3 = CriarFila();

  int sorteio;
  Fila *caixa;

  while (F->quant != 0 || c1->quant !=0 || c2->quant != 0 || c3->quant != 0) {
    sorteio = rand()% 3 + 1;
    switch (sorteio) {
      case 1:
        caixa = c1;
        break;
      case 2:
        caixa = c2;
        break;
      case 3:
        caixa = c3;
        break;
    }

    if(c1->quant == 3 || c2->quant == 3 || c3->quant == 3){
      if(c1->quant == 3){
        Remover(c1);
      }
      if(c2->quant == 3){
        Remover(c2);
      }
      else Remover(c3);
    }

    if(F->quant != 0){
      Inserir(caixa, F->inicio);
      Remover(F);
    }

    printf("\nFila = %d\n", F->quant);
    printf("c1 = %d\n", c1->quant);
    printf("c2 = %d\n", c2->quant);
    printf("c3 = %d\n", c3->quant);
    printf("=====================");
  }
  ImprimirFila(F);

  return 0;
}
