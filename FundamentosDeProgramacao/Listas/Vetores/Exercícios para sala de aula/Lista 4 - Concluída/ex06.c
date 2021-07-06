#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int i;
  char texto[150], ch;
  do {
    printf("Informe um texto com ate 150 caracteres.: ");
    fgets(texto, sizeof(texto), stdin);
    printf("\n=== TEXTO NA VERTICAL ===\n");
    for(i=0; i <= strlen(texto); i++){
      if(texto[i] == ' '){
        printf("\n");
      }
      else putchar(texto[i]);
    }
    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');

  return 0;
}
