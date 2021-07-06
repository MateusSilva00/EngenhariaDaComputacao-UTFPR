#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TABLE_SIZE 100000

typedef struct entry_t {
  char *key;
  char *value;
  struct entry_t *next;
} entry_t;

typedef struct {
  entry_t **entries;
} ht_t;

unsigned int hash(const char *key){
  unsigned long int value = 0;
  unsigned int i = 0;
  unsigned int key_len = strlen(key);

  for(; i < key_len; ++i){
    value = value * 37 + key[i];
  }

  value = value % TABLE_SIZE;

  return value;
}

entry_t *ht_pair(const char *key, const char *value){
  entry_t *entry = malloc(sizeof(entry) * 1);
  entry->key = malloc(strlen(key) + 1);
  entry->value = malloc(strlen(value) + 1);

  strcpy(entry->key, key);
  strcpy(entry->value, value);

  entry->next = NULL;

  return entry;
}

ht_t *ht_create( ) {
  // Aloca espaço para tabela
  ht_t *hashtable = malloc(sizeof(ht_t) * 1);

  // Aloca espaço para espaço da tabela
  hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

  int i = 0;
  for(; i < TABLE_SIZE; ++i){
    hashtable->entries[i] = NULL;
  }
  return hashtable;
}

void ht_set(ht_t *hashtable, const char *key, const char *value){
  unsigned int slot = hash(key);

  entry_t *entry = hashtable->entries[slot];

  if(entry == NULL){
    hashtable->entries[slot] = ht_pair(key, value);
    return;
  }

  entry_t *prev;

  while (entry != NULL) {
    if(strcmp(entry->key, key) == 0){
      free(entry->value);
      entry->value = malloc(strlen(value) + 1);
      strcpy(entry->value, value);
      return;
    }
    prev = entry;
    entry = prev->next;
  }
  prev->next = ht_pair(key, value);
}

char *ht_get(ht_t *hashtable, const char *key){
  unsigned int slot = hash(key);

  entry_t *entry = hashtable->entries[slot];

  if(entry == NULL)
    return NULL;

  while (entry != NULL) {
      if(strcmp(entry->key, key) == 0){
        return entry->value;
      }

      entry = entry->next;
  }
  return NULL;
}

void ht_dump(ht_t *hashtable){
  for(int i = 0; i < TABLE_SIZE; ++i){
    entry_t *entry = hashtable->entries[i];

    if(entry == NULL)
      continue;

    printf("Slot[%d]: ", i);

    for(;;){
      printf("%s = %s ", entry->key, entry->value);
      if(entry->next == NULL)
        break;
      entry = entry->next;
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {

  ht_t *ht = ht_create();

  ht_set(ht, "name1", "USA");
  ht_set(ht, "name2", "FRANCE");
  ht_set(ht, "name3", "SWEDEN");
  ht_set(ht, "name4", "NORWAY");
  ht_set(ht, "name5", "FINLAND");
  ht_set(ht, "name6", "RUSSIA");
  ht_set(ht, "name7", "BRAZIL");

  ht_dump(ht);

  return 0;
}
