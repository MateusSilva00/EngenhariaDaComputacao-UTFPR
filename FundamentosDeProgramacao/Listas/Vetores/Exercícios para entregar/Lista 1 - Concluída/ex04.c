#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  srand(time(0));

  char ch, gabarito[10], resposta[10];
  do {
    int i, j, numAlunos, pontuacao;
    printf("Digite o número de alunos.: ");
    scanf("%d", &numAlunos);

    printf("\n=== GABARITO ===\n");
    for(i=1; i<=10; i++){
      do {
        printf("Digite o gabarito da prova para a questao %d.: ", i);
        scanf(" %c", &gabarito[i]);
        gabarito[i] = toupper(gabarito[i]);
        if(gabarito[i] < 65 || gabarito[i] > 69){
          printf("Caracter Inválido!\n");
        }
      } while(gabarito[i] < 65 || gabarito[i] > 69);
    }

    printf("\n=== RESPOSTAS DOS ALUNOS ===\n");
    for(i=1; i<= numAlunos; i++){
      pontuacao = 0;
      for(j=1; j <= 10; j++){
        do {
          printf("Digite a resposta do aluno %d para a questão %d.: ", i, j);
          scanf(" %c", &resposta[j]);
          resposta[j] = toupper(resposta[j]);
          if(resposta[j] < 65 || resposta[j] > 69){
            printf("Caracter Inválido!\n");
          }
          else{
            if(resposta[j] == gabarito[j]){
               pontuacao++;
             }
          }
        } while(resposta[j] < 65 || resposta[j] > 69);
      }

      printf("\n\nO aluno %d fez %d pontos!\n", i, pontuacao);
    }


    printf("\n\nDeseja repetir o programa (S/N).: ");
    scanf(" %c", &ch);
  } while(toupper(ch) == 'S');

  return 0;
}
