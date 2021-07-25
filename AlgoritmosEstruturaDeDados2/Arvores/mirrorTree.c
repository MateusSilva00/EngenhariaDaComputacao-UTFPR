#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* create(int num){
    Node *tree = (Node *)malloc(sizeof(Node));
    tree->data = num;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node* insert(Node *tree, int num){
    if (tree == NULL)
        tree = create(num);
    else if (num < tree->data)
        tree->left = insert(tree->left, num);
    else
        tree->right = insert(tree->right, num);

    return tree;
}

void swap(Node **a, Node **b){
    Node* aux = *a;
    *a = *b;
    *b = aux;
}

Node* mirrorTree(Node *tree){
    if(tree == NULL)
        return tree;
    swap(&tree->left, &tree->right);

    if(tree->left != NULL)
        mirrorTree(tree->left);
    if(tree->right != NULL)
        mirrorTree(tree->right);
    
    return tree;
}

void Infix(Node *tree){
    if (tree != NULL){
        Infix(tree->left);
        printf("%d ", tree->data);
        Infix(tree->right);
    }
}

int main(){

    Node *root = NULL;
    int value;
    srand(time(0));

    // int arr[8] = {4, 2, 6, 1, 3, 5, 10, 8};
    // for(int i = 0; i < 8; i++){
    //     root = insert(root, arr[i]);
    // }

    for(int i = 0; i < 6; i++){
        value = rand() % 100 + 1;
        printf("\nInserted %d", value);
        root = insert(root, value);
    }

    printf("\nInfix: ");
    Infix(root);
    mirrorTree(root);
    printf("\nInfix mirror tree: ");
    Infix(root);

    return 0;
}