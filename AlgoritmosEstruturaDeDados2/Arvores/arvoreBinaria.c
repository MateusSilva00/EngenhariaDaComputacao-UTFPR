#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;

    struct Node* left;
    struct Node *right;
} Node;

Node* insert(Node *root, int data){
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    } else {
        Node* current = root;
        Node* parent = NULL;
        while (1){
            parent = current;
            if(data < parent -> data){
                current = current->left;
                if(current == NULL){
                    parent->left = temp;
                    return root;
                }
            } else {
                current = current->right;
                if(current == NULL){
                    parent->right = temp;
                    return root;
                }
            }
        }        
    }

    return root;
}

void inorder_traversal(struct Node* root){
    if(root){
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

Node* search(Node *root, int data){
    Node* current = root;
    printf("Visiting elements: ");

    while (current){
        printf("%d ", current->data);
        if(data < current->data){
            current = current->left;
        } else if(data > current->data){
            current = current->right;
        } else {
            return current;
        }
    }   
}

int main(){

    int i;
    int array[14] = {34, 84, 15, 0, 2, 99, 79, 9, 88, 89, 18, 31, 39, 100};
    Node *root = NULL;

    for(i = 0; i < 14; i++){
        root = insert(root, array[i]);
        printf("Inserted: %d\n", array[i]);
    }

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    int temp =  search(root, 88);
    if(temp){
        printf("\n[%d][%i] Found!\n", temp, 88);
    } else {
        printf("[x] (%d) Not found!\n", 88);
    }

    return 0;
}