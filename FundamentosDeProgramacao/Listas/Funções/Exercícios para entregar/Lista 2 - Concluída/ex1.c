#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int numTriangular(int x){
  int aux=0, i;
  for(i=1; i*(i+1)*(i+2)<= x; i++){
    if(i*(i+1)*(i+2) == x){
      aux++;
      break;
    }
  }
  if(aux == 1){
      printf("%d é triangular ==> %d * %d * %d = %d\n",x,i,i+1,i+2,x);
  }
  return aux;
}


int main(){
  setlocale(LC_ALL,"Portuguese");

  int opcao, num, limInf, limSup, i;
  char ch;
  do {
    printf("1 - Verifica se um numero é triangular\n2 - Mostra os número triangulares que pertecem a um intervalo\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe um número.: ");
        scanf("%d", &num);
        if(numTriangular(num) == 0){
          printf("%d Não é triangular\n", num);
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
                  numTriangular(i);
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
