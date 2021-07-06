#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int qtHomi = 0, qtMuie=0, total;
  float altura, mediaMuie=0, mediaHomi=0, percentualHomi, percentualMuie;
  char sexo, ch;

  do {
    do {
      printf("Informe a altura.: ");
      scanf("%f", &altura);
      if(altura <= 0){
        break;
      }
      else{
        do {
          printf("Informe o sexo.: ");
          scanf(" %c", &sexo);
          sexo = toupper(sexo);
          if (sexo != 'M' && sexo != 'F'){
            printf("Caracter inválido! Informe M ou F!\n");
          }
          else if(sexo == 'M'){
            qtHomi++;
            mediaHomi = mediaHomi + altura;
          }
          else if(sexo == 'F'){
            qtMuie++;
            mediaMuie = mediaMuie + altura;
          }

        } while(sexo != 'M' && sexo != 'F');
        printf("\n");
      }
    } while(altura > 0);
    total = qtHomi+qtMuie;
    mediaMuie = mediaMuie / qtMuie;
    percentualMuie = ((float)qtMuie/(float)total)*100;
    printf("\n=== MULHERES === \nQuantidade: %d\nMédia de altura: %.2f\nPercentual.: %.2f\n\n", qtMuie, mediaMuie, percentualMuie);

    mediaMuie = mediaHomi / qtHomi;
    percentualHomi = ((float)qtHomi/(float)total)*100;
    printf("\n=== HOMENS === \nQuantidade: %d\nMédia de altura: %.2f\nPercentual.: %.2f\n\n", qtHomi, mediaHomi, percentualHomi);

    printf("\nDeseja continuar o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      mediaMuie=0; mediaHomi=0; qtHomi = 0; qtMuie=0; printf("\n");
    }
  } while(ch == 'S');

  return 0;
}
