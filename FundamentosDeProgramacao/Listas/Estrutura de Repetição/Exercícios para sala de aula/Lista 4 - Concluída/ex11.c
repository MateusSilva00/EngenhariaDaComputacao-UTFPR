#include <stdio.h>

int main(){

  int num, cont=0;
  printf("Informe um numero.: ");
  scanf("%d", &num);
  while (cont <= 10) {
    printf("%d ", cont*num);
    cont++;
  }


  return 0;
}
