// Faça uma função recursiva que receba uma string e imprima todos os seus caracteres em ordem inversa
// (do final para o começo).
#include <stdio.h>
#include <string.h>

void imprimeTexto(char text[], int size, int cont){
  if(cont < size-1){
    imprimeTexto(text, size, cont+1);
    putchar(text[cont]);
    printf("-");
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
