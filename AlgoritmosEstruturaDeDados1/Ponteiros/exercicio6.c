// Você pretende fazer uma viagem de carro em Duckland, um país muito organizado em que todos os pedágios de uma mesma
// estrada estão organizados de maneira equidistante, a partir da capital Donald. Seu destino final é Scrooge, porém são
// 4 estradas possíveis entre Donald e Scrooge. Por consequência, cada estrada terá uma quilometragem total diferente,
// número de pedágios diferente e consumo de gasolina diferente devido às condições do asfalto. Suas opções são:
// Estrada Quilometragem total Distância entre cada pedágio Consumo (km/litro)
// A         150                   20                            10
//
// B         120                   15                            8,5
//
// C         135                   20                            8,2
//
// D         160                   30                            9,4
// Implemente:
// Um vetor de “structs” para armazenar os valores da tabela acima;
// Uma função que recebe o vetor de structs criado em (a) e calcula o número de pedágios daquela estrada e a quantidade de litros de combustível gasta;
// Um vetor de “structs” que armazene os valores computados em (b);
// Uma função que calcule o custo da viagem para cada estrada, recebendo como parâmetros: uma struct (conforme criada em (c)), o preço de cada pedágio e o preço do combustível. Ex.: se cada pedágio custa 10 duckdollars e o combustível é vendido por 3 duckdollars, o custo da viagem em cada estrada seria:
// A 115,00
//
// B 122,35
//
// C 109,39
//
// D 101,06
//
// Teste também com outros preços. A estrada D será sempre a mais vantajosa, mesmo baixando/aumentando o preço do pedágio ou do combustível?
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char opcao;
  int quilometragem_total;
  int distancia_pedagio;
  float km_litro;
}Estradas;
Estradas Estrada[4];

typedef struct{
  int Qt_pedagios;
  float Qt_combustivel_gasto;
}Pedagios;
Pedagios Pedagio[4];

void calcPedagios(Estradas X, int contador){
  int qt_pedagios;
  float qt_combustivel_gasto;

  qt_pedagios = X.quilometragem_total / X.distancia_pedagio;
  qt_combustivel_gasto = X.quilometragem_total / X.km_litro;

  // Pedagios P[4];
  Pedagio[contador].Qt_pedagios = qt_pedagios;
  Pedagio[contador].Qt_combustivel_gasto = qt_combustivel_gasto;

  printf("%c\t%d\t%4.2f\n", X.opcao, qt_pedagios, qt_combustivel_gasto);
}

void custoViagem(Estradas X, Pedagios P, float vl_pedagio, float vl_combustivel){
  float custo_total;
  custo_total = (P.Qt_combustivel_gasto * vl_combustivel) + (P.Qt_pedagios * vl_pedagio);

  printf("%c\t%4.2f\n", X.opcao, custo_total);
}

int main(){

  Estrada[0].opcao = 'A';
  Estrada[0].quilometragem_total = 150;
  Estrada[0].distancia_pedagio = 20;
  Estrada[0].km_litro = 10;

  Estrada[1].opcao = 'B';
  Estrada[1].quilometragem_total = 120;
  Estrada[1].distancia_pedagio = 15;
  Estrada[1].km_litro = 8.5;

  Estrada[2].opcao = 'C';
  Estrada[2].quilometragem_total = 135;
  Estrada[2].distancia_pedagio = 20;
  Estrada[2].km_litro = 8.2;

  Estrada[3].opcao = 'D';
  Estrada[3].quilometragem_total = 160;
  Estrada[3].distancia_pedagio = 30;
  Estrada[3].km_litro = 9.4;

  printf("Opção\tPedagios  Combustível\n");
  for(int i=0; i < 4; i++){
    calcPedagios(Estrada[i], i);
  }

  float vl_pedagio = 3;
  float vl_combustivel = 10;

  printf("\n\nPREÇO FINAL DAS VIAGENS\nOpção\tCusto\n");
  for(int i=0; i < 4; i++){
    custoViagem(Estrada[i], Pedagio[i], vl_pedagio, vl_combustivel);
  }

  return 0;
}
