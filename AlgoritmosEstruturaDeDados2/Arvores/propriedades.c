#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

// Exemplo de impressoes
//             50
//     25              10
//         30
    
//     50 25 30 100
//     25 30 50 100

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* insert(Node *root, int num){
    if(root == NULL){
        Node *aux = malloc(sizeof(Node));
        aux->data = num;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if(num < root->data)
            root->left = insert(root->left, num);
        else
            root->right = insert(root->right, num); 
        return root;
    }
}

void leftView(Node *root){
    if(root){
        printf("%d ", root->data);
        leftView(root->left);
        leftView(root->right);
    }
}

void inorderTraversal(Node *root){
    if(root){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

Node* Search_v1(Node *root, int num){
    if(root){
        if(num == root->data)
            return root;
        else if(num < root->data)
            return Search_v1(root->left, num);
        else   
            return Search_v1(root->right, num);
    }
}

int Search_v2(Node *root, int num){
    while (root){
        if(num < root->data)
            root = root->left;
        else if(num > root->data)
            root = root->right;
        else  
            return 1;
    }
    return 0;
}

int height(Node *root){
    if(root == NULL)   
        return -1;
    else {
        int left = height(root->left);
        int right = height(root->right);
        if(left > right)
            return left + 1;
        else return right + 1;
    }
}

int nodeQuants(Node *root){
    if(root == NULL)
        return 0;
    else return 1 + nodeQuants(root->left) + nodeQuants(root->right);

    //Hardcore
    // return (raiz == NULL) ? 0 : 1 + nodeQuants(root->left) + nodeQuants(root->right);
}

int main(){

    Node *root = NULL;
    int aux;
    srand(time(0));

    int arr[] = {1, 2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i++){
        root = insert(root, arr[i]);
        printf("Inserted: %i\n", arr[i]);
    }

    int busca = Search_v2(root, 11);
    printf("Valor: %d\n", busca);

    // printf("\nLeft view: ");
    // leftView(root);
    
    // printf("\nInorder traversal: ");
    // inorderTraversal(root);
    
    // printf("\nNode quants: %d", nodeQuants(root));
    // printf("\nTree height %d", height(root));
    return 0;
}