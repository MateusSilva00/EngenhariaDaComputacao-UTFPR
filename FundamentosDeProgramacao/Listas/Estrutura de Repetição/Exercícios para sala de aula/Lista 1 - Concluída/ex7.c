// Ler uma série de números indicados pelo usuário até ser informado o valor zero.
// Encontrar e mostrar o maior e o menor dos valores informados pelo usuário. O valor zero
// indica o final da leitura e não deve ser considerado.
#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int maior = 0, menor = 0, num;

  while (num != 0) {
    printf("Informe um número.: ");
    scanf("%d", &num);
    if (maior == 0 && menor == 0){
      maior = num; menor = num;
    }

    if (num > maior && num != 0){
      maior = num;
    }
    else if (num < menor && num != 0){
      menor = num;
    }
  }

  printf("Maior valor digitado: %d\nMenor valor digitado: %d", maior, menor);

  return 0;
}
