#include <stdio_ext.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100 		/* Max. Tamanho da Lista */

typedef struct {
		int id;
		char info[50];
} elem;	/* Tipo do Elemento */

typedef struct{
		int nelem;
		elem A[MAX];
} Lista; /* Tipo Lista */


void Definir(Lista *L){
	/* Define uma lista vazia */
	L->nelem=0;
}

int Fim(Lista *L){
	/* Retorna a posicao apos o ultimo elemento da lista */
	return (L->nelem);
}

int Lista_vazia(Lista *L){
	/* Retorna true se lista vazia, false caso contr�rio */
	return (L->nelem == 0);
}

int Lista_cheia(Lista *L){
	/* Retorna true se lista cheia, false caso contr�rio */
	return (L->nelem == MAX);
}

int Inserir(elem* x, int p, Lista *L){
/* Insere elemento x na posicao p da Lista L.
Devolve true se sucesso, false se L cheia ou nao tem posicao p. L nao ordenada! */
	int atual;
	if (Lista_cheia(L))
		return 0;  /* lista cheia */
	else if (p > Fim(L) || p < 0)
		return 0; /* posicao nao existe */
	else {
		for(atual = L->nelem-1; atual >= p; atual--)
			L->A[atual+1] = L->A[atual];
		L->A[p]=  *x;
		L->nelem++;
		return 1; /* insercao com sucesso */
	}
}

int Remover(int p, Lista *L){
/* Remove o elemento da posicao p da Lista.
Devolve true se sucesso, false caso contrario (L nao tem posicao p, inclusive se p = Fim(L))  */
	int atual;
	if(p >= Fim(L) || p < 1 || Lista_vazia(L))
        return 0;
	else {
		for (atual = p+1; atual <= L->nelem; atual++)
			L->A[atual-1] = L->A[atual];
		L->nelem--;
	}
    return 1;
}

elem* Obter(Lista *L, int p){
/* Retorna elemento da posicao p, ou elem. invalido se p eh invalida */
	if (p >= Fim(L) || p < 1 || Lista_vazia(L))
		return NULL;    /* retorna elemento invalido */
	else
        return &(L->A[p]);
}

void menu(Lista *chamada){
  elem novo;
  int opt=1, aux, remov;

  do{
    printf("\n1 - Adicionar Aluno\n2 - Remover\n3 - Obter\n0 - Sair\nOpção.:");
    scanf("%d", &opt);

    switch (opt) {
      case 1:
        novo.id = rand()%20 + 1;
        __fpurge(stdin);
         printf("\nDigite o nome de um aluno: ");
         fgets(novo.info, sizeof(&novo.info),stdin);
        aux = Inserir(&novo, Fim(chamada), chamada);
        if (!aux) printf("Erro insercao");
        else printf("Matricula nro = %d\n", novo.id);
      break;

      case 2:
        printf("Deseja remover o aluno em qual posição?: ");
        scanf("%d", &remov);
        aux = Remover(remov, chamada);
        if (aux) printf("Remocao com sucesso.\n");
        else printf("Remocao invalida!\n");
      break;

      case 3:
        // Obter();
      break;
    }
  }
  while(opt != 0);
}


int main(void){

    srand(time(0));

    Lista chamada;			/* Exemplo de Declaracao*/
    Definir(&chamada);

    int i;
    int aux;
    srand(time(NULL));

    //adicionar 5 novos alunos a chamada
    for (i=0; i<5; i++) {
        elem novo;
        novo.id = rand()%20 + 1;

        __fpurge(stdin);
        printf("Digite o nome de um aluno: ");
        fgets(novo.info, sizeof(&novo.info),stdin);

        aux = Inserir(&novo, Fim(&chamada), &chamada);
        if (!aux)
            printf("Erro insercao");
        else
            printf("Matricula nro = %d\n", novo.id);
    }
    printf("\n\n");

    system("clear");
    menu(&chamada);


}
