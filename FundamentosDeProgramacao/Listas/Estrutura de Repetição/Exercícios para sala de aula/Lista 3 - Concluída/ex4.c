#include <stdio.h>

int main (){
  int i, x,y, limInf, limSup;
  printf ("Informe um valor para o limite inferior de um intervalo.: ");
  scanf("%d", &limInf);
  printf ("Informe um valor para o limite superior de um intervalo.: ");
  scanf("%d", &limSup);
  printf("Informe um valor para x.: ");
  scanf("%d", &x);
  printf("Informe um valor para y.: ");
  scanf("%d", &y);

  if (limInf == limSup){
    printf("Valor dos limites inválidos");
  }

  else if (limInf < limSup){
    for (limInf; limInf <= limSup; limInf++) {
      if (limInf % x == 0 && limInf % y != 0){
        printf("%d ", limInf);
      }
    }
  }

  else if (limInf > limSup){
    for (limInf; limInf >= limSup; limInf--){
      if (limInf % x == 0 && limInf % y != 0){
        printf("%d ", limInf);
      }
    }
  }


  return 0;
}
