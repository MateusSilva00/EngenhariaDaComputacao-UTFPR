// Ler três valores inteiros diferentes, encontrar e mostrar o menor deles. Deve ser criada
// uma variável para armazenar o menor número.
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int a, b, c, menor;

  printf("Insira o valor de <a>:");
  scanf("%d", &a);
  printf("Insira o valor de <b>:");
  scanf("%d", &b);
  printf("Insira o valor de <c>:");
  scanf("%d", &c);

  if (a < b && a < c){
    menor = a;
  }

  else if (b < a && b < c){
    menor = b;
  }

  else if (c < a && c < b){
    menor = c;
  }

  printf("O menor valor digitado foi %d!", menor);

  return 0;
}
