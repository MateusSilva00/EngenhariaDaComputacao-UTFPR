// Um ano é bissexto se for divisível por 4 e não for divisível por 100. Também são bissextos os
// divisíveis por 400. Escreva um programa que determina se um ano informado pelo usuário é
// bissexto.
#include <stdio.h>
#include <locale.h>

int main (){

  setlocale(LC_ALL, "Portuguese");
  int ano;
  printf("Insira um ano.: ");
  scanf("%d", &ano);

  if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0 ){
    printf("Ano bissexto");
  }
  else{
    printf("Ano não bissexto");
  }

  return 0;
}
