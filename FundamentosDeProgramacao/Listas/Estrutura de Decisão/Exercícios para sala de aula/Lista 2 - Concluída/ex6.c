// Ler três valores inteiros que representam os lados de um triângulo e determinar se
// esses valores podem formar um triângulo (obs.: para ser um triângulo cada lado deve ser
// menor que a soma dos outros dois lados). Se for um triângulo, determinar o seu tipo:
// equilátero (todos os lados iguais), isósceles (dois lados iguais) e escaleno (todos os lados
// diferentes).
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int a, b, c;
  printf("Insira o lado <a>.: ");
  scanf("%d", &a);
  printf("Insira o lado <b>.: ");
  scanf("%d", &b);
  printf("Insira o lado <c>.: ");
  scanf("%d", &c);
  if ((a < (b+c)) && (b < (a+c)) && (c < (a+b)) ){
    if (a == b && a == c) {
      printf("\nTriângulo Equilátero!");
    }
    else if(a == b || b == c || c == a){
      printf("\nTriângulo Isósceles!");
    }
    else if(a != b && a != c && b != c){
      printf("\nTriângulo Escaleno!");
    }
  }

  else{
    printf("Não é um triângulo!");
  }

  return 0;
}
