#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int key;
    int color; // 0 - red 1 - black
    struct node *father;
    struct node *left;
    struct node *right;
} Node;

Node* create(int k){
    Node* tree = (Node*) malloc(sizeof(Node));
    tree->key = k;
    tree->color = 0;
    tree->left = NULL;
    tree->right = NULL;
    tree->father = NULL;

    return tree;
}

Node* obter_avo(Node *no){
   if((no != NULL) && (no->father != NULL))
        return no->father->father;
    return NULL;
}

Node* obter_tio(Node *no){
    Node* avo = obter_avo(no);
    Node* aux = NULL;

    if(avo != NULL){
        if(avo->left == no->father)
            aux = avo->right;
        else aux = avo->left;
    }
    return aux;
}

Node *rotacionar_dir(Node *x){
    Node *p = x->father;
    Node *a = p->father; 

    p->father = a->father;

    if (a->father != NULL){

        if (a->father->left == a)
            a->father->left = p;
        else
            a->father->right = p;
    }

    a->father = p;
    a->left = p->right;
    p->right = a;

    x = p;

    return x;
}

Node *rotacionar_esq(Node *x){
    Node *p = x->father; 
    Node *a = p->father; 

    p->father = a->father;

    if (a->father != NULL){

        if (a->father->right == a)
            a->father->right = p;
        else
            a->father->left = p;
    }

    a->father = p;
    a->right = p->left;
    p->left = a;

    x = p;

    return x;
}

Node *rotacionar_dir_esq(Node *x){
    Node *p = x->father;
    Node *a = p->father; 

    x->father = a;
    a->left = x;
    p->left = x->right;
    x->right = p;
    p->father = x;

    x = rotacionar_esq(p);

    return x;
}

Node *rotacionar_esq_dir(Node *x){
    Node *p = x->father; 
    Node *a = p->father; 

    x->father = a;
    a->left = x;
    p->father = x;
    p->right = x->left;
    x->left = p;

    x = rotacionar_dir(p);

    return x;
}

Node *balance(Node*x){
    Node *pai;
    Node*tio;

    if (x->father == NULL)
        x->color = 1;
    else {
        pai = x->father;

        if (pai->color == 0){
            tio = obter_tio(x);

            if ((tio != NULL) && (tio->color == 0)){
                pai->color = tio->color = 1;
                x = obter_avo(x);

                if (x->father != NULL)
                    x->color = 0;
            }
            else { 
                if (pai->left == x) { 
                    if (pai->father->left == pai)
                        x = rotacionar_dir(x);
                    else
                        x = rotacionar_dir_esq(x); 
                }
                else {
                    if (pai->father->right == pai)
                        x = rotacionar_esq(x); 
                    else
                        x = rotacionar_esq_dir(x); 
                }

                x->color = 1;

                if (x->left != NULL)
                    x->left->color = 0;

                if (x->right != NULL)
                    x->right->color = 0;
            }
        }
    }

    return x;
}

Node *insert(Node* tree, int key){
    Node *auxP;
    Node *auxF;

    if (tree == NULL){
        tree = create(key);
        tree->color = 1;
    }
    else{
        auxP = auxF = tree;

        while (auxF != NULL)
        {
            auxP = auxF;

            if (key < auxF->key)
                auxF = auxF->left;
            else
                auxF = auxF->right;
        }

        auxF = create(key);
        auxF->father = auxP;

        if (auxF->key < auxP->key)
            auxP->left = auxF;
        else
            auxP->right = auxF;

        while ((auxF->father != NULL) && (auxF->color == 0) && (auxF->father->color == 0))
            auxF = balance(auxF);

        while (auxF->father != NULL)
            auxF = auxF->father;

        tree = auxF;
    }
    return tree;
}

int qtBlack(Node *tree){
    if(tree == NULL)
        return 0;
    else {
        return (tree->color == 1 ? 1 : 0) + qtBlack(tree->left) + qtBlack(tree->right);
    }
}

int qtRed(Node *tree){
    if (tree == NULL)
        return 0;
    else{
        return (tree->color == 0 ? 1 : 0) + qtRed(tree->left) + qtRed(tree->right);
    }
}

int main(){

    Node *root = NULL;

    int arr[] = {38, 40, 21, 18, 30, 22, 37, 8, 70};

    for(int i = 0; i < 9; i++){
        root = insert(root, arr[i]);
        printf("Inserted: %i!\n", arr[i]);
    }


    int black = qtBlack(root);
    int red = qtRed(root);
    printf("\nQuantidade Black %d", black);
    printf("\nQuantidade Red %d", red);

    return 0;
}