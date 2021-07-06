// 3. (2,5) Crie uma função que utiliza uma pilha para verificar se uma frase é palíndroma. Esta
// função deve retornar 1 caso a frase seja palíndroma, e -1 caso não seja. Obs.:
// a) frases palíndromas são iguais se lidas tanto do início pro fim quanto do fim pro início.
// Ex: “roma me tem amor”.
// b) os espaços em branco devem ser ignorados e você pode assumir que a frase só tem
// caracteres minúsculos.
// c) pode existir um caractere que não se repete exatamente no meio da frase. Ex: “a
// grama é amarga”.
// d) você pode utilizar a função “strlen” ou outra para verificar o tamanho da string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaFrase(char str[], char str_invertida[]){
    int i, size = strlen(str), size_inv = strlen(str_invertida);
    if(size == size_inv){
      for(i=0; i < size; i++){
        if(str[i] != str_invertida[i])
          return 0;
      }
      return 1;
    }
    else return 0;
}

void inverter(char *string, char *frase_invertida){
  int j=0;
  int tamanho = strlen(string)-1;

  for(; tamanho >= 0; tamanho--){
    frase_invertida[j] = string[tamanho];
    j++;
  }
}

void removeEspaco(char *string){
  int j=0, qt_espacos=0;
  int tamanho = strlen(string)-1;

  for(int i=0; i < tamanho; i++){
    if(string[i] == ' '){
      qt_espacos++;
    }
  }

  char nova_frase[tamanho-qt_espacos];

  for(int i=0; i < tamanho; i++){
    if(string[i] != ' '){
      nova_frase[j] = string[i];
      j++;
    }
  }

  printf("%s\n", nova_frase);

}

int main(){

  int tamFrase, i, j=0, aux;
  char frase[50] = "a grama e amarga", frase_invertida[50];
  tamFrase = strlen(frase);

  inverter(frase, frase_invertida);
  printf("\nFrase: %s\nFrase Invertida: %s\n\n", frase, frase_invertida);

  removeEspaco(frase);

  aux = verificaFrase(frase, frase_invertida);
  if(aux){
    printf("\nA frase é palíndroma!\n");
  }
  else printf("A frase não é palíndroma!\n");

}
