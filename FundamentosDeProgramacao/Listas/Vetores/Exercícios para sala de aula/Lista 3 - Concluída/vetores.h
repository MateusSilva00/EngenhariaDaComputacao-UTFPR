#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED

  /*
      FUNÇÕES QUE GERAM E MOSTRAM VALORES INTEIROS
  */
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

  void GerarVetorInteiroComFaixa(int vetor[], int tam, int limInf, int limSup)
  {
      int i;

      srand(time(NULL));

      for(i=0; i<tam; i++)
      {
          vetor[i] = rand()%((limSup-limInf)+ 1) + limInf;
      }
  }

  /*
      FUNÇÕES QUE GERAM E MOSTRAM VALORES REAIS
  */

  void GerarVetorFloat0a1(float vetor[], int tamanho);
  void GerarVetorFloat0a100(float vetor[], int tamanho);
  void MostrarVetorFloat(float vetor[], int tamanho);
  float SomarVetorFloat(float vetor[], int tamanho);

  /*
      FUNÇÕES QUE GERAM E MOSTRAM CARACTERES
  */

  void GerarVetorCharMinuscula(char vetor[], int tamanho);
  void GerarVetorCharMaiuscula(char vetor[], int tamanho);
  void MostrarVetorChar(char vetor[], int tamanho, int n);

  /*
      FUNÇÕES QUE GERAM E MOSTRAM CARACTERES ALFANUMÉRICO
  */

  void GerarVetorCharAlfanumerico(char vetor[], int tamanho);
  void MostrarVetorCharAlfanumerico(char vetor[], int tamanho, int n);

  /*
      FUNÇÕES QUE GERAM E MOSTRAM VETORES COM VALORES POSITIVO E NEGATIVOS
  */

  void GerarVetorPositivoNegativo(int vetor[], int tamanho, int limNegativo, int limPositivo);
  void MostrarVetorPositivoNegativo(int vetor[], int tamanho);

#endif
