#include <stdio.h>

int main (){
  int i;
  long long int num;
  printf("Informe um número.: ");
  scanf("%lld", &num);
  for (i = num-1; i>0; i--){
    num = num *i;
  }
  printf("Fatorial = %lld", num);

}
