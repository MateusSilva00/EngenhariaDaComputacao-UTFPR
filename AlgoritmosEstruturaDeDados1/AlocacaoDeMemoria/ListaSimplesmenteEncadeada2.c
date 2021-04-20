#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;


typedef struct{
  int chave;
  char produto[20];
  float valor;
}REGISTRO;

typedef struct aux{
  REGISTRO reg;
  struct aux* prox;
}ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
  int quant;
  PONT inicio;
}ListaSE;

ListaSE* Definir(){
  ListaSE *L;
  L = (ListaSE*) malloc(sizeof(ListaSE));
  if(L != NULL){
    L->quant = 0;
    L->inicio = NULL;
    return L;
  }
  return NULL;
}

booleano ListaVazia(ListaSE *L){
  if(L->quant == 0){
    printf("Lista Vazia!\n");
    return TRUE;
  }
  return FALSE;
}

ELEMENTO* CriarReg(char *s, float f){
  ELEMENTO* novo_produto;
  novo_produto = (ELEMENTO*) malloc(sizeof(ELEMENTO));
  novo_produto->reg.chave = rand() % 1000 + 1;
  strcpy(novo_produto->reg.produto, s);
  novo_produto->reg.valor = f;
  novo_produto->prox = NULL;
  return novo_produto;
}

booleano Inserir(ListaSE *L, ELEMENTO* novo_produto, int posicao){
  if(posicao < 0 || posicao > L->quant){
    return FALSE;
  }
  if (posicao == 0) {
    novo_produto->prox = L->inicio;
    L->inicio = novo_produto;
  }
  else{
    ELEMENTO* aux = L->inicio;
    int cont = 0;
    while (cont != posicao - 1) {
      aux = aux->prox;
      cont++;
    }
    novo_produto->prox = aux->prox;
    aux->prox = novo_produto;
  }
  L->quant++;
  return TRUE;
}

void tamanho(ListaSE *L){
  printf("%d \n", L->quant);
}

booleano Excluir(ListaSE *L){
  if(!ListaVazia(L)){
    ELEMENTO *atual = L->inicio;
    L->inicio = atual->prox;
    L->quant--;
    return TRUE;
  }
  return FALSE;
}


void Imprimir(ListaSE *L){
  PONT end = L->inicio;
  if(!ListaVazia(L)){
    printf("Lista:\n");
    for(int i = 0; i < L->quant; i++){
      printf("Item:%s\tPreço:%.2f\tChave:%i\n", strtok(end->reg.produto, "\n"), end->reg.valor, end->reg.chave);
      end = end->prox;
    }
    printf("\n");
  }
}

void inserir(ListaSE *L, int key){
  ELEMENTO* regs;
  __fpurge(stdin);
  char produto[100];
  float valor;

  printf("Produto: ");
  fgets(produto, sizeof(produto), stdin);
  printf("Valor: ");
  scanf("%f", &valor);
  regs = CriarReg(produto, valor);
  Inserir(L, regs, key);
}

void reinicilizarLista(ListaSE *L){
  L->quant = 0;
}

void limparTela(){
  system("clear");
}

int main(){
  srand(time(0));

  ListaSE *L;
  L = Definir();

  int opt, chave = 0;

  do {
    printf("\n=== Menu de Opções ===\n1 - Inserir Elemento\n2 - Remover Elemento\n3 - Imprimir Lista");
    printf("\n4 - Limpar Tela\n5 - Reiniciar Lista\n6 - Tamanho\n0 - SAIR\nOpção.: ");
    scanf("%d", &opt);

    switch (opt) {
      case 1:
        inserir(L, chave);
        chave++;
      break;

      case 2:
        Excluir(L);
      break;

      case 3:
        Imprimir(L);
      break;

      case 4:
        limparTela();
      break;

      case 5:
        reinicilizarLista(L);
      break;

      case 6:
        tamanho(L);
      break;

      case 0:
        system("exit");
      break;
    }

  } while(opt != 0);

  return 0;
}
