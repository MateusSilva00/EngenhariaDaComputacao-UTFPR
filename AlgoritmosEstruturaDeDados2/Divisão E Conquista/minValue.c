#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DAC_minValue(int arr[], int index, int size){
    int medium, a, b;
    if(size - index <= 1){
        return arr[index] < arr[size] ? index : size;
    }
    else {
        medium = (size + index) / 2;
        a = DAC_minValue(arr, index, medium);
        b = DAC_minValue(arr, medium+1, size);
    }
    
    return arr[a] < arr[b] ? a : b;
}

int main(){


    int size = 10;
    int arr[size]; 
    srand(time(0));

    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100 + 1;
        printf("[%d] ", arr[i]); 
    }

    int min = DAC_minValue(arr, 0, size-1);
    printf("\nO menor valor esta na posicao %d \n", min);

    return 0;
}