#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int idade, profissional = 1, qtaut=0, count=0;
  float mediafun = 0;
  char categoria;

  do {
    printf("Insira a idade do profissional <%d> .: ", profissional);
    scanf("%d", &idade);
    if (idade <= 0){
      printf("Idade Inválida!\n");
    }
    else {
      profissional++;

      do{
        printf("Qual a categoria? A - Autônomo  F - Funcionário\nEnter.: ");
        fflush(stdin);
        scanf(" %c", &categoria);
        categoria = toupper(categoria);
        if (categoria != 'A' && categoria != 'F'){
          printf("\nCategoria Inválida!");
        }
        else if (categoria == 'A' && idade < 18){
          qtaut++;
        }
        else if (categoria == 'F' && idade > 18){
          mediafun = mediafun + idade;
          count++;
        }

      } while(categoria != 'A' && categoria != 'F');
    }
    printf("\n");
  } while(idade > 0);

  mediafun = mediafun / count;
  printf("\nO total de profissionais autônomos com menos de 18 anos.: %d", qtaut);
  printf("\nA média das idades dos funcionários com mais de 18 anos.: %.2f", mediafun);

  return 0;
}
