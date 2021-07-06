// A figura a seguir representa uma árvore de decisão para identificar se um paciente está
// saudável ou doente. Elabore um programa que implementa essa árvore de decisão.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){

  int temperatura;
  char condicao;

  setlocale (LC_ALL,"Portuguese");
  printf("\tRELATÓRIO MÉDICO");
  printf("\nResponda S para SIM e N para NAO\n\nO paciente se sente bem?.:");
  scanf("%s", &condicao);
  condicao = toupper(condicao);

  if (condicao == 'S'){
    printf("\nO paciente está saudável!");
  }
  else if (condicao == 'N'){
    printf("O paciente tem dor?.: ");
    scanf("%s", &condicao);
    condicao = toupper(condicao);

    if (condicao == 'S'){
      printf("\nO paciente está doente!");
    }
    else if(condicao == 'N'){
      printf("Qual a temperatura do paciente.: ");
      scanf("%d", &temperatura);
      if (temperatura > 37) {
        printf("\nO paciente está doente!");
      }
      else printf("\nO paciente está saudável!");
    }
  }
  else printf("Você digitou um valor inválido");

  return 0;
}
