#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED


void gerarVetorInteiros(int vetor[], int tamanho, int limite){
  int i;

  srand(time(0));

  for(i=0; i<tamanho; i++){
    vetor[i] = (rand() % limite) + 1 ;
  }
}

void mostrarVetorInteiros(int vetor[], int tamanho){
  int i;

  for(i=0; i<tamanho; i++){
    printf("%d ", vetor[i]);
  }
}

void gerarVetorInteiroComLimite(int vetor[], int tamanho, int valor_inicial, int valor_final){
  int i;
  srand(time(0));
  for(i=0; i<tamanho; i++){
    vetor[i] = (rand() % valor_final) + valor_inicial;
  }
}

int somarVetorInteiro(int vetor[], int tamanho){
  int i, somaVetores = 0;
  for(i=0; i<tamanho; i++){
    somaVetores = somaVetores + vetor[i];
  }
  return somaVetores;
}

#endif
