// 3. Um grupo de sobreviventes do apocalipse zumbi está circundado por uma horda de zumbis.
// Não existe esperança de vitória contra essa horda e os sobreviventes planejam uma fuga a
// cavalo. A questão principal nesse momento é que o grupo só dispõe de um único cavalo. É
// necessário estabelecer um critério de sorteio para ver qual sobrevivente fará uso desse cavalo
// para escapar do massacre. Regras do sorteio:
// o É sorteado um número N e o nome de um sobrevivente;
// o Iniciando no sobrevivente eles começam a contar no sentido horário;
// o O sobrevivente no qual a contagem N é finalizada é retirado do circulo;
// o Todo sobrevivente que sair do circulo não entra mais no processo;
// o O último sobrevivente é o felizardo para escapar com o cavalo.
// Implemente o sorteio utilizando uma lista encadeada circular.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

typedef int booleano;

typedef struct elem{
  struct elem* prox;
  struct elem* ant;
  char nome[20];
  int chave;
} no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}LDECirc;

LDECirc* Definir(){
  LDECirc* L = (LDECirc*) malloc(sizeof(LDECirc));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

no* CriarNo(const char *name, int key){
  no* novo = (no*) malloc(sizeof(no));
  strcpy(novo->nome, name);
  novo->prox = NULL;
  novo->ant = NULL;
  novo->chave = key;
  return novo;
}

booleano ListaVazia(LDECirc *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

booleano InserirUnico(LDECirc *L, no* novo){
  if(ListaVazia(L)){
    L->inicio = novo;
    L->fim = novo;
    L->quant = 1;

    L->inicio->prox = L->fim;
    L->inicio->ant = L->fim;
    return TRUE;
  }
  return FALSE;
}

booleano InserirPorPosicao(LDECirc* L, no* novo, int pos){
  if(pos < 0 || pos > L->quant)
    return FALSE;
  if(L->quant == 0)
    InserirUnico(L, novo);
  else{
    if(pos == 0){
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
    }
    else if(pos == L->quant){
      L->fim->prox = novo;
      novo->ant = L->fim;
      L->fim = novo;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
    }
    else{
      no* aux = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++)
        aux = aux->prox;

      aux->ant->prox = novo;
      novo->ant = aux->ant;
      aux->ant = novo;
      novo->prox = aux;
    }
    L->quant++;
  }
  return TRUE;
}

void Imprimir(LDECirc* L){
    if (L->quant == 0){
        printf("Lista vazia.\n\n");
    } else {
        no *aux;
        aux = L->inicio;
        for (int i=0; i<L->quant; i++){
            printf("[%d] %s\n", aux->chave, aux->nome);
            aux = aux->prox;
        }
    }
}

void RemoverUnico(LDECirc* L) {
  no* remov = L->inicio;
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  free(remov);
}

booleano RemoverPorPosicao(LDECirc* L, int pos){
  if(pos < 0 || pos > L->quant || L->quant == 0)
    return FALSE;
  if (L->quant == 1)
    RemoverUnico(L);
  else{
    if(pos == 0){
      no* aux = L->inicio;
      L->inicio = aux->prox;
      L->inicio->ant = L->fim;
      L->fim->prox = L->inicio;
      free(aux);
    }
    else if(pos == L->quant-1){
      no *aux = L->fim;
      L->fim = aux->ant;
      L->fim->prox = L->inicio;
      L->inicio->ant = L->fim;
      free(aux);
    }
    else{
      no* aux = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++)
        aux = aux->prox;
      aux->ant->prox = aux->prox;
      aux->prox->ant = aux->ant;
      free(aux);
    }
    L->quant--;
  }
  return TRUE;
}

void sorteio(LDECirc *L, no* remover, int num){
  if(L->quant > 1){
    no* aux = L->inicio;
    for(int i = 0; i < num; i++){
      remover = remover->prox;
    }
    printf("\nRemovendo: %s\n", remover->nome);
    if(num > L->quant) num = num - L->quant;
    RemoverPorPosicao(L, num);
    Imprimir(L);
    sorteio(L, aux, num);
  }
  else if(L->quant == 1)
  printf("O último sobrevivente é o felizardo %s", remover->nome);
}

int main(){

  LDECirc *L;
  L = Definir();

  no* f1 = CriarNo("Mateus Silva", 1);
  no* f2 = CriarNo("Pablo Escoblar", 2);
  no* f3 = CriarNo("Fernando Haddad", 3);
  no* f4 = CriarNo("Luíz Lula Inácio", 4);
  no* f5 = CriarNo("Messi", 5);
  no* f6 = CriarNo("Amy Winehouse", 6);

  srand(time(0));

  InserirPorPosicao(L, f1, 0);
  InserirPorPosicao(L, f2, 1);
  InserirPorPosicao(L, f3, 2);
  InserirPorPosicao(L, f4, 3);
  InserirPorPosicao(L, f5, 4);
  InserirPorPosicao(L, f6, 5);

  printf("\nUltimos sobreviventes do apocalipse\n");
  Imprimir(L);

  int num = rand() % 10 + 1;
  printf("\nNúmero sorteado: %d", num);

  no* aux = L->inicio;
  sorteio(L, aux, num);


  return 0;
}
