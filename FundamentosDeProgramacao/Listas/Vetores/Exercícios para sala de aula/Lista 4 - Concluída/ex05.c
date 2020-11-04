#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int i;
  char texto[150], ch;
  do {
    printf("Informe um texto com ate 150 caracteres.: ");
    fgets(texto, sizeof(texto), stdin);
    printf("\n=== TEXTO INVERSO ===\n");
    for(i=strlen(texto); i >= 0; i--){
      putchar(texto[i]);
    }
    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar(); // lê o caracter da nova linha
  } while(toupper(ch) == 'S');

  return 0;
}
