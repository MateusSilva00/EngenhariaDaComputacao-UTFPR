#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int numRetangular(int x){
  int aux=0, i, j=0, count=0;
  for(i=2; i <= x; i+=2){
      j = j+i;
      count++;
      if(j == x){
        aux++;
        break;
      }
    }

  if(aux == 1){
      printf("%d é retangular ==>", x);
      for(j=1; j <= count; j++){
          if(j == count){
            printf("%d = %d\n", j*2,x);
          }
          else{
            printf(" %d + ", j*2);
          }
        }
  }
  return aux;
}


int main(){
  setlocale(LC_ALL,"Portuguese");

  int opcao, num, limInf, limSup, i;
  char ch;
  do {
    printf("1 - Verifica se um numero é retangular\n2 - Mostra os número retangulares que pertecem a um intervalo\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe um número.: ");
        scanf("%d", &num);
        if(numRetangular(num) == 0){
          printf("%d Não é retangular\n", num);
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
                  numRetangular(i);
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
