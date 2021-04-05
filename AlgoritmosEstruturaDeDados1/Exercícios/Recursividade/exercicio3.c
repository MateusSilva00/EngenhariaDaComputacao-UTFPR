// 3.    Implemente uma função recursiva que recebe uma string e substitui as letras minúsculas por maiúsculas
// e vice-versa.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimeTexto(char text[], int size, int cont){
  if(cont < size-1){
    if(isupper(text[cont])){
      text[cont] = tolower(text[cont]);
      putchar(text[cont]);
      imprimeTexto(text, size, cont+1);
    }
    else{
      text[cont] = toupper(text[cont]);
      putchar(text[cont]);
      imprimeTexto(text, size, cont+1);
    }
  }
}

int main(){

  int size, i = 0;
  char texto[100];

  printf("Digite uma frase.: ");
  fgets(texto, sizeof(texto), stdin);
  size = strlen(texto);

  imprimeTexto(texto, size, i);

}
