#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ORDEM 5
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct nodeB{
    int nro_chaves; //quantida de chaves na pagina
    int chaves[ORDEM-1]; //elementos da página
    struct nodeB *filhos[ORDEM];
    booleano verify_folha; // verificar se a página é folha 
} NodeB;

NodeB* create(){
    NodeB *tree = malloc(sizeof(NodeB));
    int i;
    
    tree->verify_folha = TRUE;
    tree->nro_chaves = FALSE;

    for(i = 0; i < ORDEM; i++)
        tree->filhos[i] = NULL;
    
    return tree;
}

int liberar(NodeB *tree){
    if(tree){
        free(tree);
        return TRUE;
    }
    return FALSE;
}

int binary_search(int key, NodeB *tree){
    int ini, fim, meio;

    if(tree){
        ini = 0;
        fim = tree->nro_chaves - 1;

        while (ini <= fim){
            meio = (ini + fim) / 2;

            if(tree->chaves[meio] == key)
                return meio;
            
            else if(tree->chaves[meio] > key)
                fim = meio - 1;
            else ini = meio + 1;
        }
        return ini;
    }
    return -1;
}

int linearSearch(int key, NodeB *tree){
    int i;

    if(tree){
        for(i = 0; i < tree->nro_chaves && key < tree->chaves[i]; i++);

        if(key == tree->chaves[i])
            return TRUE;
        else return linearSearch(key, tree->filhos[i]);
    }

    return FALSE;
}

int search(int key, NodeB *tree){
    int pos = binary_search(key, tree);

    if(pos >= 0){
        if(tree->chaves[pos] == key)
            return TRUE;
        else return search(key, tree->filhos[pos]);
    }

    return FALSE;
}

NodeB* split_pag(NodeB *pai, int posF_cheio){
    int i;
    NodeB *pag_esq = pai->filhos[posF_cheio];

    NodeB *pag_dir;
    pag_dir = create();

    pag_dir->verify_folha = pag_esq->verify_folha;

    pag_dir->nro_chaves = round((ORDEM - 1) / 2);

    for(i = 0; i < pag_dir->nro_chaves; i++)
        pag_dir->chaves[i] = pag_esq->chaves[i + pag_dir->nro_chaves];

    if(!pag_esq->verify_folha)
        for(i=0; i < pag_dir->nro_chaves; i++)
            pag_dir->filhos[i] = pag_esq->filhos[i + pag_dir->nro_chaves];
    pag_esq->nro_chaves = (ORDEM - 1) / 2;

    for(i = pai->nro_chaves + 1; i > posF_cheio + 1; i--)
        pai->filhos[i + 1] = pai->filhos[i];

    pai->filhos[posF_cheio + 1] = pag_dir;

    pai->filhos[posF_cheio] = pag_esq;

    pai->chaves[posF_cheio] = pag_dir->chaves[0];

    pai->nro_chaves++;

    for(i = 0; i < pag_dir->nro_chaves; i++)
        pag_dir->chaves[i] = pag_dir->chaves[i + 1];
    pag_dir->nro_chaves--;

    return pai;
}

NodeB* insertNotFullPage(NodeB *tree, int key){

    int i;
    int pos = binary_search(key, tree);

    if(tree->verify_folha){

        for(i = tree->nro_chaves; i > pos; i--)
            tree->chaves[i] = tree->chaves[i - 1];

        tree->chaves[i] = key;

        tree->nro_chaves++;

    }
    else { 

        if(tree->filhos[pos]->nro_chaves == ORDEM - 1){
            tree = split_pag(tree, pos);

            if(key > tree->chaves[pos])
                pos++;
        }

        tree->filhos[pos] = inserir_pagina_nao_cheia(tree->filhos[pos], key);
    }
    return tree;
}

NodeB* insert(NodeB *tree, int key){
    NodeB *aux = tree;
    NodeB *nova_pag;

    if(aux->nro_chaves == ORDEM - 1){
        nova_pag = create();

        tree = nova_pag;
        nova_pag->verify_folha = FALSE;
        nova_pag->filhos[0] = aux;

        nova_pag = split_pag(nova_pag, 0);
        nova_pag = inserir_pagina_nao_cheia(nova_pag, key);

        tree = nova_pag;
    }
    else tree = inserir_pagina_nao_cheia(aux, key);

    return tree;
}

void runLeafs(NodeB *tree, int *sum, int *quant){
    if(tree){
        if(tree->verify_folha){
            for(int i = 0; i < tree->nro_chaves; i++){
                printf("%d ", tree->chaves[i]);
                *sum = *sum + tree->chaves[i];
                *quant = *quant + 1;
            }
            printf("\n");
        }
        else {
            for(int j = 0; j < ORDEM; j++)
                runLeafs(tree->filhos[j], sum, quant);
        }
    }
}

void fullPages(NodeB *tree, int *quant){
    if(tree){
        if(tree->nro_chaves == ORDEM - 1)
            *quant = *quant + 1;
        for(int i = 0; i < ORDEM; i++){
            fullPages(tree->filhos[i], quant);
        }
    }
}

int main(){

    NodeB* root = create();
    // int sum = 0;
    // int quant = 0;
    // runLeafs(root, &sum, &quant);
    // printf("Média das folhas: %d\n", sum / quant);
    

    // int arr[17] = {1, 2, 3, 5, 6, 8, 10, 12, 14, 19, 21, 22, 25, 34};
    int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    for (int i = 0; i < 16; i++){
        printf("Inserted: %d\n", arr[i]);
        root = insert(root, arr[i]);
    }
    
    int quant = 0;
    fullPages(root, &quant);
    printf("Quantidade páginas cheias: %d", quant);


    return 0;
}