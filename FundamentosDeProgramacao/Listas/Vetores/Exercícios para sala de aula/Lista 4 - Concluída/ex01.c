#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

  char texto[100], ch;
  int count, i;
  do {
    count = 0; i = 0;
    printf("Informe um texto com até 100 caracteres.: ");
    fflush(stdin);
    fgets(texto, sizeof(texto), stdin);

    if(toupper(texto[0]) == 'A'){
      printf("%s ", texto);
    }

    else{
        while(texto[i] != '\0'){
          if(toupper(texto[i]) == 'O'){
            count++;
          }
          i++;
        }
      printf("O texto '%s' possui %d caracteres 'o' ", strtok(texto,"\n"), count);
    }

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');


  return 0;
}
