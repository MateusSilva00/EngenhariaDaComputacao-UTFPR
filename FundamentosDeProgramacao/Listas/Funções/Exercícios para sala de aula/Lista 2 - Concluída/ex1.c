#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include "Fatorial.h"

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num;
  char ch;
  do {
    printf("Informe um número.: ");
    scanf("%d", &num);
    mostraFatorial(num);
    printf(" %d", calcFatorial(num));

    printf("\n\n=== Fatorial de 1 a 12 ===\n");
    for(int i=1; i<=12; i++){
      mostraFatorial(i);
      printf(" %d \n", calcFatorial(i));
    }

    printf("\n\nDeseja continuar no programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');

  return 0;
}
