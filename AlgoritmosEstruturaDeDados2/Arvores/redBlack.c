#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int color; // 1 red / 0 black
    struct node* parent;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* bst(struct node* trav, struct node* temp){


    if(trav == NULL)
        return temp;
    
    if(temp->data < trav->data){
        trav->left = bst(trav->left, temp);
        trav->left->parent = trav;
    }
    else if(temp->data > trav->data){
        trav->right = bst(trav->right, temp);
        trav->right->parent = trav;
    }

    return trav;
}

void rightrotate(struct node* temp){
    struct node* left = temp->left;
    temp->left = left->right;
    if(temp->left)
        temp->left->parent = temp;
    left->parent = temp->parent;
    if(!temp->parent)
        root = left;
    else if(temp == temp->parent->left)
        temp->parent->left = left;
    else
        temp->parent->right = left;
    left->right = temp;
    temp->parent = left;
}

void leftrotate(struct node* temp){
    struct node* right = temp->right;
    temp->right = right->left;
    if(temp->right)
        temp->right->parent = temp;
    right->parent = temp->parent;
    if(!temp->parent)
        root = right;
    else if(temp == temp->parent->left)
        temp->parent->left = right;
    else
        temp->parent->right = right;
    right->left = temp;
    temp->parent = right;
}

void fixup(struct node* root, struct node* pt){
    struct node *parent_pt = NULL;
    struct node *grand_parent_pt = NULL;

    while((pt != root) && (pt->color != 0) && (pt->parent->color == 1)){
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if(parent_pt == grand_parent_pt->left){

            struct node* uncle_pt = grand_parent_pt->right;

            if(uncle_pt != NULL && uncle_pt->color == 1){
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }

            else{
                if(pt == parent_pt->right){
                    leftrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rightrotate(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }

        else {
            struct node* uncle_pt = grand_parent_pt->left;

            if((uncle_pt != NULL) && (uncle_pt->color == 1)){
                grand_parent_pt->color = 1;
                parent_pt->color = 0;
                uncle_pt->color = 0;
                pt = grand_parent_pt;
            }
            
            else {
                if(pt == parent_pt->left){
                    rightrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                leftrotate(grand_parent_pt);
                int t = parent_pt->color;
                parent_pt->color = grand_parent_pt->color;
                grand_parent_pt->color = t;
                pt = parent_pt;
            }
        }
    }
    root->color = 0;
}

void inorder(struct node *trav){
    if (trav == NULL)
        return;
    inorder(trav->left);
    printf("%d ", trav->data);
    inorder(trav->right);
}

int main(){

    int n = 7;
    int a[7] = {7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < n; i++){
        struct node* temp = (struct node*) malloc(sizeof(struct node));
        temp->right = NULL;
        temp->left = NULL;
        temp->parent = NULL;
        temp->data = a[i];
        temp->color = 1;

        root = bst(root, temp);
        fixup(root, temp);
    }

    printf("Inoder Traversal of Created Tree\n");
    inorder(root);

    return 0;
}