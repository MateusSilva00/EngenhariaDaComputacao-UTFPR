// Ler caracteres até ser informado o caractere zero que representa a saída e não deve ser considerado
// no processamento. Quando o caractere informado é uma letra minúscula ou minúscula, verificar se o número correspondente ao
// código ASCII desse caractere é primo. Fazer o percentual dos caracteres informados que não são letras maiúsculas ou minúsculas.
// Exemplo: se for informado o caractere ‘a’, o valor correspondente desse caractere é 97. Então, verificar se 97 é um número primo,
// se for, informar que o mesmo é um número primo, caso contrário, informar que 97 não é um número primo. Se ao todo foram
// informados 30 caracteres e destes 15 não são letras, ou seja, não estão entre ‘a’ a ‘z’ e ‘A’ a ‘Z’ ou entre 97 a 122 e 65 a 90, o
// percentual é 50%.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int var, i, countprimo=0, countall=0;
  float countchar=0;
  char ch, continuar;

  do {
    do {
      printf("Informe um caractere ('0' para sair).: ");
      scanf(" %c", &ch);
      var = ch;

      if((var >= 65 && var <= 90) || (var >=97 && var <=122)){

        for(i = 1; i<=var; i++){
          if(var % i == 0){
            countprimo++;
          }
        }

        if(countprimo == 2){
          printf("%c que corresponde a %d na tabela ASCII é primo!\n", ch, var);
        }

        else{
          printf("%c que corresponde a %d na tabela ASCII não primo!\n", ch, var);
        }

        countprimo=0;
        countchar++;
      }

      if(ch != '0'){
        countall++;
      }

    } while(ch != '0');

    printf("Caracteres letras %.2f\nTotal digitado %d", countchar, countall);
    countchar = (countchar/countall) * 100;
    printf("\n\nPerentual de caracteres que não são letras.: %.2f%%", countchar);

    printf("\nDeseja executar o programa novamente (S/s para SIm) ?");
    scanf(" %c", &continuar);

    continuar = toupper(continuar);

    if (continuar == 'S'){
      countprimo=0, countall=0; countchar=0; printf("\n");
    }
    else{
      printf("\nBye!");
    }

  } while(continuar == 'S');

  return 0;
}
