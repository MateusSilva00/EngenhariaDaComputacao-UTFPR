#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem {
  int coluna;
  int valor;
  struct elem* prox;
}no;

typedef no* PONT;

typedef struct {
  int linhas;
  int colunas;
  int quant;
  PONT* A;
} MATRIZ;

// INICIALIZA A MATRIZ E SETA TODOS OS VALORES COMO NULOS
void criar_matriz(MATRIZ *m, int linhas , int colunas){
  m->quant = 0;
  m->linhas = linhas;
  m->colunas = colunas;
  m->A = (PONT*) malloc(linhas*sizeof(PONT));
  int i = 0;
  for(; i < linhas; i++) m->A[i] = NULL;
}

booleano set(MATRIZ *m, int i, int j, int value){
  //Verifica se existe a posição na matriz
  if(i < 0 || i >= m->linhas || j < 0 || j >= m->colunas)
    return FALSE;
  PONT anterior = NULL;
  PONT atual = m->A[i];

  while (atual != NULL && atual->coluna < j) {
    anterior = atual;
    atual = atual->prox;
  }

  if(atual != NULL && atual->coluna == j) {
    if(value == 0){ //se valor a ser inserido é zero, da free na posiçoes
      if(anterior == NULL){
        m->A[i] = atual->prox;
      }
      else{
        anterior->prox = atual->prox;
      }
      free(atual);
    } // se for diferente de zero, apenas insere o novo valor
    else atual->valor = value;
    m->quant++;
  }
  // Se não houver valor na posição a ser inserido
  else if(value != 0){
    PONT novo = (PONT) malloc(sizeof(no));
    novo->valor = value;
    novo->coluna = j;
    novo->prox = atual;
    if(anterior == NULL) m->A[i] = novo;
    else anterior->prox = novo;
    m->quant++;
  }
  return TRUE;
}

booleano remover(MATRIZ *m, int i, int j){
  //Verifica se existe a posição na matriz
  if(i < 0 || i >= m->linhas || j < 0 || j >= m->colunas)
    return FALSE;
  PONT anterior = NULL;
  PONT atual = m->A[i];
  while (atual != NULL && atual->coluna < j) {
    anterior = atual;
    atual = atual->prox;
  }

  // Verifica se existe algum valor na posição
  if(atual == NULL || atual->coluna != j){
    return FALSE;
  }

  if(anterior == NULL)
    m->A[i] = atual->prox;
  else anterior->prox = atual->prox;
  free(atual);
  m->quant--;
  return TRUE;
}

void showMatriz(MATRIZ* m, const char s){
  int i;
  printf("Matriz %c: %d X %d\n", s,m->linhas, m->colunas);
  for (i=0;i<m->linhas;i++){
    PONT atual = m->A[i];
    while (atual != NULL){
      printf("A[%d][%d] = %d\t", i+1, atual->coluna+1,atual->valor);
      atual = atual->prox;
    }
    printf("\n");
  }
}

// Utilizado para as funções de somar, subtrair e multiplicar
int obterElem(MATRIZ* m, int i, int j){
  if(i < 0 || i >= m->linhas || j < 0 || j >=m->colunas)
    return FALSE;
  PONT atual = m->A[i];
  while (atual != NULL && atual->coluna < j) {
    atual = atual->prox;
  }
  if(atual != NULL && atual->coluna == j)
    return atual->valor;
  return FALSE;
}

void sumMatriz(MATRIZ* A, MATRIZ* B){
  if(A->linhas != B->linhas || A->colunas != B->colunas){
    printf("Impossível somar matriz de ordem diferente!\n");
  }
  else {
    int nl = A->linhas;
    int nc = A->colunas;
    MATRIZ* Mc = (MATRIZ*)malloc(sizeof(MATRIZ));
    criar_matriz(Mc, nl, nc);
    // Criar nova matriz para armazenar os valores da soma
    int sum1, sum2;

    for(int i=0; i < nl; i++){
      for(int j=0; j < nc; j++){
        sum1 = obterElem(A, i, j);
        sum2 = obterElem(B, i, j);
        set(Mc, i, j, sum1+sum2);
      }
    }
    printf("\n\tSOMA DAS A E B MATRIZES\n");
    showMatriz(Mc, 'C');
  }
}

void subMatriz(MATRIZ* A, MATRIZ* B){
  if(A->linhas != B->linhas || A->colunas != B->colunas){
    printf("Impossível subtrair matriz de ordem diferente!\n");
  }
  else {
    int nl = A->linhas;
    int nc = A->colunas;
    MATRIZ* Mc = (MATRIZ*)malloc(sizeof(MATRIZ));
    criar_matriz(Mc, nl, nc);

    int sub1, sub2;

    for(int i=0; i < nl; i++){
      for(int j=0; j < nc; j++){
        sub1 = obterElem(A, i, j);
        sub2 = obterElem(B, i, j);
        set(Mc, i, j, sub1-sub2);
      }
    }
    printf("\n\tSUBTRAÇÃO DAS A E B MATRIZES\n");
    showMatriz(Mc, 'C');
  }
}

void multMatriz(MATRIZ* A, MATRIZ* B){
  if(A->colunas != B->linhas){
    printf("Impossível multiplicar essas matrizes!\nO número de colunas de A é diferente do número de linhas de B\n");
  }

  else {
    MATRIZ* Mc = (MATRIZ*)malloc(sizeof(MATRIZ));
    criar_matriz(Mc, A->linhas, B->colunas);

    int i, j, k, total;

    for(i=0; i < A->linhas; i++){
      for(j=0; j < B->colunas; j++){
        total = 0;
        for(k=0; k < A->colunas; k++){
          total += obterElem(A, i, k) * obterElem(B, k, j);
        }
        if(total){
          set(Mc, i, j, total);
        }
      }
    }

    printf("\n\tMULTIPLICAÇÃO DAS A E B MATRIZES\n");
    showMatriz(Mc, 'C');
  }
}
