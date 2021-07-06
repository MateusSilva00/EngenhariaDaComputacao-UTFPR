// Faça um programa que apresente o menu a seguir e permita ao usuário escolher a
// opção desejada, receba os dados necessários para executar a operação e mostre o
// resultado.
// Menu de opções:
// 1 – Mostra os números em ordem crescente
// 2 – Mostra os números em ordem decrescente
// 3 - Mostra os números que são múltiplos de 2
// Digite a opção desejada:
// Observações: Ler um conjunto de 4 valores inteiros: opcao, a, b e c. A seguir:
// a) Se opcao = 1 escrever os três valores a, b e c em ordem crescente.
// b) Se opcao = 2 escrever os três valores a, b e c em ordem decrescente.
// c) Se opcao = 3 escrever se os valores a, b e c são múltiplos de 2.


#include <stdio.h>
#include <locale.h>

int main (){

  setlocale(LC_ALL,"Portuguese");
  int a, b, c, opcao, maior, menor, meio, div2a,div2b,div2c;
  printf("Insira o valor de <a>.: ");
  scanf("%d", &a);
  printf("Insira o valor de <b>.: ");
  scanf("%d", &b);
  printf("Insira o valor de <c>.: ");
  scanf("%d", &c);
  printf("Menu de Opções:\n1 – Mostra os números em ordem crescente\n2 – Mostra os números em ordem decrescente\n3 -Mostra os números que são múltiplos de 2\n");
  scanf("%d", &opcao);

// Verificando
  if (a < b && a < c){
    menor = a;
    if (b < c ){
      meio = b; maior = c;
    }
    else{
      meio = c; maior = b;
    }
  }

  else if (b < a && b < c){
    menor = b;
    if (a < c){
      meio = a; maior = c;
    }
    else{
      meio = c; maior = a;
    }
  }

  else if (c < a && c < b){
    menor = c;
    if (a < b){
      meio = a; maior = b;
    }
    else{
      meio = b; maior = a;
    }
  }

  switch (opcao) {
    case 1:
      printf("Ordem crescente: %d %d %d", menor, meio, maior);
    break;

    case 2:
      printf("Ordem decrescente: %d %d %d", maior, meio, menor);
    break;

    case 3:
      div2a = a % 2; div2b = b % 2; div2c = c % 2;

        if (div2a == 0 || div2b == 0 || div2c == 0){

          if (div2a == 0 && div2b == 0 && div2c == 0){
            printf("%d, %d e %d são multiplos de 2", a , b,c);
          }

          else if ((div2a == 0 || div2b == 0) && div2c != 0) {
            if (div2a == 0 && div2b == 0){
              printf("Apenas %d e %d são multiplos de 2", a, b);
            }
            else if (div2a == 0){
              printf("Apenas %d é multiplo de 2", a);
            }
            else printf("Apenas %d é multiplo de 2", b);
          }

          else if ((div2a == 0 || div2c == 0) && div2b != 0) {
            if (div2a == 0 && div2c == 0){
              printf("Apenas %d e %d são multiplos de 2", a, c);
            }
            else if (div2a == 0){
              printf("Apenas %d é multiplo de 2", a);
            }
            else printf("Apenas %d é multiplo de 2", c);
          }

          else if ((div2c == 0 || div2b == 0) && div2a != 0) {
            if (div2c == 0 && div2b == 0){
              printf("Apenas %d e %d são multiplos de 2", b, c);
            }
            else if (div2c == 0){
              printf("Apenas %d é multiplo de 2", c);
            }
            else printf("Apenas %d é multiplo de 2", b);
          }
        }
        else{
          printf("Nenhum número é múltiplo de 2!");
        }
    break;
  }

  return 0;
}
