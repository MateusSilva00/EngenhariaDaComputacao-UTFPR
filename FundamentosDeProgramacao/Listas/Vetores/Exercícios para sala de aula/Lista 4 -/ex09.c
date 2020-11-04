#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificarString (char wordone[], char wordtwo[]);

int main(){

  int i, j, retornoFuncao;
  char palavra[15], ch, inversa[15];
  do {
    j = 0;
    printf("Informe uma palavra.: ");
    gets(palavra, sizeof(palavra), stdin);

    for(i=strlen(palavra)-1; i>=0; i--){
      inversa[j] = palavra[i];
      j++;
    }
    inversa[j] = '\0';
    
    retornoFuncao = verificarString(palavra, inversa);
    if(retornoFuncao == 1){
      printf("É palindromo!\n");
    }
    else printf("Não é palindromo!\n");

    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar();
  } while(toupper(ch) == 'S');

  return 0;
}

int verificarString(char wordone[], char wordtwo[]){
  int i=0;
  do {
    if(wordone[i] != wordtwo[i]){
      return 0;
      break;
    }
    i++;
  } while(i <= strlen(wordone));
  return 1;
}
