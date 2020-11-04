#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int i=0;
  char texto[150], ch, palavra[150];
  do {
    printf("Informe um texto com ate 150 caracteres.: ");
    fgets(texto, sizeof(texto), stdin);
    while(texto[i] != ' '){
      palavra[i] = texto[i];
      i++;
    }
    printf("A string copiada é.: %s", palavra);
    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');

  return 0;
}
