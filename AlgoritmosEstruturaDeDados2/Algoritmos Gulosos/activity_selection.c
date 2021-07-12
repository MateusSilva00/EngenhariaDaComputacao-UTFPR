#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

void MaxActivities(int start[], int finish[], int n){

    int i, j;
    printf("\nFollowing activities are selected n: ");
    
    //A primeira atividade sempre é selecionada
    i = 0;

    printf("%d ", i);
    for(j = 1; j < n; j++){
        //Se essa atividade tem um começo maior ou igual o tempo de término da atividade
        // anterior, seleciona esse atividade.
        if(start[j] >= finish[i]){
            printf("%d ", j);
            i = j;
        }
    }
}

int main(){

    srand(time(0));

    int start[TAM];
    int finish[TAM];
    int i;

    printf("Start Time: ");
    for(i=0; i < TAM; i++){
        start[i] = rand () % 10;
        printf("[%2d] ", start[i]);
    }

    printf("\nFinish Time: ");
    for (i = 0; i < TAM; i++){
        finish[i] = rand() % 10;
        printf("[%2d] ", finish[i]);
    }

    int n = sizeof(start)/ sizeof(start[0]);
    MaxActivities(start, finish, n);

    return 0;
}