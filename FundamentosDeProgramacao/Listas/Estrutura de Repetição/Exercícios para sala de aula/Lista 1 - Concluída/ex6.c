// Ler dois números que representam os limites de um intervalo e ler o incremento.
// Mostrar os números desse intervalo de acordo com o incremento indicado e em ordem
// crescente. O usuário pode informar os valores que representam os limites do intervalo
// em ordem crescente ou decrescente. Fazer a média dos ímpares e divisíveis por 35 do
// intervalo.
#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int limInicial,limFinal,incremento, media = 0, count = 0;
  printf("Insira o início do intervalo.: ");
  scanf("%d", &limInicial);
  printf("Insira o fim do intervalo.: ");
  scanf("%d", &limFinal);
  printf("Insira o incremento.: ");
  scanf("%d", &incremento);

  for (limInicial; limInicial <= limFinal; limInicial= limInicial + incremento){

    if (limInicial % 2 != 0 && limInicial % 35 == 0){
      printf("\n%d \tImpar e divisível por 35", limInicial);
      count++;
      media = media + limInicial;
    }
    else printf("\n%d ", limInicial);
  }
  media = media / count;

  printf("A media dos números ímpares que são divisíveis por 35 é %d ", media);

  return 0;
}
