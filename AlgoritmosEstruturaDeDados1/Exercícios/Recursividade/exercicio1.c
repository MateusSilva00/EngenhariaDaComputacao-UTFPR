// 1.    Faça uma função recursiva que receba uma string e imprima todos os seus caracteres.
#include <stdio.h>
#include <string.h>

void imprimeTexto(char text[], int size, int cont){
  if(cont < size-1){
    putchar(text[cont]);
    printf("-");
    imprimeTexto(text, size, cont+1);
  }
}

int main(){

  int size;
  char texto[100];

  printf("Digite uma frase.: ");
  fgets(texto, sizeof(texto), stdin);
  size = strlen(texto);

  imprimeTexto(texto, size, 0);

}
