#include <stdio.h>
#include <locale.h>
#include <ctype.h>
int main (){

  setlocale (LC_ALL, "Portuguese");
  int qtanos, i;
  float vlbem, juros, depreciacao, vldepreciado, dpacumulada = 0;
  char ch;

  do {
    do {
      printf("Informe o valor do bem a ser depreciado.: ");
      scanf("%f", &vlbem);
      printf("Informe o periodo da depreciacao <em anos>.: ");
      scanf("%d", &qtanos);
      if (qtanos <= 0){
        printf("O numero de anos deve ser positivo!\n");
      }
      else {
        do {
          printf("Informe a taxa de depreciação.: ");
          scanf("%f", &juros);
          if (juros <= 0){
            printf("A taxa de depreciação deve ser positiva!\n");
          }
          else {
            printf("Ano\t Valor do Bem\t Depreciacão\t Valor Depreciado\n");
            printf("________________________________________________________________\n");
            for (i=1; i<=qtanos; i++){
              depreciacao = vlbem * (juros/100);
              vldepreciado = vlbem - depreciacao;
              printf("%d\t%1.2f\t\t%.2f\t\t%.2f\n", i, vlbem, depreciacao, vldepreciado);
              vlbem = vldepreciado;
              dpacumulada = dpacumulada + depreciacao;
            }
            printf("________________________________________________________________");
            printf("\nDepreciação Acumulada: R$%.2f", dpacumulada);
            printf("\nDeseja repetir o programa <S ou N>?");
            scanf(" %c", &ch);
            ch = toupper(ch);
            if (ch == 'S'){
              dpacumulada = 0;
            }
          }
        } while(juros <= 0);
      }
    } while(qtanos <= 0);
  } while(ch == 'S');


  return 0;

}
