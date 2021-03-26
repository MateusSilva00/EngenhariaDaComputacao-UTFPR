#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void display(int *arr, int size){
  printf("\n\n");
  for (int i=0; i < size; i++){
    printf("[%d] ", arr[i]);
  }
}

void merge(int *array, int inicio, int meio, int fim){
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2=0; // Variáveis booleanas
  tamanho = fim - inicio + 1;
  p1 = inicio;
  p2 = meio+1;
  temp = (int *) malloc(tamanho*sizeof(int)); // Aloca memória para criar um vetor temporário
  if(temp != NULL){
    for(i=0; i < tamanho; i++){
      if(!fim1 && !fim2){ // Verifica se chegou ao fim de um dos dois vetores
        if(array[p1] < array[p2])
          temp[i] = array[p1++];
        else
          temp[i] = array[p2++];

        if(p1 > meio) fim1 = 1; // Caso tenha chego ao fim do vetor, o booleano retorna True
        if(p2 > fim) fim2=1;
      }
      else{
        if(!fim1)
          temp[i] = array[p1++];
        else
          temp[i] = array[p2++];
      }
    }
    for(j=0, k=inicio; j < tamanho; j++, k++) // Copiar do vetor temporário para o original
      array[k] = temp[j];
  }
  free(temp); // Libera a memória do vetor temporário
}

void merge_sort(int *array, int inicio, int fim){
  int meio;
  if (inicio < fim){
    //Calcular o meio do vetor
    meio = floor((inicio+fim)/2);
    //recursão esquerda
    merge_sort(array, inicio, meio);
    //recursão direita
    merge_sort(array, meio+1, fim);
    //Faz o merge (junta com os dois grupos de vetores ordenados)
    merge(array, inicio, meio, fim);
  }
}

int main(){

  srand(time(0));

  int size=10, arr[size], i;

  printf("=== ORIGINAL VECTOR ===\n\n");
  for(i=0; i < size; i++){
    arr[i] = rand() % 100 + 1;
    printf("[%d] ", arr[i]);
  }

  merge_sort(arr, 0, 10);
  printf("\n\n=== SORTED NUMBERS ===");
  display(arr, size);

  return 0;
}
