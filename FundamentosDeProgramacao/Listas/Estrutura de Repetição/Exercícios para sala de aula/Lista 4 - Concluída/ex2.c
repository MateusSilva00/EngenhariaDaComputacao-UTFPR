// Uma pessoa aplicou R$ 1000,00 com rendimento de 5% ao mês. Quantos meses serão necessários para
// que o capital investido ultrapasse R$ 1200,00.
#include <stdio.h>

int main (){

  int meses = 0;
  float invest, cap;
  printf("Insira o investimento inicial.:");
  scanf("%f", &invest);
  printf("Capital desejado.: ");
  scanf("%f", &cap);

  while (invest < cap) {
    invest = invest * 1.05;
    meses++;
  }

  printf("Valor final = R$ %.2f", invest);
  printf("\nSerao necessario %d meses para que o capital investido ultrapasse R$%.2f", meses, cap);

  return 0;
}
