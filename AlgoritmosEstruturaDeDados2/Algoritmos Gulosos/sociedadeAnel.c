#include <stdio.h>
#include <stdlib.h>
#define MOD(x) x >= 0 ? (x) :-(x)

int FrodoEpicWay(int line, int col, int arr[line][col]){

    int i = 0, j = 0;
    int posAtual[line - 1][col - 1];
    int caminho = 0;
    int x, y;
    printf("\nInitial position %d [%d][%d]", arr[i][j], i, j);
    printf("\nFinal position %d [%d][%d]", arr[line-1][col-1], line-1, col-1);

    while (i < line - 1 ||  j < col - 1){    
        // Movimento para esquerda ou direita
        if (MOD(arr[i + 1][j])  < MOD(arr[i - 1][j]))
            x = i + 1;
        else x = i - 1;

        //Movimento para cima ou para baixo
        if (MOD(arr[i][j - 1]) < MOD(arr[i][j + 1]))
            y = j + 1;
        else y = j - 1;

        printf("\nPossible new x: %d", x);
        printf("\nPossible new y: %d", y);

        //Movimento para horizontal ou vertical
        arr[i][j] = 1000;
        if(arr[x][j] < arr[i][y]){
            printf("\nNew Position %d [%d][%d]", arr[x][j], x, j);
            i = x;
            caminho += arr[x][j];
        }
        else{
            printf("\nNew Position %i [%d][%d]", arr[i][y], i, y);
            j = y;
            caminho += arr[i][y];
        }

    }

    printf("\nEnergia gasta: %d ", caminho);
}

int main(){

    int l = 6, c = 6;
    int matriz[6][6] = {{0, 1, 2, 3, 4, 5},
                       {2, 1, 3, 2, 1, 4},
                       {1, 3, 4, 5, 2, 1},
                       {1, 2, 2, 6, 7, 5},
                       {3, 4, 1, 3, 5, 6},
                       {1, 4, 2, 1, 2, 3}};

    for(int i = 0; i < 6; i++){
        printf("\t");
        for(int j = 0; j < 6; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    FrodoEpicWay(l, c, matriz);

    return 0;
}