#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int idade, qtbr=0, qtgringo=0, qtcurso=0, idademedia = 0, count=0, menor=0;
  char nacionalidade, c_superior;

  while (idade > 0) {
    printf("Informe a idade.: ");
    scanf("%d", &idade);
    printf("Informe a nacionalidade (B - Brasileiro ou E - Estrangeiro).: ");
    scanf(" %c", &nacionalidade);
    nacionalidade = toupper(nacionalidade);
    printf("Possui curso superior (S - Sim ou N - Não).: ");
    scanf(" %c", &c_superior);
    c_superior = toupper(c_superior);

    if (nacionalidade == 'B'){
      qtbr++;
      if (c_superior == 'N'){
        count++;
        idademedia = idademedia + idade;
      }
    }
    else if (nacionalidade == 'E'){
      qtgringo++;
      if (c_superior == 'S'){
        if (menor == 0){
          menor = idade;
        }
        else if (idade < menor){
          menor = idade;
        }
      }
    }
  }

  idademedia = idademedia / count;

  printf("Quantidade de brasileiros: %d\nQuantidade de estrangeiros: %d", qtbr,qtgringo);
  printf("\nA idade media dos brasileiros sem curso superior é.: %d\nA menor idade de estrangeiros com curso superior é.: %d", idademedia, menor);

  return 0;
}
