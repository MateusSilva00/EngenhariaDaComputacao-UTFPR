// Ler três valores inteiros diferentes e colocá-los em ordem crescente. Os valores devem
// ser apresentados com uma instrução:
// printf("Menor: %d
// Meio: %d
// Maior: %d\n", menor, meio, maior);
// Sugestão: Dividir o problema em partes: encontrar o maior, o menor e o do meio
// separadamente. Armazenar os valores em variável e mostrá-los com uma instrução.
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int a, b, c, menor, meio, maior;

  printf("Insira o valor de <a>:");
  scanf("%d", &a);
  printf("Insira o valor de <b>:");
  scanf("%d", &b);
  printf("Insira o valor de <c>:");
  scanf("%d", &c);

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

  printf("\n\nMaior valor digitado: %d\nValor do Meio: %d\nMenor valor digitado: %d", maior, meio, menor);
  return 0;
}
