#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int numPalindromo(int x){
    int  palindromo=0, aux, isPalin=0;
    aux = x;
    while (aux > 0) {
      palindromo = (palindromo*10) + (aux%10);
      aux = aux/10;
    }

    if (x == palindromo){
      isPalin++;
      printf("%d ", x);
    }

  return isPalin;
}


int main(){
  int opcao, num, limInf, limSup, i;
  char ch;
  do {
    printf("1 - Verifica se um numero é palindromo\n2 - Mostra os número palindromo que pertecem a um intervalo\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe um número.: ");
        scanf("%d", &num);
        if(numPalindromo(num) == 0){
          printf("%d Não é palindromo\n", num);
        }
        else{
          printf("é palindromo\n");
        }
        break;

      case 2:
        do {
          printf("Informe um limite inferior.: ");
          scanf("%d", &limInf);
          if(limInf <= 0){
            printf("Limite inferior deve ser maior que 0!\n");
          }
          else{
            do {
              printf("Informe um limite superior.: ");
              scanf("%d", &limSup);
              if (limSup <= limInf){
                printf("Limite superior deve ser maior que o inferior!\n");
              }
              else{
                for(i = limInf; i<=limSup; i++){
                  numPalindromo(i);
                }
              }
            } while(limSup <= limInf);
          }
        } while(limInf <= 0);
        break;

      default:
      printf("Opção Inválida!\n");
    }

    printf("\nDeseja continuar o programa (S ou N).:");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
        printf("\n");
    }

  } while(ch == 'S');


  return 0;
}
