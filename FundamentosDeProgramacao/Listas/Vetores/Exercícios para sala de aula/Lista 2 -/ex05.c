// Gerar vetores A e B, sendo A com n elementos aleatórios entre 1 e 20 e B com n elementos aleatórios
// entre 1 e 15. O usuário informa a quantidade de elementos dos vetores, ou seja, o seu tamanho. Validar para
// que seja informado um valor positivo para a quantidade de elementos. Mostrar os elementos dos vetores A eB. Construir um vetor C, em que cada elemento de C será 1 quando o elemento de A for maior que o
// respectivo elemento em B; será 0 quando o elemento de A for igual ao respectivo elemento em B; e será -1
// quando o elemento de A for menor que o respectivo elemento em B. Mostrar os elementos do vetor C.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void comparaVetor(int vetorA[], int tamanhoA, int vetorB[], int tamanhoB);

int main(){
  setlocale(LC_ALL,"Portuguese");
  
  int tamanhoA, tamanhoB, vetA[tamanhoA], vetB[tamanhoB];
  char ch;

  do {
    printf("Informe o tamanho do vetor A.: ");
    scanf("%d", &tamanhoA);
    printf("Informe o tamanho do vetor B.: ");
    scanf("%d", &tamanhoB);
    printf("\n=== VETOR A ===\n");
    gerarVetorInteiros(vetA, tamanhoA, 20);
    mostrarVetorInteiros(vetA, tamanhoA);
    printf("\n=== VETOR B ===\n");
    gerarVetorInteiros(vetB, tamanhoB, 15);
    mostrarVetorInteiros(vetB, tamanhoB);
    printf("\n=== VETOR C ===\n");
    comparaVetor(vetA, tamanhoA, vetB, tamanhoB);

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}

void comparaVetor(int vetorA[], int tamanhoA, int vetorB[], int tamanhoB){
  int maior, i;
  if(tamanhoA >= tamanhoB){
    maior = tamanhoA;
  }
  else{
    maior = tamanhoB;
  }

  for(i=0; i<maior; i++){
    if(vetorA[i] > vetorB[i]){
      printf("1    ");
    }
    if(vetorA[i] == vetorB[i]){
      printf("0    ");
    }
    if(vetorA[i] < vetorB[i]){
      printf("-1    ");
    }
  }
}
