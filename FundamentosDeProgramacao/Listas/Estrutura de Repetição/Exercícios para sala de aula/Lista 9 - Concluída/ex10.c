#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int qtProduto, reais, nota100, nota50, nota20, nota10, nota5, nota2, nota1;
  float vlUnitario, vlMedio=0,total=0, centavos;
  char ch;
  do {
    do {
      printf("Informe a quantidade de um produto.: ");
      scanf("%d", &qtProduto);
      if(qtProduto > 0){
        do {
          printf("Informe o valor unitario do produto.: ");
          scanf("%f", &vlUnitario);
          if(vlUnitario <= 0){
            printf("Produto de graça? Acho que não né meu filho!\n");
          }
          else{
            total = total + (qtProduto*vlUnitario);
            vlMedio = vlMedio + qtProduto;
          }
          printf("\n");
        } while(vlUnitario <= 0);
      }
    } while(qtProduto > 0);

    vlMedio = total / vlMedio;
    printf("\n\nVALOR TOTAL DA COMPRA R$ %.2f\nVALOR MÉDIO DA COMPRA %.2f", total, vlMedio);
    reais = total;
    centavos = total - reais;
    printf("\n\nO valor total da compra é %d reais e %.2f centavos", reais, centavos);

    nota100 = reais / 100; //788 / 100 = 7
    nota50 = (reais % 100) / 50; //788 % 100 = 88, 88 / 50 = 1 -
    nota20 = ((reais % 100) - (nota50*50)) / 20;
    nota10 =  ((reais % 100) - (nota50*50) - (nota20*20)) / 10;
    nota5 = ((reais % 100) - (nota50*50) - (nota20*20) - (nota10*10)) / 5;
    nota2 = ((reais % 100) - (nota50*50) - (nota20*20) - (nota10*10) - (nota5*5)) / 2;
    nota1 = ((reais % 100) - (nota50*50) - (nota20*20) - (nota10*10) - (nota5*5) - (nota2*2)) / 1;

    printf("\n%d nota(s) de 100\n%d nota(s) de 50\n%d nota(s) de 20\n%d nota(s) de 10\n%d nota(s) de 5\n%d nota(s) de 2\n%d moeda(s) de 1",nota100, nota50, nota20, nota10, nota5, nota2, nota1);

    printf("Deseja repetir o programa (S ou N).: ");
    scanf(" %c", &ch);
    if(ch == 'S'){
      vlMedio=0; total=0; printf("\n");
    }
  } while(ch == 'S');

  return 0;
}
