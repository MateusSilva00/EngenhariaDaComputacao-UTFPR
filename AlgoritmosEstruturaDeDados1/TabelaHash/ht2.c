#include <stdio.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 11

typedef struct node {
  unsigned int value;
  struct node* next;
} node;

void insert_new_node(node** head, int new_value) {
  node* new_node = malloc(sizeof(node*));
  new_node->value = new_value;
  new_node->next = NULL;

  if(*head == NULL) {
    *head = new_node;
  }
  else {
    node* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

int get_location(int new_value) {
  return new_value % HASHTABLE_SIZE;
}

void insert_into_table(node** hashtable, int new_value) {
  int location = get_location(new_value);
  if(hashtable[location] == NULL) {
    hashtable[location] = malloc(sizeof(node*));

    node* head = NULL;
    insert_new_node(&head, new_value);

    hashtable[location] = head;
  }
  else {
    node* head = hashtable[location];
    insert_new_node(&head, new_value);
    hashtable[location] = head;
  }
}

void display_table(node** hashtable) {
  for(int i = 0; i < HASHTABLE_SIZE; i++) {
    node* head = hashtable[i];

    printf("[%d]: ", i);
    if(head == NULL)
      printf("NULL");
    else {
      node* current = head;
      while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
      }
    }
    printf("\n");
  }
}

node** get_hashtable() {
  node** hashtable = calloc(HASHTABLE_SIZE, sizeof(node*));
  return hashtable;
}

int main(){

  node** table = get_hashtable();

  insert_into_table(table, 0);
  insert_into_table(table, 2);
  insert_into_table(table, 78);
  insert_into_table(table, 12);
  insert_into_table(table, 9);
  insert_into_table(table, 6);

  insert_into_table(table, 4);
  insert_into_table(table, 1);
  insert_into_table(table, 5);
  insert_into_table(table, 9);
  insert_into_table(table, 10);
  insert_into_table(table, 11);

  insert_into_table(table, 65);
  insert_into_table(table, 321);
  insert_into_table(table, 72);
  insert_into_table(table, 10);
  insert_into_table(table, 3);
  insert_into_table(table, 37);

  display_table(table);

  return 0;
}
