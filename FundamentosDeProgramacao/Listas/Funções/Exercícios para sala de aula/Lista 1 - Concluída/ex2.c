#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include "Primo.h"

int main(){

  int num, countmedia = 0;
  float media = 0;
  char opcao, ch;

  do {
    printf("A - Verificar se um número é primo\nB - Primos entre 1 e 100\nC - Media dos primos entre 200 e 100\nOpção.: ");
    scanf(" %c", &opcao);
    opcao = toupper(opcao);
    switch (opcao) {
      case 'A':
        printf("Informe um número.: ");
        scanf("%d", &num);
        if(primo(num) == 0){
          printf("%d é primo", num);
        }
        else{
          printf("%d não é primo", num);
        }
        break;

      case 'B':
        for(int i = 1; i<=100; i++){
          if(primo(i) == 0){
            printf("%d\t", i);
          }
        }
        break;

      case 'C':
        for(int i = 200; i>=100; i--){
          if(primo(i) == 0){
            media = media + i;
            countmedia++;
          }
        }
        media = media/countmedia;
        printf("Media dos primos entre 200 e 100.: %.2f", media);
        break;

      default:
        printf("Opção Inválida\n");
    }

    printf("\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    printf("\n\n");

  } while(ch == 'S');


  return 0;
}
