#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225

typedef struct{
  int peso;
  int altura;
}PesoAltura;

int main(){
  int x;
  PesoAltura* pessoa1;
  printf("Valor inicial do endereço: %p\n", pessoa1);
  pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
  printf("Peso: %i, Altura %i. ", pessoa1->peso, pessoa1->altura);
  pessoa1->peso = 80;
  pessoa1->altura = 185;

  printf("Peso: %i, Altura %i. \n", pessoa1->peso, pessoa1->altura);
  pessoa1->peso = 80;
  pessoa1->altura = 185;

  printf("Valor final do endereço: %p\n", pessoa1);

  return 0;
}
