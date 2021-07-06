// Implemente um programa que adivinhe o "número mágico" entre 0 e 10. O programa deverá
// imprimir a mensagem "Certo! %d é o número mágico" quando o jogador acerta o número mágico,
// a mensagem "Errado, muito alto", caso o jogador tenha digitado um número maior que o número
// mágico e a mensagem "Errado, muito baixo", caso o jogador tenha digitado um número menor
// que o número mágico. O número mágico é produzido usando o gerador de números randômicos
// de C (função rand(), que exige o uso da biblioteca stdlib.h).
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main(){
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));


  int num_jogador, magic_number;

  printf ("\n*---------------------------------------------*");
  printf ("\n!                 NÚMERO MÁGICO               !");
  printf ("\n!      Entre com um número entre 1 a 10       !");
  printf ("\n*---------------------------------------------*");

    printf("\nDigite um número entre 1 e 10.: ");
    scanf("%d", &num_jogador);
    magic_number = (rand()%10 + 1);
    if (magic_number == num_jogador){
      printf("Certo! %d é o número mágico!", magic_number);
    }
    while (num_jogador != magic_number) {
      if(num_jogador > magic_number){
        printf("Errado, muito alto\nTente de novo.: ");
        scanf("%d", &num_jogador);
      }
      else {
        printf("Errado, muito baixo\nTente de novo.: ");
        scanf("%d", &num_jogador);
      }
      if (magic_number == num_jogador){
        printf("Certo! %d é o número mágico!", magic_number);
      }
    }

  return 0;
}
