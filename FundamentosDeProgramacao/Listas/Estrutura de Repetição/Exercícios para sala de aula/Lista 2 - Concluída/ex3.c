#include <stdio.h>
#include <math.h>

int main(){
  int i;
  float ipow, isqrt;
  printf("\t Quadrados \t\t Raizes Quadradas\n");
  for (i=0; i<=100; i++){
    if (i % 3 == 0){
      printf("\t%d", i);
      ipow = pow(i,2);
      printf(" Quadrado é %.0f\n", ipow);
    }
    else if(i % 5 == 0 || i % 7 == 0){
      printf("\t\t\t\t%d",i);
      isqrt = sqrt(i);
      printf(" Raiz quadrada é %.2f\n", isqrt);
      }
  }

  return 0;
}
