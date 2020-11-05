#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void numPerfeito(int num);
int somaDigitos(int num);

int main(){

  srand(time(0));
  int vetor[10];
  char ch;

  do {
    printf("\n=== VETOR === \n");
    for(int i = 0; i<=9; i++){
      vetor[i] = (rand () % 100) + 1;
      printf("%d ", vetor[i]);
    }

    printf("\n\n=== PARES === \n");
    for(int i = 0; i<=9; i++){
      if(vetor[i] % 2 == 0){
        printf("%d", vetor[i]);
        numPerfeito(vetor[i]);
      }
    }

    printf("\n=== IMPARES === \n");
    for(int i = 0; i<=9; i++){
      if(vetor[i] % 2 != 0){
        printf("%d - Soma dos Digitos.: %d\n", vetor[i], somaDigitos(vetor[i]));
      }
    }

    printf("\nDeseja continuar no programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');

  return 0;
}

void numPerfeito(int num){
  int i = 1, somaDiv = 0;
  for(i; i < num; i++){
    if(num % i == 0){
      somaDiv = somaDiv + i;
    }
  }

  if(somaDiv == num){
    printf(" eh perfeito\n");
  }
  else{
    printf(" nao eh perfeito\n");
  }
}

int somaDigitos(int num){
  int dezena, unidade, soma;
  dezena = num / 10;
  unidade = num % 10;
  soma = dezena + unidade;
  return soma;
}
