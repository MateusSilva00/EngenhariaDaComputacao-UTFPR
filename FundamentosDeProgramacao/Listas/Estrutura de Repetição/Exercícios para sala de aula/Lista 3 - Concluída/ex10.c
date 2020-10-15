#include <stdio.h>

int main(){

  int i, firsterm=1 , secondterm=0, termos, aux;
  printf("Quantos termos mostrar.: ");
  scanf("%d", &termos);
  for (i = 1; i <= termos; i++){
    if (i == 1){
      firsterm = i;
      secondterm = 0;
      printf("%d ", firsterm);
    }
    else {
      aux = firsterm + secondterm;
      secondterm = firsterm;
      firsterm = aux;
      printf("%d ", aux);
    }

  }


  return 0;
}
