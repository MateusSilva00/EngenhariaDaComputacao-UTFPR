// Elaborar um programa para mostrar os números pares entre 20 e 100. Fazer a média
// dos valores desse intervalo que são divisíveis por 5.
#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int pares, i, count = 0, media = 0;
  for (i = 20; i<=100;  i++){
    pares = i % 2;
    if (pares == 0){
      printf(" %d ", i);
    }
    else if (i % 5 == 0) {
      count++;
      media = (i + media);
    }
  }
  media = media / count;
  printf("\nQuantidade Números Divisiveis por cinco: %d\nMedia dos Números divisiveis por 5: %d", count,media);

  return 0;
}
