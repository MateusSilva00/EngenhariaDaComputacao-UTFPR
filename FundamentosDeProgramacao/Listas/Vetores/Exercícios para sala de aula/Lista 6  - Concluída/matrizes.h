#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

  void GerarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna], int limite){
    int i, j;
    srand(time(0));
    for(i=0; i < linha; i++){
      for(j=0; j < coluna; j++){
        matriz[i][j] = (rand() % limite) + 1 ;
      }
    }
  }

  void MostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna]){
    int i, j;
    for(i=0; i < linha; i++){
      for(j=0; j < coluna; j++){
        printf("%2d ", matriz[i][j]);
      }
      printf("\n");
    }
  }

#endif
