#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int i, limInf, limSup;

  do {
    printf ("Informe um valor para o limite inferior de um intervalo.: ");
    scanf("%d", &limInf);
    printf ("Informe um valor para o limite superior de um intervalo.: ");
    scanf("%d", &limSup);

    if (limInf == limSup || limInf <= 0 || limSup <= 0){
      printf("Valor dos inválidos. Informe valores diferentes!\n");
    }

    else if (limInf < limSup){
      for (limInf; limInf <= limSup; limInf++) {
          if (limInf % 2 == 0 && limInf % 3 == 0){
            printf("%d ", limInf);
          }
        }
      }

    else if (limInf > limSup){
      for (limSup; limSup <= limInf; limSup++){
          if (limSup % 2 == 0 && limSup % 3 == 0){
            printf("%d ", limSup);
           }
        }
      }

  } while(limInf == limSup);

  return 0;
}
