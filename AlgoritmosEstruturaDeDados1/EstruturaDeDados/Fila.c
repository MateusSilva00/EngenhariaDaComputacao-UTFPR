#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 		/* Max. Tamanho da Lista */

typedef struct {
		int id;
		char info[50];
} elem;	/* Tipo do Elemento */

typedef struct{
		int nelem;
		elem A[MAX];
}Fila;


void Definir(Fila *F){
	/* Define uma lista vazia */
	F->nelem= 0;
}

int Fim(Fila *F){
	/* Retorna a posicao apos o ultimo elemento da lista */
	return (F->nelem);
}

int Fila_vazia(Fila *F){

	return (F->nelem == 0);
}

int Fila_cheia(Fila *F){

	return (F->nelem == MAX);
}

int Enfila(elem* x, Fila *F){
	int atual;
	if (Fila_cheia(F))
		return 0;  /* lista cheia */
	else {
		F->A[F->nelem] = *x;
		F->nelem++;
		return 1; /* insercao com sucesso */
	}
}

int Desenfila(Fila *F){
/* Remove o elemento da posicao p da Lista.
Devolve true se sucesso, false caso contrario (L nao tem posicao p, inclusive se p = Fim(L))  */
	int atual;
	if(Fila_vazia(F))
        return 0;
	else {
		for (atual = F->nelem-1; atual > 0; atual--)
			F->A[atual-1] = F->A[atual];
		F->nelem--;
	}
    return 1;
}

elem* Obter(Fila *L, int p){

	if (p >= Fim(L) || p < 1 || Fila_vazia(L))
		return NULL;
	else
        return &(L->A[p]);
}


int main(void){
    Fila chamada;			/* Exemplo de Declaracao*/
    Definir(&chamada);

    int i;
    int aux;
    srand(time(NULL));

    //adicionar 5 novos alunos a chamada
    for (i=0; i<5; i++) {
        elem novo;
        novo.id = rand()%20 + 1;

        printf("Digite o nome de um aluno: ");
        scanf("%s", &novo.info);
        getchar();

        aux = Enfila(&novo, &chamada);
        if (!aux)
            printf("Erro insercao");
        else
            printf("Matricula nro = %d\n", novo.id);
    }
    printf("\n\n");

    //elem *aluno = Obter(&chamada, 4);
    //printf("O aluno %s tem matricula nro. %d.\n", aluno->info, aluno->id);
    aux = Desenfila(&chamada);
    if (aux) {
            printf("Remocao com sucesso.\n");
    } else {
            printf("Remocao invalida!\n");
    }

    /*aluno = Obter(&chamada, 4);
    if (aluno!=NULL) {
        printf("\nO aluno %s tem matricula nro. %d.\n", aluno->info, aluno->id);
    } else {
        printf("\nO aluno solicitado nao existe!\n");
    }*/

}
