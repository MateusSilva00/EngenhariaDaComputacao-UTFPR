// Questão 3 (3,3 pontos) - Faça um programa que receba uma palavra e imprima conforme o exemplo a seguir:
// Exemplo: NATAL
// Como a palavra NATAL tem 5 letras, a impressão fica:
// NATAL
// NATAL NATAL
// NATAL NATAL NATAL
// NATAL NATAL NATAL NATAL
// NATAL NATAL NATAL NATAL NATAL
// NATAL NATAL NATAL NATAL
// NATAL NATAL NATAL
// NATAL NATAL
// NATAL

#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

int main(){

  int i, j;
  char ch, palavra[8];

  do {
    printf("Informe uma palavra.: ");
    __fpurge(stdin);//Estou usando linux, portanto o fflush(stdin) não funciona muito bem
    fgets(palavra, sizeof(palavra), stdin);

    for(i=0; i <= strlen(palavra); i++){
      for(j=0; j < i; j++){
        printf("%s  ", strtok(palavra, "\n"));
      }
      printf("\n");
    }
    for(i=strlen(palavra)-1; i>= 1; i--){
      for(j=0; j < i; j++){
        printf("%s  ", strtok(palavra, "\n"));
      }
      printf("\n");
    }

    printf("\n\nDeseja repetir o programa (S/N).: ");
    __fpurge(stdin);
    scanf("%c", &ch);
  } while(toupper(ch) == 'S');

  return 0;
}
