#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode{
    char data;

    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeadNode** array;
};

struct MinHeadNode* newNode(char data, unsigned freq){
    struct MinHeadNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeadNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp; 
}


int main(){

    return 0;
}