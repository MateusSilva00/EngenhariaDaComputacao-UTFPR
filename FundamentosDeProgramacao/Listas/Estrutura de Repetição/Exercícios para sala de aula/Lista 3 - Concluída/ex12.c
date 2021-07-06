// Faça um programa que imprima os n (indicado pelo usuário) primeiros números pares
// (começa em 0). Apresentar 5 valores por linha.
#include <stdio.h>

int main(){
  int n,i,count=0, aux;
  printf("Insira a quantidade de termos.: ");
  scanf("%d", &n);
  aux = 2 * n;
  for (i=0; i<aux; i+=2){
    printf("%d ",i);
    count++;
    if (count == 5){
      printf("\n");
      count=0;
    }
  }

  return 0;
}
