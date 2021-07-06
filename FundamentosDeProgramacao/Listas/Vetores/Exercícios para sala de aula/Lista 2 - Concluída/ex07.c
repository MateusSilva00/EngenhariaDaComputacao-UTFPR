// Em uma determinada cidade, sabe-se que, de janeiro a abril de um determinado ano (121 dias), a temperatura
// ficou entre a 5° e 45°. Gerar um vetor com valores inteiros randômicos nesse intervalo para esse período de
// tempo. Para isso, crie uma função na biblioteca Vetores.h chamada GerarVetorInteiroComLimite() que receba
// como parâmetros: o vetor, o tamanho do vetor, o valor inicial e o valor final do limite da aleatoriedade. A partir do
// vetor gerado, obtenha e mostre:
// a) A menor temperatura ocorrida.
// b) A maior temperatura ocorrida.
// c) A temperatura média.
// d) O número de dias em que a temperatura foi inferior à temperatura média.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "vetores.h"

int menorElementos(int vetor[], int tamanho);
int maiorElementos(int vetor[], int tamanho);
float temperaturaMedia(int vetor[], int tamanho);
int qtDias(int vetor[], int tamanho, float media);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int elementos = 121, vetor[elementos], menor, maior, quantidadeDias;
  float tempMedia;
  char ch;
    do {
      gerarVetorInteiroComLimite(vetor, elementos, 5, 41);
      printf("=== TEMPERATURA ===\n");
      mostrarVetorInteiros(vetor, elementos);

      menor = menorElementos(vetor, elementos);
      printf("\nMenor temperatura ocorrida.: %d", menor);

      maior = maiorElementos(vetor, elementos);
      printf("\nMaior temperatura ocorrida.: %d", maior);

      tempMedia = temperaturaMedia(vetor, elementos);
      printf("\nTemperatura Média.: %.2f", tempMedia);

      quantidadeDias = qtDias(vetor, elementos, tempMedia);
      printf("\nQuantidade de dias que a temperatura foi menor que a media.: %d", quantidadeDias);


      printf("\n\nDeseja continuar o programa (S ou N).: ");
      scanf(" %c", &ch);
      ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}

int menorElementos(int vetor[], int tamanho){
  int i, menor;
  menor = vetor[0];
  for(i=0; i<tamanho; i++){
    if(vetor[i] < menor){
      menor = vetor[i];
    }
  }
  return menor;
}

int maiorElementos(int vetor[], int tamanho){
  int i, maior;
  maior = vetor[0];
  for(i=0; i<tamanho; i++){
    if(vetor[i] > maior){
      maior = vetor[i];
    }
  }
  return maior;
}

float temperaturaMedia(int vetor[], int tamanho){
  int i;
  float media=0;
  for(i=0; i<tamanho; i++){
    media = media + vetor[i];
  }
  media = media / tamanho;
  return media;
}

int qtDias(int vetor[], int tamanho, float media){
  int i, contDias = 0;
  for(i=0; i<tamanho; i++){
    if(vetor[i] < media){
      contDias++;
    }
  }
  return contDias;
}
