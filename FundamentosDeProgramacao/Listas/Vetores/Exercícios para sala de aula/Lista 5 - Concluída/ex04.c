#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  int i, countPalavra;
  char texto[150], ch;

  do {
    countPalavra = 0;
    printf("Informe um texto.: ");
    fgets(texto, sizeof(texto), stdin);
    for(i = 0; i<=strlen(texto); i++){
      if( (texto[i] == ' ' && texto[i+1] != ' ') || (texto[i] != ' ' && texto[i] == '\n')){
        countPalavra++;
      }
    }

    printf("'%s' possui %d palavras", strtok(texto,"\n"), countPalavra);

    printf("\n\nDeseja continuar no programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();

  } while(toupper(ch) == 'S');

  return 0;
}
