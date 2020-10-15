#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int opcao;
  float sl_bruto, sl_liquido;
  printf("Insira o seu salário.: ");
  scanf("%f", &sl_bruto);
  printf("Menu de opções:\n1 - Imposto\n2 - Novo Salário\n3 - Classificação\n");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1:
      if (sl_bruto < 1000){
        sl_liquido = sl_bruto * 0.95;
        printf("\nPercentual de Imposto: 5%%\nSalário Líquido: R$%.2f", sl_liquido);
      }
      else if (sl_bruto >= 1000 && sl_bruto <= 1500){
        sl_liquido = sl_bruto * 0.9;
        printf("\nPercentual de Imposto: 10%%\nSalário Líquido: R$%.2f", sl_liquido);
      }
      else if (sl_bruto > 1500){
        sl_liquido = sl_bruto * 0.85;
        printf("\nPercentual de Imposto: 15%%\nSalário Líquido: R$%.2f", sl_liquido);
      }
      break;

    case 2:
      if (sl_bruto < 1000){
        sl_liquido = sl_bruto + 75;
        printf("\nAumento de R$75\nSalário Líquido: R$%.2f", sl_liquido);
      }
      else if (sl_bruto >= 10100 && sl_bruto <= 1500){
        sl_liquido = sl_bruto + 100;
        printf("\nAumento de R$100\nSalário Líquido: R$%.2f", sl_liquido);
      }
      else if (sl_bruto > 1500){
        sl_liquido = sl_bruto + 150;
        printf("\nAumento de R$ 150\nSalário Líquido: R$%.2f", sl_liquido);
      }
      break;

    case 3:
      if (sl_bruto >= 1000){
        printf("Salário de <Categoria A>");
      }
      else {
        printf("Salário de <Categoria B>");
      }
      break;

    default:
      printf("Você inseriu uma opção inválida");

  }

  return 0;
}
