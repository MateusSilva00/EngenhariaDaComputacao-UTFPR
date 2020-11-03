#include <stdio.h>

int verificarEspacos(char texto[]);
int verificarSemEspacos(char texto[]);

int main(){

  int i = 0, espacos, semEspacos;
  char texto[150];
  printf("Informe um texto com ate 150 caracteres.: ");
  fgets(texto, sizeof(texto), stdin);
  espacos = verificarEspacos(texto);
  printf("\nNúmero de caracteres com espaco.: %d", espacos);
  semEspacos = verificarSemEspacos(texto);
  printf("\nNúmero de caracteres sem espaco.: %d", semEspacos);

  return 0;
}

int verificarEspacos(char texto[]){
  int i = 0;
  while(texto[i] != '\0'){
    i++;
  }
  return i;
}

int verificarSemEspacos(char texto[]){
  int i=0, semEspacos=0;
  while(texto[i] != '\0'){
    if(texto[i] != ' '){
      semEspacos++;
    }
    i++;
  }
  return semEspacos;
}
