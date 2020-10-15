// Uma árvore A tem 1,50 metros e cresce 2 centímetros por ano, enquanto uma árvore B tem 1,10 metros
// e cresce 3 centímetros por ano. Construa um programa que calcule e imprima quantos anos serão
// necessários para que a árvore B seja maior que a árvore A.
#include <stdio.h>

int main (){

  int anos = 0;
  float arvoreA, arvoreB, centA, centB;

  printf("Insira a altura da arvore A.:");
  scanf("%f", &arvoreA);
  printf("Quantos centimetros ela cresce por ano.: ");
  scanf("%f", &centA);
  printf("Insira a altura da arvore B.:");
  scanf("%f", &arvoreB);
  printf("Quantos centimetros ela cresce por ano.: ");
  scanf("%f", &centB);

  while (arvoreA > arvoreB) {
    arvoreA = arvoreA + centA;
    arvoreB = arvoreB + centB;
    anos++;
  }

  printf("Altura final arvore A %.2f\nAltura final arvore B %.2f\n", arvoreA, arvoreB);
  printf("Serao necessarios %d anos para que a arvore B seja maior que a arvore A!", anos);

  return 0;
}
