#include <stdio.h>

#define MAX 5

typedef struct {
		char id;
} elem;	/* Tipo do Elemento */

typedef struct{
        int nelem;
		int inicio;
		int fim;
		elem A[MAX];
} FilaCirc; /* Tipo Fila Circular */

void Definir(FilaCirc *F){
    F->nelem = 0;
	F->inicio = 0;
	F->fim = 0;
}

int Fila_cheia(FilaCirc *F){
    if (F->nelem == MAX)
        return 1;
    else
        return 0;
}

int Fila_vazia(FilaCirc *F){
    if (F->nelem == 0)
        return 1;
    else
        return 0;
}

int Enfila(elem* x, FilaCirc *F){
	int atual;
	if (Fila_cheia(F))
		return 0;
	else {
		F->A[F->fim]=  *x;
		F->nelem++;
		F->fim++;
		if (F->fim == MAX) {
            F->fim = 0;
		}
		return 1; /* insercao com sucesso */
	}
}

int Desenfila(FilaCirc *F){
    if (Fila_vazia(F))
        return 0;
    else {
        F->inicio++;
        if (F->inicio == MAX) {
            F->inicio = 0;
        }
        F->nelem--;
        return 1;
    }
}

void ImprimeBom(FilaCirc *F){
    int i = F->inicio;
    if (!Fila_vazia(F)){
        do {
            printf("%c  ", F->A[i]);
            i++;
            if (i == MAX) {
                i = 0;
            }
        } while (i != F-> fim);
    }
    printf("\n");
}

void ImprimeRuim(FilaCirc *F) {
    int i;
    for (i=0; i<MAX; i++)
        printf("%c, ", F->A[i]);
    printf("\n");
}

int main() {
    FilaCirc F;
    Definir(&F);

    int i, aux;
    elem novo;
    for (i=1; i<=20; i++) {
        if (i%3 != 0){
            novo.id = 64 + i;
            aux = Enfila(&novo, &F);
            if (aux) {
                printf("enfila com sucesso");
            } else {
                printf("enfila nao funcionou");
            }
        } else {
            aux = Desenfila(&F);
            if (aux) {
                printf("desenfila com sucesso");
            } else {
                printf("desenfila nao funcionou");
            }
        }
        printf("\n");
        ImprimeBom(&F);
        printf("\n");
    }
}
