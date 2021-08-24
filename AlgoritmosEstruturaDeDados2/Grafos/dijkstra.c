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
}GraphAM;

static int** startMA(int n){
    int i, j;
    int **matrix = (int **)malloc(n * sizeof(int *));

    for(i = 0; i < n; i++)
        matrix[i] = (int*) malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            matrix[i][j] = 0;
    

    return matrix;
}

GraphAM* startGraphMA(int v){
    GraphAM *G = (GraphAM*) malloc(sizeof(GraphAM));
    boolean *visited = (boolean*) malloc(v * sizeof(boolean));

    G->V = v;
    G->A = 0;
    G->visited = visited;
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

void printMatrix(GraphAM* G){
    int i, j;
    for(i = 0; i < G->V; i++){
        for(j = 0; j < G->V; j++)
            printf("%d ", G->matrix[i][j]);
        printf("\n");
    }
}

int minDistance(int distance[], GraphAM* G){

    int8_t min = INT8_MAX;
    int index;

    for(int i = 0; i < G->V; i++){
        if(G->visited[i] == FALSE && distance[i] <= min){
            min = distance[i];
            index = i;
        }
    }

    return index;
}

void printDijkstra(int parent[], int distance[], GraphAM *G){
    printf("v p d\n");
    for(int i = 0; i < G->V; i++){
        if(parent[i] < 0)
            printf("%d: - -\n", i);
        else printf("%d: %d %d\n", i, parent[i], distance[i]);
    }
}

void dijkstra(GraphAM* G){

    int distance[G->V];
    int parent[G->V];

    for(int i = 0; i < G->V; i++){
        distance[i] = INT16_MAX;
        G->visited[i] = FALSE;
    }

    distance[0] = 0;
    parent[0] = -1;

    for(int j = 0; j < G->V - 1; j++){

        int u = minDistance(distance, G);

        G->visited[u] = TRUE;

        for(int w = 0; w < G->V; w++)
            if(!G->visited[w] && G->matrix[u][w] && distance[u] != INT16_MAX && distance[u] + G->matrix[u][w] < distance[w]){
                parent[w] = u;
                distance[w] = distance[u] + G->matrix[u][w]; 
            }
    }

    printDijkstra(parent, distance, G);
}

int main(){

    GraphAM* graph = NULL;
    int size;
    scanf("%d", &size);

    graph = readGraph(graph, size);
    printMatrix(graph);

    dijkstra(graph);

    return 0;
}

/*
6
0 10 5 0 0 0
0 0 2 1 0 0
0 3 0 9 2 0
0 0 0 0 4 2
7 0 0 6 0 5
0 0 0 0 0 0
*/