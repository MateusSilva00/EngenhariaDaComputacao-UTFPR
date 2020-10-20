#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED


  int gerarNumRandom(int tamanho, int limite){
    int i=0, vetor[tamanho], resultado, menor, posicao, countmedia=0;
    float media=0;
    for(i; i<tamanho; i++){
      vetor[i] = rand() % limite + 1;
      resultado = vetor[i];
      if(i == 0){
        menor = vetor[i];
        posicao = i;
      }
      else if(vetor[i] < menor){
        menor = vetor[i];
        posicao = i;
      }

      if(vetor[i] % 2 == 0){
        media = media + vetor[i];
        countmedia++;
      }
      printf("%d ", resultado);
    }

    printf("\n\nO menor valor é %d e está no indice %d", menor, posicao);
    if(countmedia > 0){
      media = media / countmedia;
      printf("\n\nA média dos pares é %.2f ", media);
    }
  }

#endif
