#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

  void troca(int *xp, int *yp)
  {
      int temp = *xp;
      *xp = *yp;
      *yp = temp;
  }
  
  void bubbleSort(int vet[], int tamanho){
    srand(time(0));
    int i, j, aux;
    for(i = 1; i < tamanho; i++){
      for(j = 0; j<tamanho-1; j++){
        if( vet[j] > vet[j+1] ){
          troca(&vet[j], &vet[j+1]);
        }
      }
    }
  }

#endif
