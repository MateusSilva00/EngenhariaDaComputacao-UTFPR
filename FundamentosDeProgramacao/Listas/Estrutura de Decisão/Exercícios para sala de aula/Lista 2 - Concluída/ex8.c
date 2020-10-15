#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  float sl_base, sl_bruto, gratificacao, ir, sl_liquido;
  printf("Insira seu salário base.:");
  scanf ("%f", &sl_base);
  printf("Insira a gratificação.:");
  scanf("%f", &gratificacao);
  sl_bruto = sl_base + gratificacao;
  if (sl_bruto < 1000){
    ir = sl_bruto * 0.15;
  }
  else{
    ir = sl_bruto * 0.20;
  }
  sl_liquido = sl_bruto - ir;
  printf("\nSalário bruto: R$%.2f\nSeu salário líquido: R$%.2f", sl_bruto, sl_liquido);

  return 0;
}
