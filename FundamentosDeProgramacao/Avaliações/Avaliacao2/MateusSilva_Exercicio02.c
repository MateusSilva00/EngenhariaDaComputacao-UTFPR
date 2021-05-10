// Ler uma string e contar quantos espaços sucessivos ela contém. Armazenar esses valores em um vetor e
// mostrar o vetor. Percorrer o vetor copiando apenas os números que são primos para um novo vetor. Mostrar o novo vetor (de números
// primos). Exemplo (traços representam espaços): --Curso---de----Tecnologia-----em-Analise-----e-Desenvolvimento--de---Sistemas----

#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

int primo(int num);

int main(){

  int i, j, numeros[150], aux;
  char texto[150], ch;

  do {
    j=0; aux=1;
    printf("Informe uma string.: ");
    __fpurge(stdin);
    fgets(texto, sizeof(texto), stdin);

    printf("\n\n=== STRING ===\n");
    printf("%s", texto);

    for(i=0; i < strlen(texto); i++){
      if(texto[i] == ' ' || texto[i+1] == ' '){
        numeros[j] = aux;
        aux++;

        if(texto[i] == ' ' && texto[i+1] != ' '){
          j++;
        }
      }
      else{
        aux = 0;
      }
    }

    printf("\n\n=== VETOR === \n");
    for(i=0; i < j; i++){
      printf("%d ", numeros[i]);
    }

    printf("\n\n=== PRIMOS === \n");
    for(i=0; i < j; i++){
      if(primo(numeros[i]) == 1){
        printf("%d ", numeros[i]);
      }
    }

    printf("\n\nDeseja repetir o programa (S/N).: ");
    __fpurge(stdin);
    scanf("%c", &ch);
  } while(toupper(ch) == 'S');

  return 0;
}

int primo(int num){
  int i=2;

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
