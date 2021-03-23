#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int verificaPrimo(int num);

int main(){

  srand(time(0));
  int vetor[10], k, primos[10], i;
  char ch;

  do {
    k = 0;
    printf("\n=== VETOR === \n");
    for(i = 0; i<=9; i++){
      vetor[i] = (rand () % 45) + 6;
      printf("%d ", vetor[i]);
    }

    for(i = 0; i<=9; i++){
      if(verificaPrimo(vetor[i]) == 1){
        printf("%d eh primo", vetor[i]);
        primos[k] = vetor[i];
        k++;
      }
      else{
        printf("%d nao eh primo", vetor[i]);
      }
    }

    printf("\n\n=== PRIMOS ===\n");
    for(i=0; i < k; i++){
      printf("%d\t", primos[i]);
    }

    printf("\nDeseja continuar no programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');

  return 0;
}

int verificaPrimo(int num){
  int i = 2;
  printf("\n");
  if(num == 1){
    return 0;
  }

  for(i; i <= num/2; i++){
    if(num % i == 0 || num == 1){
      return 0;
      break;
    }
  }
  return 1;
}
