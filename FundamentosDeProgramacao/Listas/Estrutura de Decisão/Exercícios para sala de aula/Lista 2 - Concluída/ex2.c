// Ler três valores inteiros diferentes, encontrar e mostrar o número do meio. Deve ser
// criada uma variável para armazenar esse número.
// Exemplo: Seja num1 = 5, num2 = 8 e num3 = 1, então o número do meio é 5.
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int a, b, c, meio;
  printf("Insira o valor de <a>:");
  scanf("%d", &a);
  printf("Insira o valor de <b>:");
  scanf("%d", &b);
  printf("Insira o valor de <c>:");
  scanf("%d", &c);

  if ((a > b && a < c) || (a > c && a < b)){
    meio = a;
  }
  else if ((b > a && b < c) || (b > c && b < a)){
    meio = b;
  }

  else if ((c > a && c < b) || (c > b && c < a)){
    meio = c;
  }

  printf("O valor do meio é %d!", meio);

  return 0;
}
