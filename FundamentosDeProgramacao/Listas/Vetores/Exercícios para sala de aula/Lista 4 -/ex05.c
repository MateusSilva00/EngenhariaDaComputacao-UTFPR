#include <stdio.h>
#include <string.h>

int main(){

  int i;
  char texto[150];
  printf("Informe um texto com ate 150 caracteres.: ");
  fgets(texto, sizeof(texto), stdin);
  for(i=strlen(texto); i >= 0; i--){
    putchar(texto[i]);
  }

  return 0;
}
