// Fregueses: Quantas pessoas estão no restaurante (nenhuma, algumas, cheio)?
// Tempo de espera (em minutos): 0-10, 10-30, 30-60, >60.
// Alternativa: Há um restaurante alternativo na redondeza?
// Reserva: Foi feita uma reserva?
// Bar: Existe um bar confortável onde possa se esperar?
// Sex/Sab: É sexta ou sábado?
// Faminto: Está com fome?
// Chovendo: Está chovendo lá fora?
// As entradas são do tipo char, exceto o tempo de espera que pode ser int. Portanto, estabeleça
// uma letra para cada entrada esperada, por exemplo 'S' para sim e 'N' para não.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL, "Portuguese");
  char respostas;
  int tempo_espera;

  printf("Quantas pessoas estão no restaurante\nN - nenhuma  A - algumas  C - cheio\n");
  scanf("%c", &respostas); respostas = toupper(respostas);


  if (respostas == 'N'){
    printf("Não deve esperar");
  }
  else if (respostas == 'A'){
    printf("Deve esperar");
  }
  else if (respostas == 'C'){
    printf("\nQual tempo de espera estimado em minutos? ");
    scanf("%d", &tempo_espera);

    if (tempo_espera > 60){
      printf("Não deve esperar");
    }

    else if (tempo_espera < 10){
      printf("Deve esperar");
    }

    else if (tempo_espera >= 10 && tempo_espera < 30){
      printf("\nVocê está fome ?\nS - Sim      N - Não\n");
      scanf(" %c", &respostas); respostas = toupper(respostas);

      if (respostas == 'N'){
        printf("Deve esperar");
      }

      else if (respostas == 'S'){
          printf("\nHá um restaurante alternativo na redondeza?\nS - Sim      N - Não\n");
          scanf(" %c", &respostas); respostas = toupper(respostas);

          if (respostas == 'N'){
            printf("\nDeve esperar");
          }

          else if(respostas == 'S'){
            printf("\nEstá chovendo lá fora?");
            scanf(" %c", &respostas); respostas = toupper(respostas);
            if (respostas == 'S'){
              printf("Deve esperar");
            }
            else if(respostas == 'N'){
              printf("Não deve esperar");
            }
          }
        }
      }

    else if (tempo_espera >= 30 && tempo_espera <= 60){
        printf("\nHá um restaurante alternativo na redondeza?\nS - Sim      N - Não\n");
        scanf(" %c", &respostas); respostas = toupper(respostas);

        if (respostas == 'S'){
          printf("\nÉ sexta ou sábado?\nS - Sim      N - Não\n");
          scanf(" %c", &respostas); respostas = toupper(respostas);
          if(respostas == 'N'){
            printf("Não deve esperar");
          }
          else if(respostas =='S'){
            printf("Deve esperar");
          }
        }

        else if (respostas =='N'){
            printf("\nFoi feita uma reserva?\nS - Sim      N - Não\n");
            scanf(" %c", &respostas); respostas = toupper(respostas);
            if (respostas == 'S'){
              printf("Deve esperar");
            }
            else if (respostas == 'N'){
              printf("\nExiste um bar confortável onde possa se esperar?\nS - Sim      N - Não\n");
              scanf(" %c", &respostas); respostas = toupper(respostas);
              if (respostas == 'S'){
                printf("Deve esperar");
              }
              else if (respostas == 'N'){
                printf("Não deve esperar");
              }
            }
        }
      }
    }

 return 0;

}
