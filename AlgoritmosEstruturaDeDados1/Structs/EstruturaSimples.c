#include <stdio.h>
#define alturaMaxima 225

typedef struct{
  int peso;
  int altura;
} PesoAltura;

int main(){
  int x;
  PesoAltura pessoa1;
  pessoa1.peso = 75;
  pessoa1.altura = 172;

  printf("Peso: %i, Altura: %i ", pessoa1.peso, pessoa1.altura);
  if(pessoa1.altura > alturaMaxima){
    printf("Altura acima da máxima\n");
  }
  else printf("Altura abaixo da máxima!\n");

  printf("%p %p %p\n", &x, &pessoa1, &(pessoa1.altura));
  printf("%ld %ld %ld\n", sizeof(x), sizeof(pessoa1), sizeof(pessoa1.altura));

  return 0;
}
