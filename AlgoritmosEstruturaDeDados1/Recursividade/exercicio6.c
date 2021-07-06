// 6.    Escreva uma função recursiva que determine quantas vezes um dígito K ocorre em um número natural N.
// Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numRepetidos(int num, int num_verificado, int repeticao){

  if(num >= 1){
    if(num_verificado == (num%10)){
      repeticao++;
    }
    num = num / 10;
    numRepetidos(num, num_verificado,  repeticao);
  }

  else return repeticao;
}

int main(){

  srand(time(0));

  int num, num_verificado, return_func;
  for(int i = 1; i <= 5; i++){
    num = rand() % 99999999999 + 1;
    num_verificado = rand() % 9 + 1;
    return_func = numRepetidos(num, num_verificado, 0);

    printf("Número: %d\nDígito a ser verificado: %d\nRepetições: %d\n\n", num, num_verificado, return_func);
  }

  return 0;
}
