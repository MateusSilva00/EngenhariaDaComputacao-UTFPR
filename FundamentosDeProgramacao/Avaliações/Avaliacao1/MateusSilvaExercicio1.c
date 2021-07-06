// Fazer um programa que lê n números inteiros e informa se os números lidos estão ou não em ordem
// crescente. n é informado pelo usuário e é um valor positivo e maior que 0. Caso a sequência não esteja ordenada, o programa
// deverá interromper o processo de repetição no momento em que a sequência deixar de ser ordenada. Além disso, o programa
// deverá encontrar o maior e o menor elemento da sequência e imprimi-los na tela.
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int i=1, num, maior, menor, valor, aux;
  printf("Digite o valor de n.: ");
  scanf("%d", &num);
  do {
    printf("Informe o valor %d.: ", i);
    scanf("%d", &valor);
    if(i == 1){
      maior = valor;
      menor = valor;
      aux = valor;
    }
    else if(valor > maior){
      maior = valor;
    }
    else if(valor < menor){
      menor = valor;
    }
    i++;

    if (valor < aux){
      printf("Sequência não ordenada");
      break;
    }

    else{
      aux = valor;
    }

    if(i > num){
      printf("Sequencia ordenada!");
    }

  } while(i <= num || valor < aux);


  printf("\nMaior valor da sequencia: %d\nMenor valor da sequência: %d", maior, menor);

  return 0;
}
