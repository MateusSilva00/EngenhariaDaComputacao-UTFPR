#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct graphAM{
    int V;
    int A;
    boolean *visited;
    int **matrix;
} GraphAM;

static int **startMA(int n){
    int i, j;
    int **matrix = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            matrix[i][j] = 0;

    return matrix;
}

static boolean validadeVertex(GraphAM *G, int v){
    return (v >= 0) && (v < G->V);
}

GraphAM *startGraphMA(int v){
    GraphAM *G = (GraphAM *)malloc(sizeof(GraphAM));
    boolean *visited = (boolean*) malloc(v * sizeof(boolean));
    
    G->V = v;
    G->A = 0;
    G->visited = visited;
    G->matrix = startMA(G->V);

    return G;
}

GraphAM *readGraph(GraphAM *G, int size){
    G = startGraphMA(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &G->matrix[i][j]);
    return G;
}

void printMatrix(GraphAM *G){
    int i, j;
    for (i = 0; i < G->V; i++){
        for (j = 0; j < G->V; j++)
        {
            printf("%d ", G->matrix[i][j]);
        }
        printf("\n");
    }
}

int minKey(int key[], GraphAM* G){

    int8_t min = INT8_MAX;
    int index;

    for(int i = 0; i < G->V; i++){
        if(G->visited[i] == FALSE && key[i] < min){
            min = key[i]; 
            index = i;
        }
        else index = 0;
    }
    
    return index;
}

void printPrim(int parent[], GraphAM* G){
    for(int i = 0; i < G->V; i++){
        if(parent[i] < 0)
            printf("%d: -\n", i);
        else printf("%d: %d\n", i, parent[i]);
    }
}

void primAlgo(GraphAM* G){

    int parent[G->V];
    int key[G->V];

    for(int i = 0; i < G->V; i++){
        key[i] = INT16_MAX; 
        G->visited[i] = FALSE;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int j = 0; j < G->V-1; j++){

        int u = minKey(key, G);
        
        G->visited[u] = TRUE;

        for(int w = 0; w < G->V; w++)
            if(G->matrix[u][w] && G->visited[w] == FALSE && G->matrix[u][w] < key[w]){
                parent[w] = u;
                key[w] = G->matrix[u][w];
            }
    }

    printPrim(parent, G);
}

int main(){

    GraphAM *graph = NULL;
    int size;
    scanf("%d", &size);

    graph = readGraph(graph, size);
    printMatrix(graph);

    primMST(graph);

    return 0;
}