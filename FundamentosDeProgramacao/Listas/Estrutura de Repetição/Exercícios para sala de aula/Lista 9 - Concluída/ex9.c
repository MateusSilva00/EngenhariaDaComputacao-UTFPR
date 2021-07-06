#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int idade, qtAgro=0, qtNAgro=0, qtPato=0, menor=0;
  float mediaAgro=0;
  char curso, reside, ch;

  do {
    do {
      printf("Informe a idade do aluno.: ");
      scanf("%d", &idade);
      if(idade > 0){
        do {
          printf("Informe o curso (Q/q/A/a).: ");
          scanf(" %c", &curso);
          curso = toupper(curso);
          if(curso != 'Q' && curso != 'A'){
            printf("Caracter inválido! Tente novamente!\n");
          }
          else{
            if(curso == 'A'){
              qtAgro++;
              mediaAgro = mediaAgro + idade;
            }
            else{
              qtNAgro++;
            }
            do {
              printf("Reside em Pato Branco (S/s/N/n) ?");
              scanf(" %c", &reside);
              reside = toupper(reside);
              if(reside !='S' && reside !='N'){
                printf("Caracter inválido! Tente novamente!\n");
              }
              else if(reside == 'S'){
                qtPato++;
              }
              else if(reside == 'N'){
                if(menor == 0){
                  menor = idade;
                }
                if(idade < menor){
                  menor = idade;
                }
              }
            } while(reside != 'S' && reside != 'N');
            printf("\n");
          }
        } while(curso != 'Q' && curso != 'A');
      }
    } while(idade > 0);

    mediaAgro = mediaAgro / qtAgro;
    printf("\nA media de idade dos alunos do curso de Agronomia é.: %.2f", mediaAgro);
    printf("\nA quantidade de alunos que residem em Pato Branco é.: %d", qtPato);
    printf("\nA menor idade entre alunos que não residem em Pato Branco é.: %d", menor);
    printf("\nA quantidade de alunos que não cursam Agronomia.: %d", qtNAgro);

    printf("\n\nDeseja repetir o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if (ch == 'S'){
      mediaAgro=0; qtAgro=0; qtNAgro=0; qtPato=0; menor=0; printf("\n");
    }
  } while(ch == 'S');

  return 0;
}
