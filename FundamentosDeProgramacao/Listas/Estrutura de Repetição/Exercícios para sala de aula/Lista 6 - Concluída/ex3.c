#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  char ch;
  int limSup, limInf, aux, count=0;
  float media = 0;
  do {
    do {
      printf("Insira o valor do limite inferior.: ");
      scanf("%d", &limInf);
      printf("Insira o valor do limite superior.: ");
      scanf("%d", &limSup);

      if(limInf == limSup || limInf <=0 || limSup <=0){
        printf("\nInsira novamente os valores\n");
      }
      else if(limSup < limInf){
        aux = limSup;
        limSup = limInf;
        limInf = aux;
      }
      for(limInf; limInf<=limSup; limInf++){
        if (limInf % 3 == 0){
          printf("%d\t", limInf);
          media = media + limInf; count++;
        }
      }
      media = media / count;
      printf("\nA media dos numeros multiplos de 3 é %.2f\n", media);

      printf("\nDeseja digitar outro numero (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);

    } while(limInf == limSup || limInf <=0 || limSup <=0);


  } while(ch == 'S');


  return 0;
}
