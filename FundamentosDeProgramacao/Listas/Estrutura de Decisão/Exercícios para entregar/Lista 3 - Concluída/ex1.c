// Elabore um programa que obtenha por meio do teclado a pontuação, em valores
// inteiros, de um candidato ao concurso vestibular, nas seguintes área: exatas (e), humanas
// (h) e conhecimento geral (cg). A seguir deverá ser definida a média ponderada usando a
// seguinte expressão: mp = ((e * 3) + (h * 2) + cg) / 6. A média ponderada calculada define
// o rendimento do candidato de acordo com a seguinte tabela:
// Insuficiente = 0 - 250 pontos
// Baixo = 251 - 500 pontos
// Regular = 501 - 700 pontos
// Bom = 701 - 900 pontos
// Excelente = maior que 900 pontos
#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL, "Portuguese");
  int e, h, cg, mp;
  printf("Insira sua nota de exatas.: ");
  scanf("%d", &e);
  printf("Insira sua nota de humanas.: ");
  scanf("%d", &h);
  printf("Insira sua nota de conhecimentos gerais.: ");
  scanf("%d", &cg);
  mp = ((e * 3) + (h *2) + cg)/6;
  if ( mp <= 250){
    printf("\n\tInsuficiente");
  }
  else if (mp >= 251 && mp <= 500){
    printf("\n\tBaixo");
  }
  else if (mp >= 501 && mp <= 700){
    printf("\n\tRegular");
  }
  else if (mp >= 701 && mp <= 900){
    printf("\n\tBom");
  }
  else if (mp > 900){
    printf("\n\tExcelente");
  }

  printf(" Sua média final é de %d pontos", mp);


  return 0;
}
