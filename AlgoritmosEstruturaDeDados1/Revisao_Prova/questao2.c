// 2) Escreva uma função recursiva que recebe uma string e converte para o número inteiro equivalente. Ex: converte("1985")
// retorna 1985. Não é permitio utilizar funções prontas para isso! Dica: utilize a tabela ascii.
#include <stdio_ext.h>
#include <string.h>
#include <math.h>

int convertNum(char arr[]){

  int tam = strlen(arr) - 1, num=0, i, j;
  printf("Tamanho do vetor: %d", tam);
  j = tam-1;

  for(i=0; i < tam; i++){
    if(arr[i] >= 49 && arr[i] <= 57){
      switch (arr[i]) {
        case 49:
        num = num + (1 * pow(10, j));
        break;

        case 50:
        num = num + (2 * pow(10, j));
        break;

        case 51:
        num = num + (3 * pow(10, j));
        break;

        case 52:
        num = num + (4 * pow(10, j));
        break;

        case 53:
        num = num + (5 * pow(10, j));
        break;

        case 54:
        num = num + (6 * pow(10, j));
        break;

        case 55:
        num = num + (7 * pow(10, j));
        break;

        case 56:
        num = num + (8 * pow(10, j));
        break;

        case 57:
        num = num + (9 * pow(10, j));
        break;
      }
    }
    j--;
  }

  return num;
}

int main(){

  char numero[10];
  printf("Digite um número.: ");
  fgets(numero, sizeof(numero), stdin);


  printf("\nNúmero convertido %d\n", convertNum(numero));

  return 0;
}
