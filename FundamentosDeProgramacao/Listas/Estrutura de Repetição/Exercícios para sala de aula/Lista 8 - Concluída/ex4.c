#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int limInf, limSup, nlinha, countlinha=0, countmedia=0, j;
  float media=0;
  char ch;

  do {
    printf("Informe o valor do limite inferior do intervalo.: ");
    scanf("%d", &limInf);
    do {
      printf("Informe o valor do limite superior do intervalo.: ");
      scanf("%d", &limSup);
      if(limSup == limInf || limSup <= limInf){
        printf("Valor do limite superior inválido\n");
      }
      else{
        do {
          printf("Informe quantos elementos deseja imprimir por linha.: ");
          scanf("%d", &nlinha);
          if(nlinha <=0){
            printf("O numero de elementos deve ser maior que zero!\n");
          }
          else{
            for(j=limInf; j<=limSup; j++){
              if(countlinha == nlinha){
                printf("\n");
                countlinha=0;
              }

              if(j % 2 == 0){
                printf("%d\t", j);
                countlinha++;
              }

              else if(j % 2 != 0){
                if(j < 0){
                  media = media + (j*-1);
                  countmedia++;
                }
                else{
                  media = media + j;
                  countmedia++;
                }
              }

            }
          }
        } while(nlinha <=0);
      }
      printf("\nmedia %.2f, countmedia %d\n", media, countmedia);
      media = media/countmedia;
      printf("\nMedia dos números impares %.2f", media);
      printf("\nDeseja continuar o programa (S ou N) ?");
      scanf(" %c", &ch);
      ch = toupper(ch);
      if(ch == 'S'){
        countlinha=0; countmedia=0; media = 0;
      }
    } while(limSup == limInf || limSup <= limInf);
  } while(ch == 'S');

  return 0;
}
