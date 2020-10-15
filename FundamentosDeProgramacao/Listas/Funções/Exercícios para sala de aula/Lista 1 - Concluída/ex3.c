#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include "Fatorial.h"

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num, i;
  char opcao, ch;
  do {
    do {
      printf("A - Fatorial entre 1 e 8\nB - Fatorial de um número\nOpção.: ");
      scanf(" %c", &opcao);
      opcao = toupper(opcao);
      switch (opcao) {
        case 'A':
        for(i=1; i<=8; i++){
          mostraFatorial(i);
          printf("%d\n", calcFatorial(i));
        }
        break;

        case 'B':
        printf("Informe um número.: ");
        scanf("%d", &num);
        mostraFatorial(num);
        printf("%d\n", calcFatorial(num));
        break;

        default:
        printf("Opção Inválida!\n");
      }

      printf("\n\nExecutar novamente (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);
    } while(ch == 'S');

  } while(num > 0);

  return 0;
}
