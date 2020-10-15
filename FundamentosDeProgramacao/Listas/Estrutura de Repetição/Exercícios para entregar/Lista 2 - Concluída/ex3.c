#include <stdio.h>
#include <ctype.h>

int main (){

  int caracter=0, vogaismin = 0;
  char ch;
  do {
    printf("Informe um caractere.: ");
    fflush(stdin);
    scanf(" %c", &ch);

      if (ch == 97 || ch == 101 || ch == 105 || ch == 111 || ch == 117){
        vogaismin++;
      }
      if (ch != '0'){
        caracter++;
      }

  } while(ch != '0');

  printf("O total de vogais minusculas eh.:%d\nO total de caracteres digitado e.:%d", vogaismin, caracter);


  return 0;
}
