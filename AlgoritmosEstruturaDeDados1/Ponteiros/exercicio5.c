// 5) Goofy é fã do programa de auditório Apagando e Ganhando. Neste programa, o jogo começa quando o apresentador escreve um
// número N em uma lousa. O participante então deve apagar exatamente D dígitos do número que está na lousa. O número
// formado pelos dígitos que restarem será o prêmio do participante.
// Goofy finalmente foi selecionado para participar do programa, e pediu que você escrevesse um programa que, dado o
// número que o apresentador escreveu na lousa e quantos dígitos devem ser apagados, determina o valor do maior prêmio que
// Goofy pode ganhar. Exs.:
// N = 2318 e D = 1, resposta = 318;
// N = 3759 e D = 2, resposta = 79;
// N = 123123 e D = 3, resposta = 323;
// N= 22313 e D=2, resposta = 313;
// N = 1000000 e D = 4, resposta = 100.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Número de digitos em um número
int num_digitos(int num){
  int tam_num = 0;
  while(num > 1){
    num = num / 10;
    tam_num++;
  }
  return tam_num;
}

// Separa número e atribui cada valor a um índice do vetor
void separarNum(int num, int size, int arr[]){
  for(int i=size-1; i >= 0; i--){
    arr[i] = num % 10;
    num = num / 10;
  }
}

// Ordenando o vetor pelo método selection_sort
void selection_sort(int arr[], int tamanho){
  int i=0, j, menor, troca;
  //Loop externo para repassar todo o vetor
  for(; i < tamanho - 1; i++){
    menor = i;
    for(j = i+1; j < tamanho; j++){
      if(arr[j] < arr[menor]){
        menor = j;
      }
    }
    if(i != menor){
      troca = arr[i];
      arr[i] = arr[menor];
      arr[menor] = troca;
    }
  }
}

// Maior número possivel
void maiorNumero(int arr[], int digitos, int digitos_remover){
  for(int i=digitos-1; i >= digitos_remover; i--){
    printf("[%d] ", arr[i]);
  }
}

int main(){

  srand(time(0));
  int numero, n_digitos;

  numero = rand() % 999999 + 1;

  printf("Número Aleatório: %d\n", numero);
  n_digitos = num_digitos(numero); // Pegar número de digitos de um número

  int vetor[n_digitos];
  separarNum(numero, n_digitos, vetor);

  int remover_digitos = rand() % 4 + 1;
  printf("\nNúmero de digitos a serem removidos: %d\n", remover_digitos);


  printf("\nDIGITOS SEPARADOS\n");
  for(int i=0; i < n_digitos; i++){
    printf("[%d] ", vetor[i]);
  }

  selection_sort(vetor, n_digitos);
  printf("\n\nDIGITOS ORDENADOS\n");
  for(int i=0; i < n_digitos; i++){
    printf("[%d] ", vetor[i]);
  }

  printf("\n\nMAIOR NÚMERO POSSÍVEL\n");
  maiorNumero(vetor, n_digitos, remover_digitos);

  return 0;
}
