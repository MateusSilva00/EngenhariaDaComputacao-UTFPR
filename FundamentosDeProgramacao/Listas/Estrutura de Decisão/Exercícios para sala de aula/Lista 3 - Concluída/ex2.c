#include <stdio.h>
#include <locale.h>

int main (){

  setlocale(LC_ALL, "Portuguese");
  int a, b, aux;
  printf("Insira o valor de <a>.: ");
  scanf("%d", &a);
  printf("Insira o valor de <b>.: ");
  scanf("%d", &b);
  if (a % 5 == 0 || b % 5 == 0){
    if (a % 5 == 0 && b % 5 == 0){
      printf("\nAmbos são divisíveis por 5");
    }
    else if (a % 5 == 0){
      printf("\nApenas %d é divisível por 5", a);
    }
    else{
      printf("\nApenas %d é divisível por 5", b);
    }
  }
  else {
      printf("\nAmbos não são divisíveis por 5");
  }

  if (a % 2 == 0 || b % 2 == 0){
    if (a % 2 == 0 && b % 2 == 0){
      printf("\nAmbos são pares");
    }
    else if (a % 2 == 0){
      printf("\n%d é par\n%d é impar", a, b);
    }
    else{
      printf("\n%d é par\n%d é impar", b, a);
    }
  }
  else {
      printf("\nAmbos são impares");
  }


  return 0;
}
