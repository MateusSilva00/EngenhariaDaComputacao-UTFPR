#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct{
    char nome[50];
    int idade;
}elem;

typedef struct{
    int topo;
    elem A[MAX];
}Pilha;

void imprimePilha(Pilha cadastro)
{
    for(int i = 0; i<cadastro.topo; i++)
    {
        printf("%s - %d anos\n", cadastro.A[i].nome, cadastro.A[i].idade);
    }
}
void Define(Pilha *c)
{
    c->topo = 0;
}
int Fim(Pilha *c)
{
	return (c->topo);
}
int Pilha_vazia(Pilha *c){
	return (c->topo == 0);
}
int Pilha_cheia(Pilha *c){
	return (c->topo == MAX);
}
int Empilha(elem* x, Pilha *c){

	if (Pilha_cheia(c))
    {
        return 0;
    }
	else
    {
		c->A[c->topo] =  *x;
		c->topo++;
		return 1;
	}
}
int Desempilha(Pilha *c)
{
	if(Pilha_vazia(c))
        return 0;
	else
	{
		c->topo--;
        return 1;
	}
}
elem* Obter(Pilha *c, int p){
	if (p >= Fim(c) || p < 0 || Pilha_vazia(c))
		return NULL;
	else
        return &(c->A[p]);
}

int main()
{
    Pilha cadastro;
    int i, aux;

    Define(&cadastro);

    for (i=0; i<MAX; i++)
    {
        elem novo;
        printf("Digite o nome: ");
        fflush(stdin);
        scanf("%s", &novo.nome);
        printf("Digite a idade: ");
        scanf("%d", &novo.idade);

        aux = Empilha(&novo, &cadastro);
        if (!aux)
        {
            printf("Erro insercao");
        }
        else
        {
           printf("Idade = %d\n", novo.idade);
        }
    }

    printf("\n\n");

    elem *pessoa = Obter(&cadastro, 4);
    printf("%s tem %d anos.\n", pessoa->nome, pessoa->idade);

    printf("\nRemovendo pessoa no topo.\n");
    aux = Desempilha(&cadastro);
    imprimePilha(cadastro);
    if (aux) {
            printf("Remocao com sucesso.\n");
    } else {
            printf("Remocao invalida!\n");
    }

    pessoa = Obter(&cadastro, 3);
    if (pessoa!=NULL) {
        printf("\n%s tem %d anos\n", pessoa->nome, pessoa->idade);
    } else {
        printf("\nA pessoa nao existe!\n");
    }
}


