#include <stdio.h>
#include <string.h>
#include <ctype.h>

int comparaStrings(char str1[], char str2[]);


int main(){

  char texto[150], semEspaco[150], inversa[150], ch, retornoFuncao;

  do {
    int i, j=0, x=0;
    printf("Informe uma frase.: ");
    gets(texto);
    //Retirando espacos da String
    for (i=0; i<=strlen(texto)-1; i++) {
      if(texto[i] != ' '){
        semEspaco[j] = texto[i];
        j++;
      }
    }
    semEspaco[j] = '\0';
    printf("Texto sem espacos.: %s\n", semEspaco);

    //Invertendo A String
    for(i=strlen(semEspaco)-1; i>=0; i--){
      inversa[x] = semEspaco[i];
      x++;
    }
    inversa[x] = '\0';

    printf("Inverso da palavra.: %s\n", inversa);

    retornoFuncao = comparaStrings(semEspaco, inversa);
    if(retornoFuncao == 1){
      printf("É palindromo!\n");
    }
    else printf("Não é palindromo!\n");


    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf("%c", &ch);
    getchar(); // lê o caracter da nova linha
  } while(toupper(ch) == 'S');

  return 0;
}

int comparaStrings(char str1[], char str2[])
{
  int i=0;
  do {
    if(str1[i] != str2[i]){
      return 0;
      break;
    }
    i++;
  } while(i <= strlen(str1));
  return 1;
}
