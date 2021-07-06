#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  float renda_anual, renda_liquida;
  printf("Insira o valor da sua renda anual.: ");
  scanf("%f", &renda_anual);

  if (renda_anual > 0){
    if (renda_anual <= 10000){
      printf("\nIsento de imposto de renda!");
    }
    else if (renda_anual > 10000 && renda_anual <= 25000){
      renda_liquida = renda_anual * 0.9;
      printf("Imposto de renda de 10%%\nRenda Líquida = R$%.2f", renda_liquida);
    }
    else if (renda_anual > 25000){
      renda_liquida = renda_anual * 0.75;
      printf("Imposto de renda de 25%%\nRenda Líquida = R$%.2f", renda_liquida);
    }
  }

  else{
    printf("Você digitou um valor negativo!");
  }

  return 0;
}
