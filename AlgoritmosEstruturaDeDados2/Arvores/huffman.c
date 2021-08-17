#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdint.h>
#define TAM 256

typedef struct node{
    unsigned char character;
    int frequency;
    struct node* left;
    struct node* right;
    struct node* next;
}Node;

typedef struct{
    Node* head;
    int size;
}List;

void initialize_table_zero(uint8_t tab[]){
    int i;
    for(i = 0; i < TAM; i++)
        tab[i] = 0;
}

void fill_frequency(unsigned char text[], uint8_t tab[]){
    int i = 0;

    while(text[i] != '\0'){
        tab[text[i]]++;
        i++;
    }
}

void print_frequencyTable(uint8_t tab[]){
    int i;
    printf("\tFrequency Table\n");
    for(i = 0; i < TAM; i++){
        if(tab[i] > 0)
            printf("\t%d = %u = %c\n", i, tab[i], i);
    }
}

void createList(List *list){
    list->head = NULL;
    list->size = 0;
}

void insert_order(List *list, Node *node){
    Node *aux;
    if(list->head == NULL){
        list->head = node;
    }
    else if(node->frequency < list->head->frequency){
        node->next = list->head;
        list->head = node;
    }
    else{
        aux = list->head;
        while (aux->next && aux->next->frequency <= node->frequency)
            aux = aux->next;
        node->next = aux->next;
        aux->next = node;
    }
    list->size++;
}

void fillList(uint8_t tab[], List *list){
    int i;
    Node *new;
    for(i = 0; i < TAM; i++){
        if(tab[i] > 0){
            new = malloc(sizeof(Node));
            if(new){
                new->character = i;
                new->frequency = tab[i];
                new->right = NULL;
                new->left = NULL;
                new->next = NULL;
                insert_order(list, new);
            }
            else{
                printf("\tError Allocation memory in 'fillList()'\n");
                break;
            }
        }
    }
}

void printList(List *list){
    Node *aux = list->head;

    printf("\t\nOrdered List: Size - %d", list->size);
    while (aux){
        printf("\tCharacter: %c Frequency: %d\n", aux->character, aux->frequency);
        aux = aux->next;
    }   
}

Node* remove_headNode(List *list){
    Node *aux = NULL;

    if(list->head){
        aux = list->head;
        list->head = aux->next;
        aux->next = NULL;
        list->size--;
    }

    return aux;
}

Node* createTree(List *list){
    Node* first;
    Node* second;
    Node* new;

    while(list->size > 1){
        first = remove_headNode(list);
        second = remove_headNode(list);
        new = malloc(sizeof(Node));

        if(new){
            new->character = '+';
            new->frequency = first->frequency + second->frequency;
            new->left = first;
            new->right = second;
            new->next = NULL;

            insert_order(list, new);
        }
        else{
            printf("\tError Allocation memory in 'fillList()'\n");
            break;
        }   
    }

    return list->head;
}

void printTree(Node* root, int size){
    if(root->left == NULL && root->right == NULL)
        printf("\tFolha: %c\tAltura: %d\n", root->character, size);

    else{
        printTree(root->left, size + 1);
        printTree(root->right, size + 1);
    }

}

int main(){

    setlocale(LC_ALL, "Portuguese");

    unsigned char text [] = "Trying a huffman tree";
    uint8_t frequencyTable[TAM];
    
    List list;
    Node *tree;

    initialize_table_zero(frequencyTable);
    fill_frequency(text, frequencyTable);
    print_frequencyTable(frequencyTable);


    createList(&list);
    fillList(frequencyTable, &list);
    printList(&list);   


    tree = createTree(&list);
    
    printf("\n\tHuffman Tree\n");
    printTree(tree, 0);

    return 0;
}