#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){

  setlocale(LC_ALL,"Portuguese");
  int limInf, limSup, nlinha, i, count=0, countlinha=0;
  char ch;
  do {

    do {
      printf("Informe o valor do limite inferior do intervalo.: ");
      scanf("%d", &limInf);

      if (limInf <= 0){
        printf("Limite inferior deve ser maior que zero!\n");
      }

      else {

        do {
          printf("Informe o valor do limite superior do intervalo.: ");
          scanf("%d", &limSup);

          if (limSup <= limInf){
            printf("Limite Superior deve ser maior que o limite inferior!\n");
          }

          else {

            do {
              printf("Informe quantos número deseja imprimir por linha.: ");
              scanf("%d", &nlinha);
              if (nlinha <= 0){
                printf("Números por linha deve ser maior que zero!\n");
              }

              else{

                for (limInf; limInf <= limSup; limInf++){

                  for(i=1; i<=limInf; i++){

                    if (limInf % i == 0){
                      count++;
                    }
                  }

                  if (count==2){
                    printf("%2.d ", limInf); countlinha++;
                  }

                  if (countlinha == nlinha){
                    printf("\n"); countlinha=0;
                  }
                  count=0;
                }
                printf("\nDeseja repetir o programa <S ou N>.: ");
                scanf(" %c", &ch);
                ch = toupper(ch);

                if (ch == 'S'){
                  count=0, countlinha=0, limInf=0;
                }
              }
            } while(nlinha <= 0);
          }
        } while(limSup <= limInf);
      }
    } while(limInf <= 0);
  } while(ch == 'S');

  return 0;
}
