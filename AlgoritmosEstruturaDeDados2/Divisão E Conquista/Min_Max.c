#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int DAC_max(int array[], int index, int left){
    int max;
    if (index >= left - 2)
    {
        if (array[index] > array[index + 1])
            return array[index];
        else
            return array[index + 1];
    }

    max = DAC_max(array, index + 1, left);

    if (array[index] > max)
        return array[index];
    else
        return max;
}

int DAC_min(int array[], int index, int left){

    int min;
    if (index >= left - 2)
    {
        if (array[index] < array[index + 1])
            return array[index];
        else
            return array[index + 1];
    }

    min = DAC_min(array, index + 1, left);
    if (array[index] < min)
        return array[index];
    else
        return min;
}

int main(){

    srand(time(0));

    int n = 10;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }

    int max = DAC_max(arr, 0, n);
    int min = DAC_min(arr, 0, n);
    printf("\nO maior valor é %d ", max);
    printf("\nO menor valor é %d ", min);

    return 0;
}