#include "LSE2.c"
#include <stdio.h>

void reinicilizarLista(ListaSE *L){
  PONT end = L->inicio;
  while (end != NULL) {
    PONT apagar =end;
    L->quant--;
    end = end->prox;
    free(apagar);
  }
  L->inicio = NULL;
}

void limparTela(){
  system("clear");
}

int main(){
  srand(time(0));

  ListaSE *L;
  L = Definir();
  ELEMENTO *aux;

  int opt, chave = 0;
  char busca[20];

  do {
    printf("\n=== Menu de Opções ===\n1 - Inserir Elemento\n2 - Remover Elemento\n3 - Imprimir Lista");
    printf("\n4 - Limpar Tela\n5 - Reiniciar Lista\n6 - Tamanho\n7 - Busca Produto\n0 - SAIR\nOpção.: ");
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

      case 7:
        __fpurge(stdin);
        printf("Qual produto deseja procurar.: ");
        fgets(busca, sizeof(busca), stdin);
        aux = buscaProduto(L, busca);
        if(aux == NULL){
          printf("Produto não encontrado na lista!\n");
        }
        else printf("%s está na lista e custa R$%2.f", busca, aux->reg.valor);

      case 0:
        system("exit");
      break;
    }

  } while(opt != 0);

  return 0;
}
