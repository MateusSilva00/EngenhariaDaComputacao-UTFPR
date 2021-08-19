#include <stdio.h>
#include <stdlib.h>

typedef int booleano;

typedef struct graphAM{
    int V; 
    int A; 
    int **matrix;
}GraphAM;

static int** startMA(int n){
    int i, j;
    int **matrix = (int **) malloc(n * sizeof(int*));
    
    for(i = 0; i < n; i++)
        matrix[i] = (int*) malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            matrix[i][j] = 0;
    
    return matrix;
}

static booleano validadeVertex(GraphAM* G, int v){
    return (v >= 0) && (v < G->V);
}

GraphAM* startGraphMA(int v){
    GraphAM* G = (GraphAM*) malloc(sizeof(GraphAM));
    G->V = v;
    G->A = 0;
    G->matrix = startMA(G->V);

    return G;
}

GraphAM* readGraph(GraphAM* G, int size){
    G = startGraphMA(size);
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            scanf("%d", &G->matrix[i][j]);
    return G;
}

int edgeExist(GraphAM* G, int v1, int v2){
    return (G) && validadeVertex(G, v1) && validadeVertex(G, v2) && (G->matrix[v1][v2] == 1);
}

void insertEdge(GraphAM* G, int v1, int v2){
    if (!edgeExist(G, v1, v2)){
        G->matrix[v1][v2] = G->matrix[v2][v1] = 1;
        G->A++;
    }
}

void removeEdge(GraphAM* G, int v1, int v2){
    if((G) && (validadeVertex(G, v1)) && (validadeVertex(G, v2)) && (edgeExist(G, v1, v2))){
        G->matrix[v2][v1] = G->matrix[v1][v2] = 0;
        G->A--;
    }
}

void printEdges(GraphAM* G){
    int i, j;

    for(i = 1; i  < G->V; i++)
        for(j = 0; j < i; j++)
            if(G->matrix[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}

void printMatrix(GraphAM *G){
    int i, j;
    for(i = 0; i < G->V; i++){
        for(j = 0; j < G->V; j++){
            printf("%d ", G->matrix[i][j]);
        }
        printf("\n");
    }
}

void liberaGraph(GraphAM *G){
    if(G){
        free(G->matrix);
        free(G);
    }
}

int main(){

    // GraphAM* graph = startGraphMA(5);

    // int arr[5][5] = {{1, 0, 1, 0, 0},
    //                 {0, 0, 0, 0, 1},
    //                 {1, 1, 1, 0, 0},
    //                 {1, 1, 0, 0, 0},
    //                 {1, 0, 1, 0, 1}}; 

    // for(int i = 0; i < 5; i++){
    //     for(int j = 0; j < 5; j++){
    //         if(arr[i][j] == 1)
    //             insertEdge(graph, i, j);
    //     }
    // }

    GraphAM *graph = NULL;
    int size;
    scanf("%d", &size);

    graph = readGraph(graph, size);

    printMatrix(graph);

    return 0;
}