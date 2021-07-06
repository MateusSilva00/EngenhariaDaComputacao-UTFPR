#include <stdio.h>


int main (){
  int qtproduto, tdez, tcinco, tum;
  float vlpago, vlproduto, total = 0, troco, tcents;
  do {
    printf("Informe a quantidade de um produto.: ");
    scanf("%d", &qtproduto);
    if (qtproduto <= 0){
      break;
    }
    else{
    printf("Informe o valor unitário de um produto.: ");
    scanf("%f", &vlproduto);
    }
    total = total + (vlproduto * qtproduto);

  } while(qtproduto > 0);

  printf("\nTOTAL DA COMPRA.: %.2f", total);
  do {
    printf("\nInsira o valor pago pelo cliente.: ");
    scanf("%f", &vlpago);
    if (total > vlpago) {
      printf("Valor pago menor que o valor total!\n");
    }
    else {
      troco = vlpago - total;
      printf("TROCO R$ %.2f", troco);

      tdez = troco / 10;
      tcinco = ((int)troco%10)/5;
      tum = ((int)troco%10)%5/1;
      tcents = troco - ((tdez*10) + (tcinco*5) + tum);
      printf("\nO valor do troco será devolvido com:\n%d nota(s) de 10 reais\n%d nota(s) de 5 reais\n%d nota(s) de 1 real\n e %.2f centavos", tdez, tcinco, tum, tcents);
    }

  } while(total > vlpago);

  return 0;
}
