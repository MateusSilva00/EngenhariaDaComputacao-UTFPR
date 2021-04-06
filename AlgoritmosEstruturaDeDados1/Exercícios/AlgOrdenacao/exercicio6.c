#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int low, int n){

  for(int i = low+1; i < n+1; i++){
    int val = arr[i];
    int j = i;
    while(j > low && arr[j-1] > val){
      arr[j] = arr[j-1];
      j-=1;
    }
    arr[j] = val;
  }
}

int partition(int arr[], int low, int high){

  int pivot = arr[high];
  int i, j;
  i = low;
  j = low;

  for(; i < high; i++){
    if(arr[i] < pivot){
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j+= 1;
    }
  }

  int temp = arr[j];
  arr[j] = arr[high];
  arr[high] = temp;

  return j;
}

void quick_sort(int arr[], int low, int high){
  if(low < high){
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot-1);
    quick_sort(arr, pivot+1, high);
  }
}

void hybrid_quick_sort(int arr[], int low, int high){
  while(low < high){
    if(high - low + 1 < 10){
      insertion_sort(arr,low, high);
      break;
    }
    else{
      int pivot = partition(arr, low, high);

      if(pivot - low < high - pivot){
        hybrid_quick_sort(arr, low, pivot-1);
        low = pivot+1;
      }

      else{
        hybrid_quick_sort(arr, pivot+1, high);
        high = pivot - 1;
      }
    }
  }
}

int main(){

  clock_t start_t, end_t, total_t;
  srand(time(0));

  int size = 800000, arr[size], i;
  printf("\n=== ORIGINAL VETOR ===\n");
  for(i=0; i < size; i++){
    arr[i] = rand() % 100;
    // printf("[%3d]  ", arr[i]);
    // if(i>0 && i % 9 == 0) printf("\n");
  }

  start_t = clock();
  hybrid_quick_sort(arr, 0, size-1);
  end_t = clock();
  total_t = ((double)(end_t - start_t) / (CLOCKS_PER_SEC/1000));
  printf("\nTempo Decorrido (Hybrido Quick Sort) = %ld", total_t);

  start_t = clock();
  quick_sort(arr, 0, size-1);
  end_t = clock();
  total_t = ((double)(end_t - start_t) / (CLOCKS_PER_SEC/1000));
  printf("\nTempo Decorrido (Quick Sort) = %ld", total_t);

  return 0;
}
