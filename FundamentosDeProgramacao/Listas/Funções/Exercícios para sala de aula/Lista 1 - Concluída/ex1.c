#include <stdio.h>
#include <locale.h>
#include <ctype.h>

void operacoes(int x, int y, char tipo){
  switch (tipo) {
    case 'A':
      printf("Adição.: %d", x+y) ;
      break;

    case 'S':
      printf("Subtração.: %d", x-y);
      break;

    case 'M':
      printf("Multiplicação.: %d", x*y);
      break;

    case 'D':
      printf("Divisão.: %d", x/y);
      break;

    case 'R':
      printf("Resto.: %d", x%y);
      break;

    default:
      printf("Valor inválido!\n");
  }
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num1, num2;
  char opcao, ch;
  do {
    printf("A - Adicionar\nS - Subtrair\nM - Multiplicação\nD - Dividir\nR - Resto\nOpção.: ");
    scanf(" %c", &opcao);
    opcao = toupper(opcao);
    printf("Informe o primeiro valor.: ");
    scanf("%d", &num1);
    printf("Informe o segundo valor.: ");
    scanf("%d", &num2);
    operacoes(num1,num2,opcao);

    printf("\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    printf("\n\n");
  } while(ch == 'S');

}
