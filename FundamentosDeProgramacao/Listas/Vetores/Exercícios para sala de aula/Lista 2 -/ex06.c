// Gerar um vetor de inteiros com 10 elementos aleatórios entre 1 e 200. Desse vetor, calcular e mostrar:
// a) A soma de elementos armazenados nesse vetor que são inferiores a 100;
// b) A quantidade de elementos armazenados nesse vetor que tem valor igual a 100;
// c) A média dos elementos armazenados nesse vetor que são superiores a 100. Validar para não realizar
// uma divisão por zero.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

int mostrarSomaMenorQ100(int vetor[], int tamanho);
int quantidadeIgual100(int vetor[], int tamanho);
float mediaMaiorQ100(int vetor[], int tamanho);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos = 10, limite = 200, vetor[elementos], soma, quantidade;
  float media;
  char ch;

  do {
    gerarVetorInteiros(vetor, elementos, limite);
    printf("=== VETOR A ===\n");
    mostrarVetorInteiros(vetor, elementos);

    soma = mostrarSomaMenorQ100(vetor, elementos);
    printf("\nSoma dos valores menores do que 100.: %d", soma);

    quantidade = quantidadeIgual100(vetor, elementos);
    printf("\nQuantidade valores igual(is) a 100.: %d", quantidade);

    media = mediaMaiorQ100(vetor, elementos);
    printf("\nMedia dos valores maiores do que 100.: %.2f", media);

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}

int mostrarSomaMenorQ100(int vetor[], int tamanho){
  int i, soma = 0;
  for(i=0; i<tamanho; i++){
    if(vetor[i] < 100){
      soma = soma + vetor[i];
    }
  }
  return soma;
}

int quantidadeIgual100(int vetor[], int tamanho){
  int i, quantidade=0;
  for(i=0; i<tamanho; i++){
    if(vetor[i] ==  100){
      quantidade++;
    }
  }
  return quantidade;
}

float mediaMaiorQ100(int vetor[], int tamanho){
  int i, qt = 0;
  float media = 0;
  for(i=0; i<tamanho; i++){
    if(vetor[i] < 100){
      qt++;
      media = media + vetor[i];
    }
  }

  if(qt > 0){
    media = media / qt;
    return media;
  }
  else{
    return 0;
  }

}
