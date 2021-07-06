// Fazer um programa que receba um valor inteiro, que se refere a quantidade de linhas de um
// triângulo. Implementar no próprio programa uma função que recebe como parâmetro esse valor e imprime um
// triângulo.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
void criaTriangulo(int x, char caracter);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num;
  char ch, caracter;
  do {
    printf("Informe a quantidade de linhas do triângulo.: ");
    scanf("%d", &num);
    printf("Informe o caracter que deseja exibir no triângulo.: ");
    scanf(" %c", &caracter);
    criaTriangulo(num, caracter);
    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}

void criaTriangulo(int x, char caracter){
  int i, j, fator = 1, espacos;
  espacos = 1 + ((x -1)*2); //O espaço é dado em um progressão aritmética
  printf("\n");//x = 10
  for(i=0; i<x; i++){
    for(j=0; j < espacos; j++){
      printf(" "); //Laço para criar espaços
    }
    for(j=0; j < fator; j++){
      printf(" %c", caracter);//Laço para colocar os caracteres
    }
    printf("\n");
    fator+=2;
    espacos-=2;
  }
}
