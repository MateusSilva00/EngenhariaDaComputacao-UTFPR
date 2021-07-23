#include <stdio.h>
#include <string.h>

typedef int Chave;
typedef char Valor[22];
typedef struct map{
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p){
    Map n = malloc(sizeof(struct map));
    n->chave = c;
    strcpy(n->valor, v);
    n->prox = p;
    return n;
}

void inserir(Chave c, Valor v, Map *L){
    while (*L != NULL && (*L)->chave < c) L = &(*L)->prox;
    if(*L != NULL && (*L)->chave == c) 
        strcpy((*L)->valor, v);
    else *L = no_map(c,v *L);
}

int remover(Chave c, Map *L){
    while(*L != NULL && (*L)->chave < c) L = &(*L)->prox;
    if(*L == NULL || (*L->chave > c))
        return 0;
    Map n = *L;
    *L = n->prox;
    free(n);
    return 1;
}

int pertm(Chave c, Valor v, Map L){
    while (L != NULL && L->chave < c)
        L = L->prox;
    if (L != NULL && L->chave == c)
        strcpy(v, L->valor);
    return (L != NULL && L->chave == c);
}

int main(){



    return 0;
}