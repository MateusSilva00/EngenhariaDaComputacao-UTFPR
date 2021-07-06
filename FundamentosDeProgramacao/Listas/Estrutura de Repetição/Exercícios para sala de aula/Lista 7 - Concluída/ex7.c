#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

  setlocale(LC_ALL,"Portuguese");
  int limInf, limSup, limA, limB;
  char ch;

  do {
    do {
      printf("Informe o limite inferior do intervalo.: ");
      scanf("%d", &limInf);

      if(limInf % 2 != 0){
        printf("O valor informado deve ser um número par!\n");
      }

      else if (limInf <= 0){
        printf("O valor informado deve ser maior do que zero\n");
      }

      else {
        do {
          printf("Informe o limite superior do intervalo.: ");
          scanf("%d", &limSup);

          if(limSup <= limInf){
            printf("O valor informado deve ser maior que o limite inferior!\n");
          }

          if(limSup % 2 != 0){
            printf("O valor informado deve ser um número par!\n");
          }

          else if(limSup >= limInf && limSup % 2 == 0){
            limA = limInf; limB = limSup;
            printf("\t=== ORDEM DECRESCENTE ===\n");
            for (limB; limB>=limA; limB--){
              printf("%2.d\t", limB);
            }
            limA = limInf; limB = limSup;
            printf("\n\t=== VALORES PARES EM ORDEM CRESCENTE ===\n");
            for (limA; limA <= limB; limA+=2){
              printf("%2.d\t", limA);
            }

            limA = limInf; limB = limSup;
            printf("\n\t=== MULTIPLOS DE 10 EM ORDEM DECRESCENTE ===\n");

            for(limB -= limB % 10; limB>=0; limB-=10){
              printf("%2.d\t", limB);
            }

            limA = limInf; limB = limSup;
            printf("\n\t=== MULTIPLOS DE 5 EM ORDEM DECRESCENTE ===\n");
            for(limB-=limB%5; limB>=0; limB-=5){
              printf("%2.d\t", limB);
            }
            printf("\n\nDeseja continuar o programa <S ou N>? ");
            scanf(" %c", &ch);
            ch = toupper(ch);
            if (ch == 'S'){
              printf("\n");
              system("clear"); //para windows
              // system("cls") para windows
            }
          }

        } while(limSup <= limInf || limSup % 2 != 0);
      }
    } while(limInf % 2 != 0 || limInf <= 0);


  } while(ch == 'S');

  return 0;
}
