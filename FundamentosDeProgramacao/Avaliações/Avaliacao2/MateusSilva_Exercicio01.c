// a) Inserir uma substring em uma string. Deve ser informada a posição inicial na qual deve ser iniciada a inserção.
// b) Copiar uma string para outra string de trás para frente, ou seja, invertendo-a, sem inverter a string original.
// c) Contar quantas vezes uma substring ocorre em uma string. A substring pode ser composta por 1 a n caracteres e pode ser igual ou
// maior que a string. Exemplo: string dia, substring diário. Nesse caso, a substring não está contida na string.
// d) Verificar se uma substring está no final de uma string.
// e) A criptografia baseada na Cifra de Cesar consiste em deslocar os caracteres de um texto ‘n’ caracteres para frente. Implemente uma
// função para deslocar um texto n caracteres para frente ou n caracteres para trás. Os espaços em branco devem ser mantidos e outros
// sinais, como de pontuação também. Na tabela ASCII: 'a' é 97, 'b' é 98, 'z' é 122, 'A' é 65, 'B' é 66, 'Z' é 90.
// Fazer um programa para usar as funções geradas.

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


//FUNÇÃO A
void insereSubString(char string[], char substring[], int tam_string, int tam_substring, int pos_substring){
  int i, j, x=0, tam_novaString = tam_string + tam_substring;
  char novaString[tam_novaString];
  for(i=0; i < tam_novaString; i++){
    if(i == pos_substring){
      for(j=0; j < tam_substring-1; j++){
        novaString[x] = substring[j];
        x++;
      }
    }
    novaString[x] = string[i];
    x++;
  }

  printf("%s", novaString);
}

//FUNÇÃO B
void inverteString(char string[]){
  int i;
  for(i=strlen(string); i > 0; i--){
    putchar(string[i]);
  }
}

//FUNÇÃO C
int ocorrenciaString(char string[], char substring[]){
  int i, j, aux=0, x, count=0;
  int tam_substring = strlen(substring) - 1;

  for(i=0; i < strlen(string); i++){

    if(substring[0] == string[i]){

      aux = i;
      x=0;

      for(j=0; j < tam_substring; j++){
        if(substring[j] == string[aux]){
          x++;
        }
        aux++;
      }

      if(x >= tam_substring){
        count++;
      }
    }
  }

  return count;
}

//FUNCAO D
void substringFinal(char string[], char substring[]){
  int i, j, aux=0, x, tam_substring = strlen(substring) - 1;
  for(i=0; i < strlen(string); i++){
    if(string[i] != ' ' && string[i-1] == ' '){

      if(substring[0] == string[i]){
        aux = i;
        x=0;

        for(j=0; j < tam_substring; j++){
          if(substring[j] == string[aux]){
            x++;
          }
          aux++;
        }

        if(x >= tam_substring && string[aux+1] == '\0'){
          printf("Sim");
        }
        else{
          printf("Nao");
        }
      }
    }//fim do primeiro if

  }
}

//FUNCAO E
void criptografia(char string[], int deslocar){
  int i;
  for(i=0; i <= strlen(string); i++){
    if(string[i] >= 97 && string[i] <= 122){
      string[i] += deslocar;
      if(string[i] < 97){
        string[i]+= 26;
      }
      if(string[i] > 122){
        string -= 26;
      }
    }

    if(string[i] >= 65 && string[i] <= 90){
      string[i] += deslocar;
      if(string[i] < 65){
        string[i] += 26;
      }
      if(string[i] > 90){
        string -= 26;
      }
    }

  }

  printf("%s", string);
}

int main(){

  int tam_string, tam_substring, pos_substring;
  char string[150], substring[25];

  // // //EXERCICIO A
  // // printf("EXERCICIO DA FUNCAO A\n");
  // //
  // // printf("Informe uma string.: ");
  // // __fpurge(stdin);
  // // fgets(string, sizeof(string), stdin);
  // // tam_string = strlen(string) - 1;
  // // printf("Tamanho da string.: %d", tam_string);
  // //
  // // printf("\nInforme uma substring.: ");
  // // __fpurge(stdin);
  // // fgets(substring, sizeof(substring), stdin);
  // // tam_substring = strlen(substring);
  // // printf("Informe uma posição (menor ou igual a %d) na string para inserir a substring.: ", tam_string);
  // // scanf("%d", &pos_substring);
  // //
  // // printf("\n\n=== SUBSTRING NA STRING ===\n");
  // // insereSubString(string, substring, tam_string, tam_substring, pos_substring);
  // //
  // // //EXERCICIO B
  // // printf("EXERCICIO DA FUNCAO B\n");
  // // printf("\n\nInforme um string.: ");
  // // __fpurge(stdin);
  // // fgets(string, sizeof(string), stdin);
  // // printf("=== STRING INVERTIDA ===\n");
  // // inverteString(string);
  // //
  // // //EXERCICIO C
  // // printf("EXERCICIO DA FUNCAO C\n");
  // // printf("\n\nInforme um string.: ");
  // // __fpurge(stdin);
  // // fgets(string, sizeof(string), stdin);
  // //
  // // printf("\nInforme uma substring.: ");
  // // __fpurge(stdin);
  // // fgets(substring, sizeof(substring), stdin);
  // //
  // // printf("\n\n=== OCORRENCIAS DA SUBSTRING ===\n");
  // // printf("Substring '%s'\nOcorrencias.: %d", strtok(substring,"\n"), ocorrenciaString(string, substring));
  //
  // //EXERCICIO D
  printf("EXERCICIO DA FUNCAO D\n");
  printf("\n\nInforme um string.: ");
  __fpurge(stdin);
  fgets(string, sizeof(string), stdin);

  printf("\nInforme uma substring.: ");
  __fpurge(stdin);
  fgets(substring, sizeof(substring), stdin);

  printf("\n\n=== SUBSTRING NO FINAL DA STRING ===\n");
  substringFinal(string, substring);
  //
  //EXERCICIO E
  // printf("EXERCICIO DA FUNCAO E\n");
  // int deslocamento;
  // printf("\n\nInforme um string.: ");
  // __fpurge(stdin);
  // fgets(string, sizeof(string), stdin);
  //
  // printf("Informe o deslocamento.: ");
  // scanf("%d", &deslocamento);
  //
  // printf("\n\n=== CRIPTOGRAFIA ===\n");
  // criptografia(string, deslocamento);



  return 0;
}
