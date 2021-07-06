#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct{
  int id;
  char info[50];
} elem;

typedef struct{
  int nelem;
  elem A[MAX];
}Lista;

void Definir(Lista *L){
  L->nelem=0;
}

int Fim(Lista *L){
  return(L->nelem);
}

int Lista_vazia(Lista *L){
  return (L->nelem == 0);
}

int Lista_cheia(Lista *L){
  return(L->nelem == MAX);
}

elem* Obter(Lista *L, int p){
  if(p >= Fim(L) || p < 0 || Lista_vazia(L))
    return NULL;
  else return &(L->A[p]);
}

int Inserir(elem* valor, int p, Lista *L){
  /* Insere elemento x na posicao p da Lista L.
  Devolve true se sucesso, false se L cheia ou nao tem posicao p. L nao ordenada! */
  int atual;
  if(Lista_cheia(L))
    return 0;
  else if (p > Fim(L) || p < 0)
    return 0; // Posição não existe
  else{
    for(atual = L->nelem-1; atual >= p; atual--)
      L->A[atual+1] = L->A[atual];
    L->A[p] = *valor;
    L->nelem++;
    return 1; // Valor inserido com sucesso
  }
}

int Remover(Lista *L, int p){
  int atual;
  if(p >= Fim(L) || p < 0 || Lista_vazia(L))
    return 0;
  else{
    for(atual = p+1; atual <= L->nelem; atual++)
      L->A[atual-1] = L->A[atual];
    L->nelem--;
  }
  return 1;
}

int main(){

  srand(time(0));

  int opt, aux, posicao;
  Lista chamada;
  Definir(&chamada);

  elem novo;
  elem *aluno;

  system("clear");

  do {
    printf("\n1 - Cadastrar Aluno\n2 - Remover Aluno\n3 - Obter\n0 - Sair\n");
    scanf("%d", &opt);
    switch (opt) {
      case 1:
        system("clear");
        __fpurge(stdin);
        printf("Digite o nome do aluno: ");
        fgets(novo.info, sizeof(novo.info), stdin);
        // scanf("%s", &novo.info);

        novo.id = rand() % 50 + 1;
        aux = Inserir(&novo, Fim(&chamada), &chamada);

        if(aux){
          printf("\nAluno %s matriculado com sucesso\nId número: %d\n", strtok(novo.info, "\n"), novo.id);
        }
        else printf("Erro na inserção");

      break;

      case 2:
        system("clear");
        printf("Deseja remover o aluno de qual posição? ");
        scanf("%d", &posicao);

        aux = Remover(&chamada, posicao);
        if(aux)
          printf("\nRemoção com sucesso!\n");
        else printf("\nRemoção inválida!\n");

      break;

      case 3:
        system("clear");
        printf("Deseja o aluno de qual posição? ");
        scanf("%d", &posicao);

        aluno = Obter(&chamada, posicao);
        if(aluno != NULL)
          printf("\nAluno %s tem matricula nro: %d\n", strtok(aluno->info,"\n"), aluno->id);
        else
          printf("\nO aluno solicitado NÃO EXISTE PORRA!");

      break;

    }
  } while(opt != 0);

  return 0;
}
