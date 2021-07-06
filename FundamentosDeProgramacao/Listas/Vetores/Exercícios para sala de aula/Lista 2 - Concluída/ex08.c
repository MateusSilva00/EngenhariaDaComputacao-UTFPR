// Gerar aleatoriamente um vetor com 100 elementos que conterá somente valores 0 ou 1. Mostrar esse vetor. Em
// seguida contar quantos 0s sucessivos o vetor contém, armazenar essa quantidade em outro vetor e mostrá-lo.
// Qual seria o tamanho mínimo e máximo desse vetor que armazena as quantidades? Criá-lo para o tamanho
// máximo possível.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void continuidadeDeZeros(int vetor[], int tamanho);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos = 100, menor, maior, quantidadeDias, vetor[elementos];
  char ch;
    do {
      gerarVetorInteiroComLimite(vetor, elementos, 0, 2);
      printf("=== VETOR A ===\n");
      mostrarVetorInteiros(vetor, elementos);
      printf("\n=== VETOR B ===\n");
      continuidadeDeZeros(vetor, elementos);


      printf("\n\nDeseja continuar o programa (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}

void continuidadeDeZeros(int vetor[], int tamanho){
  int i, continuidade = 1;

  for(i=0; i<tamanho; i++){
    if(vetor[i] == 0){
      if(vetor[i] == 0 & vetor[i+1] == 0){
        continuidade++;
      }
      else{
        printf("%d ", continuidade);
        continuidade=1;
      }
    }
  }
}
