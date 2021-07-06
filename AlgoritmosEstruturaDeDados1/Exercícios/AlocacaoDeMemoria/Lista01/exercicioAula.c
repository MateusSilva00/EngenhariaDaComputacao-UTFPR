//Fazer uma busca que aceite posição negativa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
    struct elem* prox;
    struct elem* ant;
    char livro[100];
    float vl_preco;
}no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}ListaDE;

ListaDE* Definir(){
  ListaDE* L = (ListaDE*) malloc(sizeof(ListaDE));
  L->quant = 0;
  L->inicio = NULL;
  L->fim = NULL;
  return L;
}

booleano ListaVazia(ListaDE *L){
  if(L->quant == 0)
    return TRUE;
  return FALSE;
}

no* CriarNo(const char *name, float price){
  no* novo = (no*)malloc(sizeof(no));
  strcpy(novo->livro, name);
  novo->vl_preco = price;
  novo->prox = NULL;
  novo->ant = NULL;
  return novo;
}

booleano InserirUnico(ListaDE *L, no* novo){
  if(L->quant != 0)
    return FALSE;
  else {
    L->inicio = novo;
    L->fim = novo;
    L->quant = 1;
    return TRUE;
  }
}

booleano InserirPorPosicao(ListaDE* L, no* novo, int pos){
  if(pos < 0 || pos > L->quant)
    return FALSE;
  if(L->quant == 0){
    InserirUnico(L, novo);
  }
  else{
    if(pos == 0){
      L->inicio->ant = novo;
      novo->prox = L->inicio;
      L->inicio = novo;
    }
    else if(pos == L->quant){
      L->fim->prox = novo;
      novo-> ant = L->fim;
      L->fim = novo;
    }
    else{
      no* aux;
      int cont = 0;
      for(; cont < pos; cont++){
        aux = aux->prox;
      }
      aux->ant->prox = novo;
      novo->ant = aux->ant;
      aux->ant = novo;
      novo->prox = aux;
    }
    L->quant++;
  }
  return TRUE;
}

void RemoverInicio(ListaDE* L){
  if(!ListaVazia(L)){
    no *atual = L->inicio;
    L->inicio = atual->prox;
    L->inicio->ant = NULL;
    L->quant--;
  }
}

void RemoverFim(ListaDE* L){
  if(!ListaVazia(L)){
    no *atual = L->fim;
    L->fim = atual->ant;
    L->fim->prox = NULL;
    L->quant--;
  }
}

booleano RemoverPorPosicao(ListaDE* L, int pos){
  if(!ListaVazia(L)){
    if(pos < 0 || pos > L->quant)
      return FALSE;
    if(pos == 0){
      RemoverInicio(L);
    }
    else if(pos == L->quant-1){
      RemoverFim(L);
    }
    else{
      no* atual = L->inicio;
      int cont = 0;
      for(; cont < pos; cont++){
        atual = atual->prox;
      }
      atual->ant->prox = atual->prox;
      atual->prox->ant = atual->ant;
      free(atual);
      L->quant--;
    }
    return TRUE;
  }
  else return FALSE;
}

void ImprimirANT(ListaDE* L){
  if(ListaVazia(L))
    printf("Lista Vazia!\n\n");
  else{
    no *aux = L->fim;
    for(int i=0; i < L->quant; i++){
      printf("%s\t%.2f\n", aux->livro, aux->vl_preco);
      aux = aux->ant;
    }
  }
}

void ImprimirPROX(ListaDE* L){
  if(ListaVazia(L))
    printf("Lista Vazia!\n\n");
  else{
    no *aux = L->inicio;
    for(int i=0; i < L->quant; i++){
      printf("%s\t%.2f\n", aux->livro, aux->vl_preco);
      aux = aux->prox;
    }
  }
}

no* Obter(ListaDE *L, int posicao){
  if(ListaVazia(L) || posicao >= L->quant || posicao < (-L->quant)){
    return NULL;
  }
  else{
    if(posicao < 0){
      posicao = L->quant + posicao;
    }
    no* aux = L->inicio;
    int cont = 0;
    for(; cont < posicao; cont++){
      aux = aux->prox;
    }
    return aux;
  }
}

int main(){
  ListaDE *L;
  L = Definir();

  no* f1 = CriarNo("Refatoração: Aperfeiçoando o Design de Códigos Existentes", 82.91);
  no* f2 = CriarNo("Código Limpo", 70.99);
  no* f3 = CriarNo("Exame de Redes com Nmap", 133.17);
  no* f4 = CriarNo("Testes de Invasão", 80.50);

  InserirPorPosicao(L, f1, 0);
  InserirPorPosicao(L, f2, 1);
  InserirPorPosicao(L, f3, 2);
  InserirPorPosicao(L, f4, 3);
  ImprimirPROX(L);

  no *Tk = Obter(L, -4);
  if(Tk == NULL){
    printf("Valor não encontrado!\n");
  }
  else printf("\n%s %.2f", Tk->livro, Tk->vl_preco);



  return 0;
}
