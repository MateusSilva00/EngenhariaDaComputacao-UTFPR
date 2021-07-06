#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct{
    char nome[20];
    float nota;
} elem;

typedef struct{
  elem pessoas[26];
}THash;

int definir(THash *T){
  for(int i=0; i < 26; i++){
    strcpy(T->pessoas[i].nome, "");
    T->pessoas[i].nota = -1;
  }
  return TRUE;
}

int FuncaoHash(char *nome){
  char primeiro;
  primeiro = nome[0];
    return primeiro - 97;
}


booleano inserir(THash *T, char *nome, float nota){
  int pos;
  pos = FuncaoHash(nome);

  if(T->pessoas[pos].nota != -1){
    printf("\nCOLISÃO!\n");
    return FALSE;
  }
  else{
    T->pessoas[pos].nota = nota;
    strcpy(T->pessoas[pos].nome, nome);
    printf("Inseriu:%s\n", nome);
    return TRUE;
  }
}

void buscar(THash *T, char *nome){
  int pos = FuncaoHash(nome);
  if(strcmp(nome, T->pessoas[pos].nome) == 0){
    printf("Nota: %.2f\n", T->pessoas[pos].nota);
  }
  else printf("Pessoa não cadastrada\n");
}

int main(){

  THash *T;
  T = (THash*) malloc(sizeof(THash));
  definir(T);
  char n[20];

  for(int i=0; i < 3; i++){
    __fpurge(stdin);
    printf("Digite nome: ");
    fgets(n, sizeof(n), stdin);
    float nt;
    printf("Digite nota: ");
    scanf("%f", &nt);

    inserir(T, n, nt);
  }

  __fpurge(stdin);
  printf("\nBuscar: ");
  fgets(n, sizeof(n), stdin);
  buscar(T, n);

  return 0;
}
