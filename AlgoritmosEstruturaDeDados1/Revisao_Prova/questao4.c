// A função recursiva abaixo recebe 3 parâmetros: o índice do elemento mais a esquerda (normalmente zero), o índice do e
// elemento mais a direita (normalmente número de elementos do vetor menos um) e um vetor de inteiros. Qual é o valor
// retornado? Cria um main para testar esta função e escreva como comentário qual a sua finalidade
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f(int e, int d, int v[]){
  if(e == d) return v[d];
  else{
    int m, x, y;
    m = (e+d) / 2;
    x = f(e, m, v);
    y = f(m+1, d, v);
    if(x >= y ) return x;
    else return y;
  }
}

int main(){
  srand(time(0));

  int size=6, arr[size], i, retFunc;
  for(i=0; i < size; i++){
    arr[i] = rand() % 150;
    printf("[%d] ", arr[i]);
  }

  retFunc = f(0, size-1, arr);
  printf("\nValor retornado: %d", retFunc);

  return 0;
}
