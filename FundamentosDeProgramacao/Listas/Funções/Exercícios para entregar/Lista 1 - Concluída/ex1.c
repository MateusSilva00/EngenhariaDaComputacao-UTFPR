#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int quadrado (int num){
  return num * num;
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int limInf, limSup, i;
  char ch;

  do {
    do {
      printf("Informe o valor para o limite inferior de um intervalo.: ");
      scanf("%d", &limInf);
      if(limInf < 1 || limInf > 99){
        printf("O valor do limite inferior deve estar entre 1 e 99\n");
      }
      else{
        do {
          printf("Informe o valor para o limite superior de um intervalo.: ");
          scanf("%d", &limSup);
          if(limSup <= limInf || limSup > 100){
            printf("O valor do limite superior deve ser maior que o inferior e menor que 101\n");
          }
          else{
            for(i=limInf; i<= limSup; i++){
              printf("%d ^ 2 = %d\n", i, quadrado(i));
            }
          }
        } while(limSup <= limInf || limSup > 100);
        printf("\n\nDeseja continuar no programa (S ou N) ?");
        scanf(" %c", &ch);
        ch = toupper(ch);
        if(ch == 'S') printf("\n");
      }
    } while(limInf < 1 || limInf > 99);
  } while(ch == 'S');

  return 0;
}
