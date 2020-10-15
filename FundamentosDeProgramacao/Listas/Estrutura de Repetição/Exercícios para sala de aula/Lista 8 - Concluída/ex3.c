#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

int main(){

  setlocale(LC_ALL,"Portuguese");

  int idade, i, salario, sl_count=0, comesada=0, semesada=0;
  char tipo, soun, ch;
  float mediasalarial=0;

  do {
    for(i=1; i<=5; i++){
      do {
        printf("Informe a idade da pessoa %d.: ",i);
        scanf("%d", &idade);
        if(idade <= 0){
          printf("Idade inválida!\n");
        }
        else{
          do {
            printf("Informe o tipo (P = Professor ou E = Estudante).: ");
            scanf(" %c", &tipo);
            tipo = toupper(tipo);
            if(tipo != 'P' && tipo != 'E'){
              printf("Tipo inválido\n");
            }
            else{

              switch (tipo) {

                case 'P':
                  do {
                    printf("Informe o salário.: ");
                    scanf("%d", &salario);
                    if(salario <= 0){
                      printf("Salário inválido!\n");
                      }
                    } while(salario <=0);
                    mediasalarial = mediasalarial + salario;
                    sl_count++;
                  break;

                case 'E':
                  do {
                    printf("Receba mesa (S=Sim ou N=Não).: ");
                    scanf(" %c", &soun);
                    soun = toupper(soun);
                    if(soun != 'S' && soun != 'N'){
                      printf("Valor inválido\n");
                    }
                    else if(soun == 'S'){
                      comesada++;
                    }
                    else{
                      semesada++;
                    }
                  } while(soun != 'S' && soun != 'N');
              }
            }
          } while(tipo != 'P' && tipo != 'E');
        }
      } while(idade <=0);
      printf("\n");
    }

    if(sl_count >= 1){
      mediasalarial = mediasalarial / sl_count;
      printf("\nMedia salarial dos professores: R$ %.2f", mediasalarial);
    }

    printf("\nNumero de estudantes que recebem mesada: %d\nNumero de estudantes que não recebem mesada %d", comesada, semesada);
    printf("\nDeseja continuar o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if (ch == 'S'){
      sl_count=0; comesada=0; semesada=0; mediasalarial=0;
      system("clear");
    }
  } while(ch == 'S');

  return 0;
}
