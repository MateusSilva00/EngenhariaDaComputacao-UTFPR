#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){

  setlocale(LC_ALL,"Portuguese");
  int tempo=0;
  float massaXi;
  char ch;

  do {
    do {
      printf("\nInforme o valor da massa inicial.: ");
      scanf("%f", &massaXi);
      if (massaXi <= 0){
        printf("Valor Inválido!A massa deve ser positivo!\n");
      }
      else{
        do {
          printf("Massa: %.4f\n", massaXi);
          massaXi = massaXi / 2;
          tempo++;
        } while(massaXi >= 0.50);
        printf("A massa final é %.4f\nSerão necessário %d minuto(s) para atingir a massa final!", massaXi, tempo);
        printf("\nDeseja continuar o programa <S ou N> ?");
        scanf(" %c", &ch);
        ch = toupper(ch);
        if (ch == 'S'){
          tempo = 0;
        }
      }
    } while(massaXi <= 0);

  } while(ch == 'S');

  return 0;
}
