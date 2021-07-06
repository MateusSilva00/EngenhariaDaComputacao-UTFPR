#include <stdio.h>
#include <locale.h>
#include <ctype.h>
int main(){
  setlocale(LC_ALL,"Portuguese");

  int limInf, limSup, i, j , countdiv=0, countlinha=0, countmedia=0;
  float media = 0;
  char ch;

  do {
    do {
      printf("Informe um valor para o limite inferior do intervalo.: ");
      scanf("%d", &limInf);
      if(limInf <= 0){
        printf("Informe um valor positivo!\n");
      }
      else{
        do {
          printf("Informe um valor para o limite superior do intervalo.: ");
          scanf("%d", &limSup);
          if(limSup <= limInf){
            printf("O valor limite superior deve maior do que o inferior!\n");
          }
          else{
            for(j=limInf; j<=limSup; j++){
              if(countlinha == 5){
                printf("\n");
                countlinha=0;
              }
              for(i=1; i<=j; i++){
                if(j % i == 0){
                  countdiv++;
                }
              }
              if(countdiv == 2){
                printf("%2.d ", j);
                countlinha++;
              }
              countdiv=0;
              if(j % 3 == 0 && j % 7 == 0){
                media = media + j;
                countmedia++;
              }
            }
            if(countmedia > 0){
              media = media / countmedia;
              printf("Média dos múltiplos de 3 e 7.: %.2f", media);
            }

            printf("\n\nDeseja repetir o programa (S ou N): ");
            scanf(" %c", &ch);
            ch = toupper(ch);
            if(ch == 'S'){
              media = 0; countdiv=0; countlinha=0; countmedia=0; printf("\n");
            }

          }
        } while(limSup <= limInf);
      }
    } while(limInf <= 0);
  } while(ch == 'S');


  return 0;
}
