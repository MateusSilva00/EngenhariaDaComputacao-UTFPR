#include <stdio.h>
#include <stdlib.h>

typedef struct grafoMA{
    int V; // número de vértices
    int A; // número de arestas
    int **matriz;
}GrafoMA;

static int** inicar_MA(int n){
    int i, j;
    int **matriz = (int **) malloc(n * sizeof(int*));
    
    for(i = 0; i < n; i++)
        matriz[i] = (int*) malloc(n * sizeof(int));
    
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            matriz[i][j] = 0;
    
    return matriz;
}

static int valida_vertice(GrafoMA* G, int v){
    return (v >= 0) && (v < G->V);
}

GrafoMA* iniciar_grafoMA(int v){
    GrafoMA* G = (GrafoMA*) malloc(sizeof(GrafoMA));
    G->V = v;
    G->A = 0;
    G->matriz = inicar_MA(G->V);

    return G;
}

int aresta_existe(GrafoMA* G, int v1, int v2){
    return (G) && valida_vertice(G, v1) && valida_vertice(G, v2) && (G->matriz[v1][v2] == 1);
}

void inserir_aresta(GrafoMA* G, int v1, int v2){
    if ((G) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (!aresta_existe(G, v1, v2))){
        G->matriz[v1][v2] = G->matriz[v2][v1] = 1;
        G->A++;
    }
}

void remover_aresta(GrafoMA* G, int v1, int v2){
    if((G) && (valida_vertice(G, v1)) && (valida_vertice(G, v2)) && (aresta_existe(G, v1, v2))){
        G->matriz[v2][v1] = G->matriz[v1][v2] = 0;
        G->A--;
    }
}

void imprimir_arestas(GrafoMA* G){
    int i, j;

    for(i = 1; i  < G->V; i++)
        for(j = 0; j < i; j++)
            if(G->matriz[i][j] == 1)
                printf("(%d, %d)\n", i, j);
}

void liberarGrafo(GrafoMA *G){
    if(G){
        free(G->matriz);
        free(G);
    }
}

int main(){

    GrafoMA* grafo = iniciar_grafoMA(5);

    int arr[5][5] = {{1, 0, 1, 0, 0},
                    {0, 0, 0, 0, 1},
                    {1, 1, 1, 0, 0},
                    {1, 1, 0, 0, 0},
                    {1, 0, 1, 0, 1}}; 

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            inserir_aresta(grafo, i, j);
        }
    }

    imprimir_arestas(grafo);

    return 0;
}