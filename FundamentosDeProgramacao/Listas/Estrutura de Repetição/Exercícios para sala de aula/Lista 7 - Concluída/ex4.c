#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int meses, countmes = 1, aumento=1;
  float aporte, juros;
  char ch;
  do {

    do {
      printf("Informe o valor da aplicação.: ");
      scanf("%f", &aporte);

      if (aporte <=0){
        printf("Valor da aplicação deve ser positivo!\n");
      }
      else{

        do {
          printf("Informe o percentual de rendimento mensal (0 a 1).: ");
          scanf("%f", &juros);

          if (juros < 0 || juros > 1){
            printf("O juros devem estar entre 0 e 1 !\n");
          }

          else{

            do {
              printf("Informe o periodo (em meses).: ");
              scanf("%d", &meses);

              if(meses < 0){
                printf("O periodo em meses deve ser positivo!\n");
              }

              else{
                printf("MÊS\t\t%% DE RENDIMENTO\tVALOR APLICAÇÃO\n");
                do {
                  if (aumento == 12){
                    juros = juros + 0.25;
                    aumento = 0;
                  }
                  aporte = aporte * (1+juros);
                  printf("%d\t\t%f\tR$%.2f\n", countmes, juros, aporte);
                  countmes++; aumento++;

                } while(countmes <= meses);

                printf("\nDeseja continuar o programa <S ou N> ?");
                scanf(" %c", &ch);
                ch = toupper(ch);
                if (ch == 'S') {
                  countmes = 1, aumento=1;
                  printf("\n\n");
                }

              }

            } while(meses < 0);

          }

        } while(juros < 0 || juros > 1);

      }

    } while(aporte <= 0);

  } while(ch == 'S');

  return 0;
}
