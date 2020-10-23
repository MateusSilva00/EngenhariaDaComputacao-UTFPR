#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

void verificarVetor(int vetorA[], int vetorB[], int tamanho){
  int i, k=0;
  for(i=0; i<tamanho; i++){
    if(vetorA[i] != 0){
      vetorB[k] = vetorA[i];
      k++;
    }
  }
  for(i=0; i<k;i ++){
    printf("%d ", vetorB[i]);
  }
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos=30, a[elementos], b[elementos];
  char ch;
    do {

      gerarVetorInteiroComLimite(a,elementos,0,100);
      printf("=== VETOR A ===\n");
      mostrarVetorInteiros(a, elementos);
      printf("\n=== VETOR B ===\n");
      verificarVetor(a, b, elementos);


      printf("\n\nDeseja continuar o programa (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}
