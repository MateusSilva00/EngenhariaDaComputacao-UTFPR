// (DESAFIO) Fazer um programa que receba um valor inteiro, que se refere a quantidade de linhas de um
// triângulo e um valor do tipo char, que se refere ao tipo do triângulo (que pode ser preenchido ou vazado).
// Implementar no próprio programa uma função que recebe como parâmetros esses valores e imprime um
// triângulo como no exemplo a seguir.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

void criaTriangulo(int x, char tipoTriangulo);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num;
  char ch, triangulo;
  do {
    printf("Informe a quantidade de linhas do triângulo.: ");
    scanf("%d", &num);
    printf("Vazado(V/v) ou Preenchido (P/p).: ");
    scanf(" %c", &triangulo);
    triangulo = toupper(triangulo);
    criaTriangulo(num, triangulo);
    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}

void criaTriangulo(int x, char tipoTriangulo){
  int i,j;
  switch (tipoTriangulo) {
    case 'V':
    for(i=1; i<=x; i++){
      for(j=1; j<=i; j++){
        if(i == j || i == x ||j == 1){
          printf("*");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }
      break;

    case 'P':
      for(i=1; i<=x; i++){
        for(j=1; j<=i; j++){
          printf("*");
        }
        printf("\n");
      }
      break;

    default:
      printf("Opção Inválida!\n");
  }
}
