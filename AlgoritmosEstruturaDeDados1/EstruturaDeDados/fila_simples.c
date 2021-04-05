#include <stdio.h>

#define TAMFILA 15

//Fila / dequeue

int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;


void lista_elementos(){
  printf("\n=================== FILA ATUAL ===================\n");
  for(int i=0; i < TAMFILA; i++){
    printf("-");
    printf("|%d|", fila[i]);
    printf("-");
  }
  printf("\nHEAD: %d\n", head);
  printf("TAIL: %d\n", tail);
}

void enqueue(){
  int val;
  if (tail <  TAMFILA){ //Verifica se a fila está vazia
    printf("Informe o elemento para adicionar na fila: ");
    scanf("%d", &val);
    fila[tail] = val;
    tail++;
    lista_elementos();
  }
}

void dequeue(){
  if(head < tail){
    fila[head] = 0;
    head++;
    lista_elementos();
  }
}

void clear(){
  for(int i = 0; i < TAMFILA; i++){
    fila[i] = 0;
  }
  head = 0;
  tail = 0;
}

int main(){

  int opcao;

  do {
    printf("\nSelecione a opção:\n\n");
    printf("[1] - Inserir (enqueue): \n");
    printf("[2] - Remover (dequeue): \n");
    printf("[3] - Listar: \n");
    printf("[4] - Limpar Fila: \n");
    printf("[-1] - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);


    switch (opcao) {

      case 1:
        enqueue();
        break;

      case 2:
        dequeue();
        break;

      case 3:
        lista_elementos();
        break;

      case 4:
        clear();
        break;

      case -1:
        return 0;

      default:
        printf("Opção inválida!\n");
    }
  } while(opcao != -1);

}
