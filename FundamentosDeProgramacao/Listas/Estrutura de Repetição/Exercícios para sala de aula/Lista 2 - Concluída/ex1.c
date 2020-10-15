#include <stdio.h>

int main (){
  int i, num, resul;
  printf("Informe um número.: ");
  scanf("%d", &num);
  for (i=1; i<=10; i++){
    resul = num * i;
    printf("\t%d X %d = %2d\n", num, i, resul);
  }

  return 0;
}
