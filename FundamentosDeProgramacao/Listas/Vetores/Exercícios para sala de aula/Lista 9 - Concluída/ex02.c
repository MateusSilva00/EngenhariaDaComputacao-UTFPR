#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

int contarPalavras(char texto[]);
void primeiroCaracter(char texto[]);
void ultimoCaracter(char texto[]);
void primeiraPalavra(char texto[]);

int main(){

  int quantidade_palavras;
  char texto[100], ch;

  do {

    printf("Informe uma frase de ate 100 caracteres.:\n");
    __fpurge(stdin);
    fgets(texto, sizeof(texto), stdin);

    quantidade_palavras = contarPalavras(texto);
    printf("'%s' possui %d palavras\n\n", strtok(texto, "\n"), quantidade_palavras);

    printf("Primeiro caracter de cada palavra\n");
    primeiroCaracter(texto);

    printf("\n\nUltimo caracter de cada palavra\n");
    ultimoCaracter(texto);

    printf("\n\nPrimeira palavra.: ");
    primeiraPalavra(texto);


    printf("\n\nDeseja repetir o programa (S/N) ? ");
    __fpurge(stdin);
    scanf("%c", &ch);

  } while(toupper(ch) == 'S');


  return 0;
}

int contarPalavras(char texto[]){
  int i, qt_palavras = 0;
  for(i=0; i < strlen(texto); i++){
    if(texto[i] != ' ' && (texto[i-1] == ' ' || texto[i+1] == '\0')){
      qt_palavras++;
    }
  }
  return qt_palavras;
}

void primeiroCaracter(char texto[]){
  int i;
  for(i=0; i <strlen(texto); i++){
    if(i == 0 && texto[i] != ' '){
      printf("%c ", texto[i]);
    }
    if(texto[i] != ' ' && texto[i-1] == ' '){
      printf("%c ", texto[i]);
    }
  }
}

void ultimoCaracter(char texto[]){
  int i;
  for(i=0; i <strlen(texto); i++){
    if(texto[i] != ' ' && (texto[i+1] == ' ' || texto[i+1] == '\0')){
      printf("%c ", texto[i]);
    }
  }
}

void primeiraPalavra(char texto[]){
  int i;
  for(i=0; i < strlen(texto); i++){
    if(texto[i] != ' '){
      printf("%c", texto[i]);
    }
    else break;
  }
}
