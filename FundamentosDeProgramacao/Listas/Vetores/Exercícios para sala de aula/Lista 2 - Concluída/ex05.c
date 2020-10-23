// Gerar vetores A e B, sendo A com n elementos aleatórios entre 1 e 20 e B com n elementos aleatórios
// entre 1 e 15. O usuário informa a quantidade de elementos dos vetores, ou seja, o seu tamanho. Validar para
// que seja informado um valor positivo para a quantidade de elementos. Mostrar os elementos dos vetores A eB. Construir um vetor C, em que cada elemento de C será 1 quando o elemento de A for maior que o
// respectivo elemento em B; será 0 quando o elemento de A for igual ao respectivo elemento em B; e será -1
// quando o elemento de A for menor que o respectivo elemento em B. Mostrar os elementos do vetor C.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void compareVetor(int vetorA[], int tamanhoA, int vetorB[], int tamanhoB);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int tamanhoA,  tamanhoB;
  char ch;

  do {
    do {
      printf("Informe o tamanho do vetor A.: ");
      scanf("%d", &tamanhoA);
      if (tamanhoA <= 0){
        printf("Informe um valor positivo!\n");
      }
      else{
        int vetA[tamanhoA];
        do {
          printf("Informe o tamanho do vetor B.: ");
          scanf("%d", &tamanhoB);
          if(tamanhoB <= 0){
            printf("Informe um valor positivo!\n");
          }
          else{
            int vetB[tamanhoB];
            printf("\n=== VETOR A ===\n");
            gerarVetorInteiros(vetA, tamanhoA, 20);
            mostrarVetorInteiros(vetA, tamanhoA);

            printf("\n\n=== VETOR B ===\n");
            gerarVetorInteiros(vetB, tamanhoB, 15);
            mostrarVetorInteiros(vetB, tamanhoB);
            printf("\n\n=== VETOR C ===\n");
            compareVetor(vetA, tamanhoA, vetB, tamanhoB);

          }
        } while(tamanhoB <= 0);
      }
    } while(tamanhoA <= 0);

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');

  return 0;
}

void compareVetor(int vetorA[], int tamanhoA, int vetorB[], int tamanhoB){
  int maior, i;
  if(tamanhoB >= tamanhoA){
    maior = tamanhoB;
  }
  else{
    maior = tamanhoA;
  }
  for(i=0; i<maior; i++){
    if(vetorA[i] > vetorB[i]){
      printf("1 ");
    }
    else if(vetorA[i] == vetorB[i]){
      printf("0 ");
    }
    else if(vetorA[i] < vetorB[i]){
      printf("-1 ");
    }
  }
}
