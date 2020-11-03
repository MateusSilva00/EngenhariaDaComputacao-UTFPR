#include <stdio.h>
#include <ctype.h>

int main(){
  int i = 0;
  char texto[150], vetVogais[5] = {0,0,0,0,0}, ch;

  do {
    printf("Informe um texto com ate 150 caracteres.: ");
    fgets( texto, sizeof(texto), stdin );
    while(texto[i] != '\0'){
      if(toupper(texto[i]) == 'A'){
        vetVogais[0]++;
      }
      if(toupper(texto[i]) == 'E'){
        vetVogais[1]++;
      }
      if(toupper(texto[i]) == 'I'){
        vetVogais[2]++;
      }
      if(toupper(texto[i]) == 'O'){
        vetVogais[3]++;
      }
      if(toupper(texto[i]) == 'U'){
        vetVogais[4]++;
      }
      i++;

    }
    printf("\nVogal\tQuantidade\n=================");
    printf("\nA/a\t %d\nE/e\t %d\nI/i\t %d\nO/o\t %d\nU/u\t %d", vetVogais[0], vetVogais[1], vetVogais[2],vetVogais[3], vetVogais[4]);

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    fflush(stdin);
    scanf("%c", &ch);
    i=0;
  } while(toupper(ch) == 'S');

  return 0;
}
