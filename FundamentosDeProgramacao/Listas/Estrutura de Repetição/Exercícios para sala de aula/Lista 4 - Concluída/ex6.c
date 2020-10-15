#include <stdio.h>
#include <ctype.h>

int main (){

  int caracter=0, upper = 0, lower=0, nletter=0;
  char ch;
  do {
    printf("Informe um caractere.: ");
    fflush(stdin);
    scanf(" %c", &ch);

    if (ch == '0'){
      break;
    }

    if ((ch >= 65 && ch <=90) || (ch >= 97 && ch <= 122)){
      caracter++;
      if (ch >= 97 && ch <= 122){
        lower++;
      }
      else upper++;
    }
    else nletter++;



  } while(ch != '0');

  printf("Caracters %d\nMaiusculas %d\nMinusculas %d\nNao letras %d", caracter, upper, lower, nletter);


  return 0;
}
