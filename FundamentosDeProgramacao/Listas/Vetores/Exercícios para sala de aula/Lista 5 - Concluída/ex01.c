#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int i, j=0;
  char texto[150], semEspaco[150], ch;
  do {
    printf("Informe um texto com ate 150 caracteres.: ");
    fgets(texto, sizeof(texto), stdin);

    for (i=0; i<=strlen(texto)-1; i++) {
      if(texto[i] != ' '){
        semEspaco[j] = texto[i];
        j++;
      }
    }

    printf("Texto sem espacos.: %s", semEspaco);
    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar(); // lê o caracter da nova linha
  } while(toupper(ch) == 'S');

  return 0;
}
