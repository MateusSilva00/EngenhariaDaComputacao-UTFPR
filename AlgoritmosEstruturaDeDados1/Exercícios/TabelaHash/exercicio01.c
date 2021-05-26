#include <stdio_ext.h>
#include <stdlib.h>

#define M 19

typedef struct {
  int matricula;
  char nome[50];
} Pessoa;

typedef struct no {
  Pessoa pessoa;
  struct no* prox;
} No;

typedef struct {
  No* inicio;
  int tam;
} Lista;

Lista *tabela[M];

Pessoa criarPessoa() {
  Pessoa p;
  printf("Digite o nome da pessoa: ");
  __fpurge(stdin);
  fgets(p.nome, sizeof(p.nome), stdin);
  printf("Digite a matricula: ");
  scanf("%d", &p.matricula);
  return p;
}

void imprimirPessoa(Pessoa p){
  printf("\tNome: %s\tMatricula: %d\n", p.nome, p.matricula);
}

Lista* criarLista(){
  Lista *L;
  L = (Lista*) malloc(sizeof(Lista));
  L->inicio = NULL;
  L->tam = 0;
  return L;
}

void inserirInicio(Pessoa p, Lista *L){
  No *no = (No*)malloc(sizeof(No));
  no->pessoa = p;
  no->prox = L->inicio;
  L->inicio = no;
  L->tam++;
}

No* buscarNo(int mat, No* inicio) {
  while (inicio != NULL) {
    if(inicio->pessoa.matricula == mat)
      return inicio;
    else inicio = inicio->prox;
  }
  return NULL;
}

void imprimirLista(No *inicio) {
  while (inicio != NULL) {
    imprimirPessoa(inicio->pessoa);
    inicio = inicio->prox;
  }
}

// FUNÇÕES TABELA HASH

//Inicializar tabela
void inicializar(){
  int i;
  for(i=0; i < M; i++){
    tabela[i] = criarLista();
  }
}

//Função de espalhamento
int funcaoEspalhamento(int mat){
  return mat % M;
}

//Cria uma pessoa e a insere na tabela
void inserirTabela(){
  Pessoa pes = criarPessoa();
  int indice = funcaoEspalhamento(pes.matricula);
  inserirInicio(pes, tabela[indice]);
}

//Buscar uma pessoa
Pessoa* buscarPessoaTabela(int mat){
  int indice = funcaoEspalhamento(mat);
  No *no = buscarNo(mat, tabela[indice]->inicio);
  if(no) return &no->pessoa;
  else NULL;
}

//Imprimir TABELA
void imprimirTabela(){
  int i;
  printf("\n============================ TABELA ============================\n");
  for(i=0; i < M; i++){
    printf("%d Lista tamanho: %d\n", i, tabela[i]->tam);
    imprimirLista(tabela[i]->inicio);
  }
  printf("\n================================================================\n");
}

int main(){
  int opt, mat;
  Pessoa *p;

  inicializar();

  do {
    printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir tabela\n");
    scanf("%d", &opt);
    switch (opt) {
      case 0:
        printf("Saindo...\n");
        break;
      case 1:
        inserirTabela();
        break;
      case 2:
        printf("Qual matrícula deseja buscar? ");
        scanf("%d", &mat);
        p = buscarPessoaTabela(mat);
        if(p){
          printf("Pessoa encontrada: Matricula: %d\tNome: %s", p->matricula, p->nome);
        }
        else printf("Pessoa não encontrada!\n");
      case 3:
        imprimirTabela();
        break;
      default:
        printf("Opção inválida!\n");
    }
  } while(opt != 0);


  return 0;
}
