#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* insert0(Node *root, int num){
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

void insert(Node **ro)

void print(Node *root){
    if(root){
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

int main(){

    Node *root = NULL;
    int aux;
    srand(time(0));

    for(int i = 0; i < 10; i++){
        aux = rand() % 100 + 1;
        root = insert(root, aux);
        printf("Inserted: %i\n", aux);
    }

    print(root);

    return 0;
}