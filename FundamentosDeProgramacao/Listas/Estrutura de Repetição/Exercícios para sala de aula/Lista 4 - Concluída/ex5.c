#include <stdio.h>
#include <ctype.h>

int main (){

  int count=0;
  char ch;
  do {
    printf("Informe um caractere.: ");
    fflush(stdin);
    scanf(" %c", &ch);

      if (ch == 65){
        count++;
      }

  } while(ch != '0');

  printf("O caractere 'A' foi digitado %d vezes", count);


  return 0;
}
