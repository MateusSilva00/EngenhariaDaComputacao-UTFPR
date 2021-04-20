// 1. (3,5) Implemente a estrutura de dados do tipo DEQUE de forma circular. Maiores
// detalhes:
// a) O nome DEQUE vem do inglês Double Ended Queue, que normalmente é traduzido
// como Fila duplamente terminada.
// b) A estrutura do tipo DEQUE é uma estrutura de dados na qual os elementos podem
// ser tanto inseridos quanto excluídos de qualquer uma de suas extremidades (do
// início/esquerda ou do fim/direita).
// c) Sua implementação deve conter as definições de tipo e, no mínimo, as seguintes
// funções: definir, inserir à direita, inserir à esquerda, remover à direita, remover à
// esquerda e imprimir (do início/esquerda até o fim/direita).
// d) Repito: a implementação deve ser circular, ou seja, as duas funções de inserir
// devem ser capazes de ocupar a outra extremidade do vetor, caso seja necessário e
// caso existam espaços vagos.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct{
  char id;
}elem;

typedef struct{
  int nelem;
  int inicio;
  int fim;
  elem A[MAX];
}FilaCirc;

void Definir(FilaCirc *f){
  f->nelem = 0;
  f->inicio = 0;
  f->fim = 0;
}

int filaCheia(FilaCirc *f){
  if(f->nelem == MAX)
    return 1;
  else return 0;
}

int filaVazia(FilaCirc *f){
  if(f->nelem == 0)
    return 1;
  else return 0;
}

int enfila_esquerda(elem *x, FilaCirc *f){
  if(!filaCheia(f)){
    f->nelem++;
    f->fim++;
    for(int i=f->nelem; i >= 0; i--){
      if(i != 0){
        f->A[i] = f->A[i-1];
      }
      else{
        f->A[i] = *x;
      }
    }

    if(f->fim == MAX)
      f->fim = 0;
    return 1;
  }
  else return 0;
}

int enfila_direita(elem *x, FilaCirc *f){
  if(!filaCheia(f)){
    f->nelem++;
    f->A[f->fim] = *x;
    f->fim++;
    if(f->fim == MAX)
      f->fim = 0;
    return 1;
  }
  else return 0;
}

int desenfila_esquerda(FilaCirc *f){
  if(!filaVazia(f)){
    f->inicio++;
    if(f->inicio == MAX)
      f->inicio = 0;
    f->nelem--;
    return 1;
  }
  else return 0;
}

int desenfila_direita(FilaCirc *f){
  if(!filaVazia(f)){
    f->fim--;
    if(f->fim == f->inicio)
      f->fim = 0;
    f->nelem--;

    return 1;
  }
  else return 0;
}

void imprime(FilaCirc *f){
  int i = f->inicio;
  if(!filaVazia(f)){
    do {
      printf("[%d] ", f->A[i]);
      i++;
      if(i == MAX) i = 0;
    } while(i != f-> fim);
  }
  printf("\n");
}

int main(){

  srand(time(0));
  FilaCirc f;
  Definir(&f);

  int i, aux;
  elem novo;

  for(i=0; i < MAX; i++){
    novo.id = rand() % 100 + 1;
    if(i % 2 == 0){
      aux = enfila_esquerda(&novo, &f);
      if(aux){
        printf("[%d] Enfilado na esquerda com sucesso!\n", novo.id);
        imprime(&f);
      }
      else printf("Enfilar não funcionou!\n");
    }
    else{
      aux = enfila_direita(&novo, &f);
      if(aux){
        printf("[%d] Enfilado na direita com sucesso!\n", novo.id);
        imprime(&f);
      }
      else printf("Enfilar não funcionou!\n");
    }
  }

  printf("\n=== PILHA APOS INSERCOES===\n");
  imprime(&f);
  printf("\n");

  for(i=0; i < MAX; i++){
    if(i < 10){
      aux = desenfila_esquerda(&f);
      if(aux){
        printf("Desenfilado na esquerda com sucesso!\n");
        imprime(&f);
      }
      else printf("Desenfilar não funcionou!\n");
    }

    else{
      aux = desenfila_direita(&f);
      if(aux){
        printf("Desenfilado na direita com sucesso!\n");
        imprime(&f);
      }
      else printf("Desenfilar não funcionou!\n");
    }

  }

  return 0;
}
