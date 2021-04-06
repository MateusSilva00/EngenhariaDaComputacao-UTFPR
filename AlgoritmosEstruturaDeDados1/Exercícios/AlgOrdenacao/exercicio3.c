// 3) Crie vetores com grande quantidade de elementos inteiros (ex: um milhão de elementos) de forma aleatória
// (use a função rand).  A seguir, verifique o tempo que cada algoritmo de ordenação leva para ordenar este vetor.
// Utilize a biblioteca <time.h> para isso.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *x, int *y){
  int aux = *x;
  *x = *y;
  *y = aux;
}

void selection_sort(int arr[], int size){

  int i, j, menor;

  for(i=0; i < size - 1; i++){
    menor = i;
    for(j=i+1; j < size; j++){
      if(arr[j] < arr[menor]){
        menor = j;
      }
    }

    if(i != menor){
      troca(&arr[menor], &arr[i]);
    }
  }
}

void bubble_sort(int arr[], int tam){

  int i, cont = 1;

  while(cont == 1){
    for(i=0; i < tam; i++){
      cont = 0;
        if(arr[i] > arr[i+1]){
          troca(&arr[i], &arr[i+1]);
        }
    }
  }
}

void insertion_sort(int arr[], int size){

  int i, j, menor;
  for(i=1; i < size; i++){
    j = i - 1;
    while(j >= 0 && arr[j] > menor){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = menor;
  }
}

int main(){

  clock_t tInicio, tFim, tDecorrido;
  srand(time(0));

  int i, size=100000, arr[size];

  for(i=0; i < size; i++){
    arr[i] = rand() % 5000 + 1;
  }

  tInicio = clock();
  bubble_sort(arr, size);
  tFim = clock();
  /*calcula aproximadamente o tempo em milisegundos gasto entre as duas chamadas de clock()*/
  tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("\nTempo Decorrido (Bubble Sort) = %f", tDecorrido);


  tInicio = clock();
  selection_sort(arr, size);
  tFim = clock();
  tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("\nTempo Decorrido (Selection Sort) = %ld", tDecorrido);

  tInicio = clock();
  insertion_sort(arr, size);
  tFim = clock();
  tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
  printf("\nTempo Decorrido (Insertion Sort) = %ld", tDecorrido);

  return 0;
}
