// Tarefa: implementar a E.D. do tipo matriz esparsa utilizando listas cruzadas. Devem ser implementadas, no mínimo, as
// funções de inserir e remover nós da matriz, e também as operações de somar, subtrair e multiplicar duas matrizes.
// Regras de implementação: linguagem C, em dupla ou individual.
// Data de apresentação: 18 ou 20/05/2021, horário de aula
// Regras de avaliação:
// - 0,5 para funções de inserir e remover devidamente explicadas;
// - 0,5 para funções de soma e subtração devidamente explicadas;
// - 0,5 para função de multiplicação devidamente explicada.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"


int main(){

  srand(time(0));

  MATRIZ Ma;

  int tam = 4;

  criar_matriz(&Ma, tam, tam);
  printf("========================================================\n");
  int a, b, c;
  for(int i=0; i < 4; i++){
    scanf("%d %d %d", &a, &b, &c);
    set(&Ma, a,b,c);
  }
  showMatriz(&Ma, 'A');
  printf("========================================================\n");


  MATRIZ Mb;
  criar_matriz(&Mb, tam, tam);
  for(int i=0; i < 4; i++){
    scanf("%d %d %d", &a, &b, &c);
    set(&Mb, a, b, c);
  }
  showMatriz(&Mb, 'B');
  printf("========================================================\n");



  sumMatriz(&Ma, &Mb);
  printf("========================================================\n");

  subMatriz(&Ma, &Mb);
  printf("========================================================\n");

  multMatriz(&Ma, &Mb);
  printf("========================================================\n");

  printf("Removendo o valor da linha 1 e coluna 3\n");
  remover(&Ma, 0, 2);
  showMatriz(&Ma, 'A');

  return 0;
}
