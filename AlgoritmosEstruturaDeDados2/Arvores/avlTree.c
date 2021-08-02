#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1 

typedef struct node{
    int data;
    int fb; // fator de balanceamento
    struct node* left;
    struct node* right;
} Node;

Node* create( int data){
    Node* tree = (Node*) malloc(sizeof(Node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

static void rotateL(Node* tree){
    Node* auxA = tree->left;
    Node* auxB;
    
    // Quanto o filho esquerdo possui o fator de balanceamento positivo
    // então a rotação é LL
    if(auxA->fb == +1){
        tree->left = auxA->right;
        auxA->right = tree;
        tree->fb = 0;
        tree = auxA;
        printf("\nRotated LL");
    }
    else { // caso contrário, a rotação é LR
        auxB = auxA->right;
        auxA->right = auxB->left;
        auxB->left = auxA;
        tree->left = auxB->right;
        auxB->right = tree;
        printf("\nRotated LR");

        // Atualizando fatores de balanceamento
        if(auxB->fb == 1)
            tree->fb = -1;
        else tree->fb = 0;

        if(auxB->fb == -1)
            auxA->fb = +1;
        else auxA->fb = 0;


        tree = auxB;
    }
}

static void rotateR(Node *tree){
    Node* auxA = tree->right;
    Node* auxB;

    // Quanto o filho direito possui o fator de balanceamento positivo
    // então a rotação é RR
    if(auxA->fb == +1){
        tree->right = auxA->left;
        auxA->left = tree;
        tree->fb = 0;
        tree = auxA;
        printf("\nRotated RR");
    }
    else { // Caso contrário (fb negativo), a rotação é RL
        auxB = auxA->left;
        auxA->left = auxB->right;
        auxB->right = auxA;
        tree->right = auxB->left;
        auxB->left = tree;
        printf("\nRotated RL");

        // Atualização dos fatores de balanceamento
        if(auxB->fb == -1)
            tree->fb = +1;
        else tree->fb = 0;

        if(auxB->fb == +1)
            auxA->fb = -1;
        else auxA->fb = 0;

        tree = auxB;
    }

}

Node* insert(Node* tree, int value, int *grown){
    Node *auxA, *auxB;

    if(tree == NULL){
        tree = create(value);
        *grown = TRUE;
    }

    else if(value < tree->data){
        tree->left = insert(tree->left, value, grown);
        
        if(*grown){// verificar se aumentou a árvore pelo lado esquerdo
            switch (tree->fb){
                case -1: 
                    tree->fb = 0, *grown = FALSE; // AVL BALANCEADA
                break;

                case 0:
                    tree->fb = +1;
                break; 

                case +1:
                    rotateL(tree);
                    tree->fb = 0;
                    *grown = FALSE;
                break;
            }
        }
    }

    else if(value > tree->data){
        tree->right = insert(tree->right, value, grown);
        if(*grown){
            switch(tree->fb){
                case +1: 
                    tree->fb = 0;
                    *grown = FALSE;
                break;

                case 0:
                    tree->fb = -1;
                break;

                case -1:
                    rotateR(tree);
                    tree->fb = 0;
                    *grown = FALSE;
                break;
            }
        }
    }
    
    printf("\nInserted %d ", value);
    return tree;
}

int main(){

    Node *root = NULL;
    int value;
    char str;
    int stop = 0;
    int fb = 0;

    while (stop != 1){
        printf("Qual valor deseja inserir ? ");
        scanf("%d", &value);
        insert(root, value, &fb);
        printf("\nDeseja continuar: ");
        scanf("%d", &stop);
    }
    


    return 0;
}