#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include "diversos.h"

int main(){
  setlocale(LC_ALL,"Portuguese");

  int opcao, num, num2;
  float valor, cotacao, resultado;
  char ch, conversao;

  do {
    printf("1 - Calcula o Quadrado de um número\n2 - Converte centimetros para polegada\n3 - Converte um valor para dolar ou real\n4 - Multiplica dois números\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {

      case 1:
        printf("\nInforme um número.: ");
        scanf("%d", &num);
        printf("Quadrado.: %d", quadrado(num));
        break;

      case 2:
        printf("\nInforme um valor em centimetros a ser convertido em polegadas.: ");
        scanf("%d", &num);
        printf("Polegadas.: %.2f", polegadas(num));
        break;

      case 3:
        printf("\nInforme um valor em moeda que deseja converter para dolar ou real.: ");
        scanf("%f", &valor);
        printf("Informe o valor da cotacao do dolar.: ");
        scanf("%f", &cotacao);
        printf("Informe o tipo de conversa (D - Dolar e R - Real).: ");
        scanf(" %c", &conversao);
        conversao = toupper(conversao);
        if(conversao == 'D' || conversao == 'R'){
          resultado = ConversorMoeda(valor, cotacao, conversao);
          printf("Valor convertido.: %.2f", resultado);
        }

        break;
      case 4:
        printf("\nInforme um número.: ");
        scanf("%d", &num);
        printf("Informe outro número.: ");
        scanf("%d", &num2);
        printf("Resultado da multiplicação.: %d", multiplicacao(num, num2));
        break;
        
      default:
        printf("Opção inválida!");
    }

    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      printf("\n");
    }
  } while(ch == 'S');

}
