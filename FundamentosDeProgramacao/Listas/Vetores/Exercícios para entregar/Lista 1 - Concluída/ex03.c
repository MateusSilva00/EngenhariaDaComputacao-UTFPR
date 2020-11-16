#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){

  srand(time(0));
  char ch;
  do {
    int i, j, vetA[50], countPar = 0, countImpar = 0;
    printf("=== VETOR ===\n");
    for(i = 1; i <= 50; i++){
      vetA[i] = (rand() % 100) + 1;
      printf("%d ", vetA[i]);
      if(vetA[i] % 2 == 0){
        countPar++;
      }
      else{
        countImpar++;
      }
    }

    j=1; i = 1;
    printf("\n\n=== PARES ===\n");
    do {
      if(vetA[i] % 2 == 0){
        printf("%d ", vetA[i]);
        j++;
      }
      i++;
    } while(j <= countPar);

    i=1; j=1;
    printf("\n\n=== IMPARES ===\n");
    do {
      if(vetA[i] % 2 != 0){
        printf("%d ", vetA[i]);
        j++;
      }
      i++;
    } while(j <= countImpar);


    printf("\n\nDeseja repetir o programa (S/N).: ");
    scanf(" %c", &ch);
  } while(toupper(ch) == 'S');

  return 0;
}
