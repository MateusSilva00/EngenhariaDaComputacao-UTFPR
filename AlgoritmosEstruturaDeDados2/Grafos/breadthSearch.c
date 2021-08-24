#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct elem{
    int id;
    struct elem* next;
}Node;

typedef struct queue{
    int quant;
    Node* top;
    Node* end;
}Queue;

Queue* CreateQueue(){
    Queue* Q = (Queue*) malloc(sizeof(Queue));
    if(!Q)
        return Q;
    Q->quant = 0;
    Q->top = NULL;
    return Q;
}

boolean emptyQueue(Queue *Q){
    if(Q->quant == 0)
        return TRUE;
    else return FALSE;
}

Node *newNode(int i){
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    new->id = i;
    new->next = NULL;
    return new;
}

void Enqueue(Queue *Q, int i){
    Node* new = newNode(i);
    if(Q->quant == 0){
        Q->top = new;
        Q->end = new;
    }
    else{
        Q->end->next = new;
        Q->end = new;
    }
    Q->quant++;
}

boolean Dequeue(Queue *Q){
    Node* aux = Q->top;
    if(!emptyQueue(Q)){
        Q->top = Q->top->next;
        Q->quant--;
        free(aux);
        return TRUE;
    }
    else return FALSE;
}

void printQueue(Queue *Q){
    Node* aux = Q->top;

    if(!aux)
        printf("Empty Queue!\n");
    
    while (aux){
        printf("%d ", aux->id);
        aux = aux->next;
    }
    printf("\n");
}

typedef struct graphAM{
    int V;
    int A;
    boolean *visited;
    int **matrix;
}GraphAM;

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
    boolean *visited = (boolean *)malloc(v * sizeof(boolean));

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

int edgeExist(GraphAM *G, int v1, int v2){
    return (G) && validadeVertex(G, v1) && validadeVertex(G, v2) && (G->matrix[v1][v2] == 1);
}

void printBreadth(int parent[], int distance[], GraphAM *G){
    printf("v d p\n");
    for (int i = 0; i < G->V; i++){
        if(parent[i] < 0 || G->visited[i] == FALSE){
            if(parent[i] < 0 && G->visited[i] != FALSE)
                printf("%d %d -\n", i, distance[i]);
            else printf("%d - -\n", i);
        }
        else printf("%d %d %d\n", i, distance[i], parent[i]);
    }
}

void breadthSearch(GraphAM *G, int root){

    Queue* Q = CreateQueue();

    for (int i = 0; i < G->V; i++){
        G->visited[i] = FALSE;
    }

    Enqueue(Q, root);
    G->visited[root] = TRUE;

    int vis;
    int distance[G->V];
    int parent[G->V];

    distance[root] = 0;
    parent[root] = -1;
    
    while (!emptyQueue(Q)){
        vis = Q->top->id;
        Dequeue(Q);
        
        for(int i = 0; i < G->V; i++){
            if(G->matrix[vis][i] == TRUE && (!G->visited[i])){
                Enqueue(Q, i);
                G->visited[i] = TRUE;
                distance[i] = distance[vis] + G->matrix[vis][i];
                parent[i] = vis;
            }     
        }

    }
    printBreadth(parent, distance, G);
}

void printMatrix(GraphAM *G){
    int i, j;
    for (i = 0; i < G->V; i++)
    {
        for (j = 0; j < G->V; j++)
        {
            printf("%d ", G->matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){

    GraphAM *graph = NULL;
    int size, root; 
    scanf("%d", &size);
    
    graph = readGraph(graph, size);

    printMatrix(graph);
    scanf("%d", &root);
    
    breadthSearch(graph, root);


    return 0;
}

/* 
INPUT
5
0 1 1 0 1
1 0 0 0 0
1 0 0 1 0
0 0 1 0 1
1 0 0 1 0
1
*/