#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
#include "ordenacao_vetor.h"
#include <ctype.h>

void mostrarPar(int num);
int contaPar(int num);

int main(){
  int vetA[20], i;
  char ch;

  do {
    printf("=== VETOR ORIGINAL ===\n");
    GerarVetorInteiroComFaixa(vetA, 20, 5, 20);
    mostrarVetorInteiros(vetA, 20);
    printf("\n\n=== VETOR ORDENADO ===\n");
    bubbleSort(vetA, 20);
    mostrarVetorInteiros(vetA, 20);

    printf("\n\n=== PARES ===\n");
    for(i=0; i<20; i++){
      if(i==0 || vetA[i] != vetA[i-1]){
        printf("%d ==> ", vetA[i]);
        mostrarPar(vetA[i]);
        printf("Soma = %d\n", contaPar(vetA[i]));
      }
    }

    printf("\n\nDeseja repetir o programa S ou N? ");
    scanf(" %c", &ch);
    ch = toupper(ch);



  } while(ch == 'S');

  return 0;
}


void mostrarPar(int num)
{
    int i;

    for(i=1; i<=num; i++)
    {
        if(i%2 == 0)
        {
            printf("%d  ", i);
        }
    }
}

int contaPar(int num)
{
    int i, soma=0;

    for(i=1; i<=num; i++)
    {
        if(i%2 == 0)
        {
           soma = soma + i;
        }
    }
    return(soma);
}
