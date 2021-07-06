#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ContarCaracteres(char texto[]);
int ConverteCharParaNumero(char ch);
int verificaPrimo(int num);

int main(){

  char texto[150], ch;

  do {
    int soma = 0;
    printf("Informe um texto.: ");
    // fgets(texto, sizeof(texto), stdin);
    gets(texto);

    for(int i = 0; i<=strlen(texto); i++){
      if(texto[i] != ' ' && texto[i] != '\0'){
        putchar(texto[i]);
        soma = soma + ConverteCharParaNumero(texto[i]);
      }

      else{
        printf(" = %d", soma);
        if(verificaPrimo(soma) == 1){
          printf(" ==> Prima\n");
        }
        else{
          printf(" ==> Nao prima\n");
        }
        soma = 0;
      }
    }

    printf("\nDeseja continuar no programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');

  return 0;
}

int ContarCaracteres(char texto[]){
  int i, j=strlen(texto), countCaracter = 0;
  for(i=0; i<j; i++){
    if(texto[i] != ' ' && texto[i] != '\n'){
      countCaracter++;
    }
  }
  return countCaracter;
}

int ConverteCharParaNumero(char ch){
  int i, numero;
  if(ch >= 'a' && ch <= 'z'){
    numero = 0;
    for(i = 97; i<=ch; i++){
      numero++;
    }
  }

  else if(ch >= 'A' && ch <= 'Z'){
    numero = 26;
    for(i = 65; i<=ch; i++){
      numero++;
    }
  }
  return numero;
}

int verificaPrimo(int num){
  int i = 2;
  if(num == 1){
    return 0;
  }

  for(i; i <= num/2; i++){
    if(num % i == 0){
      return 0;
      break;
    }
  }
  return 1;
}
