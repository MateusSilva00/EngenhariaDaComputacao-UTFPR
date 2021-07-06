// 2. (4,0) Estamos novamente ajudando o Noé com sua arca v2.0. Desta vez, precisamos criar uma fila
// encadeada para armazenar os animais que estão prestes a entrar na arca.
// Deve ser registrado o tipo (leão, elefante, gato, cachorro, vaca, etc) e o sexo (macho ou fêmea) de cada animal.
// Além disso, não há garantia de que os animais forem inseridos de maneira ordenada na fila. Sendo assim,
// implemente uma função que retorna 1 caso exista apenas um animal de cada tipo e sexo na fila, e 0 caso
// existam repetidos.
// Cuidado: podem existir 2 animais do mesmo tipo na fila, desde que sejam de sexos diferentes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

typedef struct elem{
  char especie[35];
  int genero;
  struct elem* prox;
}no;

typedef struct{
  int quant;
  no* inicio;
  no* fim;
}Fila;

Fila* CriarFila(){
  Fila *F = (Fila*) malloc(sizeof(Fila));
  F->quant = 0;
  F->inicio = NULL;
  F->fim = NULL;
  return F;
}

no* CriarNo(const char *s, int genero){
  no* novo = (no*) malloc(sizeof(no));
  strcpy(novo->especie, s);
  novo->genero = genero;
  novo->prox = NULL;
  return novo;
}

void Inserir(Fila *F, no* novo){
  if(F->quant == 0){
    F->inicio = novo;
    F->fim = novo;
  }
  else{
      F->fim->prox = novo;
      F->fim = novo;
  }
  F->quant++;
}

const char* getGenero(int i){
  if(i == 1){
    return "Macho";
  }
  else return "Fêmea";
}

void Imprimir(Fila *F){
  no* aux = F->inicio;
  if(aux == NULL)
    printf("Fila Vázia!\n");

  for(int i = 0; i < F->quant; i++){
    const char* genero = getGenero(aux->genero);
    printf("%s - %s\n", aux->especie, genero);
    aux = aux->prox;
  }
}

booleano verificaArca(Fila *F, no* pos, int cont){
  if(cont < F->quant){
    no* aux = pos->prox;
    while (aux != NULL) {
      //COMPARA O GENERO E ESPECIE DO ANIMAL ATUAL COM O PRÓXIMO
      if(strcmp(pos->especie, aux->especie) == 0 && (pos->genero == aux->genero)){
        return FALSE;
      }
      aux = aux->prox;
    }
    cont++;
    // A FUNÇÃO CHAMA ELA MESMA ATÉ QUE O CONTADOR SEJA IGUAL A QUANTIDADE A ANIMAIS
    // PASSANDO COMO PARAMETRO O PRÓXIMO NÓ
    verificaArca(F, pos->prox, cont);
  }
  // CASO CONTRÁRIO RETORNA TRUE, OU SEJA 1
  else return TRUE;
}

int main(){

  Fila* F = CriarFila();
  no* n1;

  // ALTERAR OS VALORES 1-0 PARA VERIFICAR EFICIÊNCIA

  n1 = CriarNo("Penguim Super Sayajin", 1); Inserir(F, n1);
  n1 = CriarNo("Macaco do Rabo Cinza", 1); Inserir(F, n1);
  n1 = CriarNo("Giraffa sem pescoço", 1); Inserir(F, n1);
  n1 = CriarNo("Zebra das 9 caudas", 0); Inserir(F, n1);
  n1 = CriarNo("Macaco do Rabo Cinza", 0); Inserir(F, n1);
  n1 = CriarNo("Zebra das 9 caudas", 1); Inserir(F, n1);
  n1 = CriarNo("Elefante de 10 kilos", 1); Inserir(F, n1);
  n1 = CriarNo("Penguim Super Sayajin", 0); Inserir(F, n1);
  n1 = CriarNo("Elefante de 10 kilos", 0); Inserir(F, n1);
  n1 = CriarNo("Giraffa sem pescoço", 1); Inserir(F, n1);

  Imprimir(F);

  int ret = verificaArca(F, F->inicio, 0);

  if(ret == 0){
    printf("\nHÁ ANIMAIS REPETIDOS NA ARCA!\n");
  }
  else printf("\nNÃO HÁ ANIMAIS REPETIDOS NA ARCA!\n");


  return 0;
}
