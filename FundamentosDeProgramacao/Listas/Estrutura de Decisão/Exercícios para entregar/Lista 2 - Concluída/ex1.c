// 1) A contribuição para o INSS é calculada da seguinte forma:
// a) Salário bruto até três salários mínimos = INSS 8%.
// b) Salário bruto acima de três salários mínimos = INSS 10%.
// c) Para as contribuições maiores que o salário mínimo, considerar a importância de um
// salário mínimo.
// Elaborar um programa que receba como entrada o valor do salário mínimo e o valor do
// salário bruto, calcule o INSS e o salário líquido restante e informe-os.

#include <stdio.h>
#include <locale.h>

int main (){

  setlocale(LC_ALL,"Portuguese");

  int sl_minimo, sl_bruto, sl_liquido;
  printf("Informe o valor do salário mínimo.: ");
  scanf("%d", &sl_minimo);
  printf("\nInforme o seu salário bruto.: ");
  scanf("%d", &sl_bruto);

  if ((sl_minimo*3) >= sl_bruto) {
    sl_liquido = sl_bruto * 0.92;
    printf("\nINSS DE 8%%!\nO seu salário líquido é R$ %d", sl_liquido);
  }

  else {
    sl_liquido = sl_bruto * 0.9;
    printf("\nINSS DE 10%%!\nO seu salário líquido é R$ %d", sl_liquido);
  }


  return 0;
}
