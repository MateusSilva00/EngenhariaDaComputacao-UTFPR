#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){
  setlocale(LC_ALL, "Portuguese");

  int ch_num;
  char ch;

  printf("Digite um caracter.: ");
  scanf("%c", &ch);
  ch = toupper(ch);

  if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
    printf("O caracter digitado pertence ao albafeto\n");

    switch (ch) {
      case 'A':
        printf("VOGAL %c\n", ch);
      break;

      case 'E':
        printf("VOGAL %c\n", ch);
      break;

      case 'I':
        printf("VOGAL %c\n", ch);
      break;

      case 'O':
        printf("VOGAL %c\n", ch);
      break;

      case 'U':
        printf("VOGAL %c\n", ch);
      break;

      default:
        printf("CONSOANTE %c\n", ch);
    }
  }

  else {
    printf("O caracter digitado não pertence ao alfabeto\n");
  }

  return 0;
}
