#include <stdio.h>
#include <locale.h>
#include <ctype.h>

float ConverterMoedas(float Valor, float Cotacao, char Tipo){
    switch (Tipo) {
      case 'R':
        return Valor * Cotacao;
        break;
      case 'D':
        return Valor / Cotacao;
        break;

      default:
        printf("Conversão inválida!\n");
    }
}


int main(){
  setlocale(LC_ALL,"Portuguese");

  int limInf, limSup, i;
  float valor, cotacao, resultado;
  char tipo, ch;

  do {

    printf("Informe um valor que deseja converter.: ");
    scanf("%f", &valor);
    printf("Informe o valor da cotação.: ");
    scanf("%f", &cotacao);
    printf("Informe o tipo de conversão (D - Dolar e R - Real).: ");
    scanf(" %c", &tipo);
    tipo = toupper(tipo);
    resultado = ConverterMoedas(valor, cotacao, tipo);
    if(tipo == 'R'  || tipo == 'D'){
      printf("O valor obtido é %.2f", resultado);
    }

    do {
      printf("\n\nInforme o valor para o limite inferior de um intervalo.: ");
      scanf("%d", &limInf);
      if(limInf <= 0){
        printf("O valor do limite inferior deve ser maior que zero\n");
      }
      else{
        do {
          printf("Informe o valor para o limite superior de um intervalo.: ");
          scanf("%d", &limSup);
          if(limSup <= limInf ){
            printf("O valor do limite superior deve ser maior que o inferior\n");
          }
          else{
            printf("Informe o valor da cotação.: ");
            scanf("%f", &cotacao);
            printf("Informe o tipo de conversão (D - Dolar e R - Real).: ");
            scanf(" %c", &tipo);
            tipo = toupper(tipo);
            printf("DOLARES\t REAIS");
            for(i = limInf; i<=limSup; i++){
              resultado = ConverterMoedas(i, cotacao, tipo);
              printf("\n%d\t%2.2f", i, resultado);
            }
          }
        } while(limSup <= limInf);
        printf("\nDeseja continuar no programa (S ou N) ?");
        scanf(" %c", &ch);
        ch = toupper(ch);
        if(ch == 'S') printf("\n");
      }
    } while(limInf <= 0);
  } while(ch == 'S');

  return 0;
}
