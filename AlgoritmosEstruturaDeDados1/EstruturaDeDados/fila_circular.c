#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct{
  char id;
} elem;

typedef struct{
  int nelem;
  int inicio;
  int fim;
  elem A[MAX];
}FilaCirc;

void Definir(FilaCirc *F){
  F->nelem=0;
  F->inicio=0;
  F->fim=0;
}

int Fila_vazia(FilaCirc *F){
  if(F->nelem == 0)
    return 1;
  return 0;
}

void lista_elementos(FilaCirc *F){
  int i;

  i = F->inicio;
  printf("\nLISTA DE ELEMENTOS\n");
  if(!Fila_vazia(F)){
    do {
      printf("%c, ", F->A[i]);
      i++;
      if(i==MAX){
        i=0;
      }
    } while(i != F->fim);
  }
}

int Fila_cheia(FilaCirc *F){
  if(F->nelem  == MAX)
    return 1;
  return 0;
}

int Enfila(elem* x, FilaCirc *F){
  // int atual;
  if(Fila_cheia(F))
    return 0;
  else{
    F->A[F->fim] = *x;
    F->nelem++;
    if(F->fim == MAX)
      F->fim=0;
    return 1;
  }
}

int Desenfila(FilaCirc *F){
  if(Fila_vazia(F))
    return 0;
  else{
    F->inicio++;
    if(F->inicio == MAX){
      F->inicio=0;
    }
    F->nelem--;
    return 1;
  }
}

int main(){

  srand(time(0));

  FilaCirc F;
  Definir(&F);

  int i, aux;
  elem novo;
  for(i=1; i <= 10; i++){
    if(i%3 != 0){
      novo.id = 64+i;
      aux = Enfila(&novo, &F);
      if(aux){
        printf("\nEnfilado com sucesso!");
        // lista_elementos(&F);
      }
      else printf("\nEnfila não funcionou!");
    }
    else {
      aux = Desenfila(&F);
      if(aux)
        printf("\nDesenfila com sucesso!");
      else printf("\nDesenfila sem sucesso!");
    }
  }

  lista_elementos(&F);

  return 0;
}
