#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int qtnum, nlinha, countlinha = 0,i=1, count=0;
  do {
    printf("Quantos valores divisíveis por 5 e não diviseis por 2 deseja mostrar.: ");
    scanf("%d", &qtnum);
    if(qtnum <= 0){
      printf("Informe um valor positivo!\n");
    }
    else{
      do {
        printf("Quantos elementos deseja mostrar por linha? ");
        scanf("%d", &nlinha);
        if(nlinha <= 0){
          printf("Número de elementos deve ser positivo!\n");
        }
        else{
          do {
            if(countlinha == nlinha){
              printf("\n");
              countlinha=0;
            }
            if(i % 5 == 0 && i % 2 != 0){
              count++;
              printf("%2.d\t", i);
              countlinha++;
            }
            i++;
          } while(count < qtnum);
        }
      } while(nlinha <= 0);
    }
  } while(qtnum <= 0);

  return 0;
}
