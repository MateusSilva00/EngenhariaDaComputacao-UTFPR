//1) Escreva uma função que divide uma fila em 2 novas filas: uma só com elementos pares e outra só com elementos
// ímpares.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

typedef struct
{
	int id;
}elem;

typedef struct
{
	int nelem;
	int inicio;
	int fim;
	elem A[MAX];
}fila;

void definir(fila *f)
{
	f->nelem=0;
	f->inicio=0;
	f->fim=0;
}

int filaCheia(fila *f)
{
	if(f->nelem==MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int filaVazia(fila *f)
{
	if(f->nelem==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int enfila (elem *x, fila *f)
{
	if(filaCheia(f))
	{
		return 0;
	}
	else
	{
		f->A[f->fim] = *x;
		f->nelem++;
		f->fim++;
		return 1;
	}
}

int desenfila (fila *f)
{
	if(filaVazia(f))
	{
		return 0;
	}
	else
	{
		f->inicio++;
        f->nelem--;
        return 1;
	}
}

void imprime (fila *f)
{
	int i = f->inicio;
    if (!filaVazia(f))
	{
        do
		{
            printf("%d  ", f->A[i]);
            i++;
        } while (i != f-> fim);
    }
    printf("\n");
}

void separa(fila *f, fila *par, fila *impar)
{
	int i,j=0,k=0;
	for(i=0;i < f->nelem;i++)
	{
	    elem copia;
	    copia.id = f->A[i].id;
		if(copia.id % 2==0)
		{
			enfila(&copia, par);
		}
		else
		{
			enfila(&copia, impar);
		}
	}

	printf("\n\nPares no vetor: ");
	imprime(par);

	printf("\n\nImpares no vetor: ");
	imprime(impar);
}

int main (void)
{
	fila f;
	fila par;
	fila impar;

	definir(&f);
	definir(&par);
	definir(&impar);

	int i, aux;

	elem novo;

  srand(time(0));

	for(i=0;i<MAX;i++)
	{
		novo.id  =rand() % 50 +1;
		aux=enfila(&novo,&f);
		if(aux)
		{
			printf("\t enfilado com sucesso\n");
		}
		else
		{
			printf("\t enfila nao funcionou :c \n");
		}

	}
	printf("\n");
	imprime(&f);
	separa(&f,&par,&impar);
}
