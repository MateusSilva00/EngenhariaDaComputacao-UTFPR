// 2. (2,0) Crie uma função recursiva capaz de esvaziar uma fila de números inteiros. Antes de
// desenfileirar, imprima o valor do elemento que está sendo retirado.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6

typedef struct{
  int id;
}elem;

typedef struct{
  int nelem;
  int inicio;
  int fim;
  elem A[MAX];
}fila;

void definir(fila *f){
  f->nelem = 0;
  f->inicio = 0;
  f->fim = 0;
}

int filaVazia(fila *f){
  if(f->nelem == 0)
    return 1;
  else return 0;
}

int filaCheia(fila *f){
  if(f->nelem == MAX)
    return 1;
  else return 0;
}

int enfila(elem *x, fila *f){
  if(!filaCheia(f)){
    f->A[f->fim] = *x;
    f->nelem++;
    f->fim++;
    return 1;
  }
  else return 0;
}

void imprime(fila *f){
  int i = f->inicio;
  if(!filaVazia(f)){
    do {
      printf("[%d]  ", f->A[i]);
      i++;
    } while(i != f->fim);
  }
}

void esvaziarFila(fila *f, elem *x, int i){
  if(!filaVazia(f)){
    i = f->nelem;
    if(f->nelem > 0){
      int j = f->inicio;
      printf("\n\nApagando [%d]\n", f->A[j]);
      imprime(f);
      f->inicio++;
      f->nelem--;
      esvaziarFila(f,x, i);
    }
  }
}

int main(){

  srand(time(0));

  elem novo;
  fila f;
  definir(&f);


  int i, aux;
  for(i=0; i < MAX; i++){
    novo.id = rand() % 100 + 1;
    aux = enfila(&novo, &f);
    if(aux){
      printf("[%d] enfilado com sucesso!\n", novo.id);
    }
    else printf("enfila não funcionou!\n");
  }

  printf("\n===  FILA GERADA ===\n");
  imprime(&f);

  esvaziarFila(&f, 0, 0);

  aux = filaVazia(&f);
  if(aux){
    printf("\n\tFILA APAGADA COM SUCESSO \n");
  }
  else printf("\nFila não foi totalmente apagada!\n");


  return 0;
}
