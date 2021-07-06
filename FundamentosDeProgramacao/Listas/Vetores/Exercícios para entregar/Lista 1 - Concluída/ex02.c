#include <stdio.h>
#include <ctype.h>

int main(){

  char ch;
  do {
    float nota[2][3], media[3] = {0,0,0};
    int i,j, aprovado = 0, reprovado = 0;
    for(i=1; i <= 3; i++){
      for(j=1; j <= 2; j++){
        printf("Informe a nota %d do aluno %d.: ", j, i);
        scanf("%f", &nota[i][j]);
        media[i] = media[i] + nota[i][j];
      }
    }

    for(i=1; i<=3; i++){
      media[i] = media[i] / 2;
        if(media[i] >= 7){
          aprovado++;
        }
        else reprovado++;
    }

    printf("\n\n=== MEDIA ===\nALUNO\tMEDIA\n");
    for(i=1; i <= 3; i++){
      printf("%d\t%.2f\n", i, media[i]);
    }
    printf("\nNúmero de alunos com média maior que sete.: %d", aprovado);
    printf("\nNúmero de alunos com média menor que sete.: %d", reprovado);

    printf("\n\nDeseja repetir o programa (S/N).: ");
    scanf(" %c", &ch);
  } while(toupper(ch) == 'S');

  return 0;
}
