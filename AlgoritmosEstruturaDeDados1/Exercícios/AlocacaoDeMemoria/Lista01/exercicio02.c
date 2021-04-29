// 2) Joãozinho e Juquinha gostam muito de jogar bafo. Para quem não sabe, este jogo inicia
// com uma pilha de figurinhas. A cada jogada, um dos jogadores terá a chance de bater na
// pilha, tentando virar algumas figurinhas. As que forem viradas passam a pertencer a este
// jogador.
// Joãozinho tem uma técnica apurada, que às vezes é capaz de virar 4 figurinhas com uma só
// jogada. Entretanto, quando esta técnica falha, nenhuma se vira.
// Já a técnica de Juquinha garantidamente vira sempre no mínimo 1 figurinha, mas no máximo
// 2.
// Simule computacionalmente partidas entre Joãozinho e Juquinha, iniciando com 20
// figurinhas na pilha e Joãozinho como 1º jogador. Se a técnica dos 2 funcionar ao máximo em
// todas jogadas, quantas jogadas serão no total? Imprima quantas figuras terá Joãozinho e
// quantas terá Juquinha. E no caso das técnicas de ambas falharem em todas as jogadas?
// Imprima também.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
typedef int booleano;

//TABELA DO BRASILEIRÃO
typedef struct elem{
  int id;
  char posicao[1];
  struct elem* anterior;
} no;

typedef struct{
  int quant;
  no* topo;
}Pilha;

booleano Definir(Pilha *P){
  if(P == NULL)
    return FALSE;
  P->quant = 0;
  P->topo = NULL;
  return TRUE;
}

Pilha* CriarPilha(){
  Pilha* P = (Pilha*)malloc(sizeof(Pilha));
  if(P == NULL)
    return P;
  P->quant = 0;
  P->topo = NULL;
  return P;
}

booleano PilhaVazia(Pilha *P){
  if(P->quant == 0){
    return TRUE;
  }
  else return FALSE;
}

void Push(Pilha *P, no *novo){
  if(PilhaVazia(P))
    P->topo = novo;
  else{
    novo->anterior = P->topo;
    P->topo = novo;
  }
  P->quant++;
}

void tamanho(Pilha *P){
  printf("Tamanho da pilha: %d", P->quant);
}

booleano PopN(Pilha *P, int posicao){
  int i=0;
  if(!PilhaVazia(P)){
    while (i < posicao) {
      no* aux = P->topo;
      P->topo = P->topo->anterior;
      P->quant--;
      free(aux);
      aux = aux->anterior;
      i++;
    }
    return TRUE;
  }
  return FALSE;
}

no* CriarNo(int i, const char *carta){
  no* novo;
  novo = (no*) malloc(sizeof(no));
  novo->id = i;
  strcpy(novo->posicao, carta);
  novo->anterior = NULL;
  return novo;
}

void Imprimir(Pilha *P){
  if(!PilhaVazia(P)){
    no* aux;
    aux = P->topo;
    while (aux != NULL) {
      printf("%s ", aux->posicao);
      aux = aux->anterior;
    }
  }
  printf("\n");
}

void joaozinho(Pilha *P, int *pontos){
  if(!PilhaVazia(P)){
    int n = rand() % 4 + 1;
    if(n <=2) n = 0;
    else n = 4;
    printf("Turno de Joãozinho!\n");
    if(n >= P->quant){
      n = P->quant;
      PopN(P, n);
      printf("Joãozinho virou o restante das %d cartas!\n", n);
      *pontos = *pontos + P->quant;
    }
    else{
      PopN(P, n);
      printf("Joãozinho virou %d cartas \n\n", n);
      *pontos = *pontos + n;
    }
  }
}


void mariazinha(Pilha *P, int *pontos){
  if(!PilhaVazia(P)){
    int n = rand() % 10 + 1;
    if(n <=4 ) n = 1;
    else n = 2;
    printf("Turno de Mariazinha!\n");
    if(n >= P->quant){
      n = P->quant;
      printf("Mariazinha virou o restante das %d cartas!\n", n);
      *pontos = *pontos + n;
      PopN(P, n);
    }
    else{
      printf("Mariazinha virou %d cartas \n\n", n);
      *pontos = *pontos + n;
      PopN(P, n);
    }
  }
}

void verifica_vencedor(int pMaria, int pJoao, int turnos){
  if(pMaria > pJoao){
    printf("Maria venceu o jogo!\n");
  }
  else if(pMaria < pJoao){
    printf("João venceu o jogo!\n");
  }
  else printf("O jogo foi um empate!\n");

  printf("\n\n=== ESTATÍSTICAS DA PARTIDA ===\n");
  printf("Joãozinho: %d pts\nMariazinha: %d pts\nTurnos: %d", pJoao, pMaria, turnos);

}

int main(){
  srand(time(0));
  Pilha P;
  Definir(&P);

  no* n1;
  for(int i=0; i < 20; i++){
    n1 = CriarNo(i, "*");
    Push(&P, n1);
  }

  int pMaria = 0;
  int pJoao = 0;
  int turnos = 0;

  printf("=== BARALHO DE 20 CARTAS ===\n");
  Imprimir(&P);
  while (!PilhaVazia(&P)) {
    joaozinho(&P, &pJoao);
    mariazinha(&P, &pMaria);
    Imprimir(&P);
    turnos++;
  }

  verifica_vencedor(pMaria, pJoao, turnos);

  return 0;
}
