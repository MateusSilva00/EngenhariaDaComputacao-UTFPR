#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create(int num){
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->data = num;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

Node *insert(Node *tree, int num){
    if(tree == NULL)
        tree = create(num);
    else if(num < tree->data)
        tree->left = insert(tree->left, num);
    else tree->right = insert(tree->right, num);

    return tree;
}

void Infix(Node* tree){
    if(tree){
        Infix(tree->left);
        printf("%d ", tree->data);
        Infix(tree->right);
    }
}

int sumNodes(Node* tree){
    if(!tree)
        return 0;
    else {
        return (tree->data + sumNodes(tree->left) + sumNodes(tree->right));
    }
}

int leafNodesQuant(Node* tree){
    if(tree == NULL)
        return 0;
    else if(tree->left == NULL && tree->right == NULL)
        return 1;
    else
        return leafNodesQuant(tree->left) + leafNodesQuant(tree->right);
}

int sumLeafNodes(Node* tree){
    if(tree == NULL)
        return 0;
    else if(tree->left == NULL && tree->right == NULL)
        return tree->data;
    else return sumLeafNodes(tree->left) + sumLeafNodes(tree->right);
}

int main(){

    Node *root = NULL;
    int arr[13] = {28, 12, 8, 3, 10, 9, 15, 16, 45, 36, 41, 59, 48};

    for(int i = 0; i < 13; i++){
        root = insert(root, arr[i]);
        // printf("Inserted: %d\n", arr[i]);
    }

    printf("Inorder traversal: ");
    Infix(root);
    printf("\nSum of all nodes: %d", sumNodes(root));

    printf("\nLeaf nodes quant: %d", leafNodesQuant(root));
    printf("\nSum of leaf nodes: %d", sumLeafNodes(root));
    return 0;
}