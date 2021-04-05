// Exercício: implementar as buscas tanto iterativas quanto recursivas. Faça experiências tanto com inteiros quanto com
// outros tipos (char, float, double).
// - Exercício:
// a) crie o tipo "aluno" (utilizando-se de struct) capaz de armazenar número de matrícula, idade e nome;
// b) crie um vetor com 5 elementos do tipo "aluno";
// c) insira valores no vetor criado acima, de forma que os alunos estejam ordenados por ordem de matrícula;
// d) qual o tipo de busca ideal para encontrar um aluno pelo número de matrícula? implemente.
// e) qual o tipo de busca ideal para encontrar um aluno pela idade? implemente.
// f) refaça as implementações de busca acima retornando um ponteiro para o tipo "aluno", e não mais o índice do vetor.
#include <stdio_ext.h>
#include <stdlib.h>

typedef struct{
  char nome[50];
  int idade;
  int matricula;
}Aluno;
Aluno alunos[50];

void cadastrar(Aluno *x, int *num_matricula){

  int opt;

  do {
    system("clear");
    __fpurge(stdin);
    printf("\nNome do aluno: ");
    fgets(x->nome, sizeof(x->nome), stdin);
    printf("Idade do aluno: ");
    scanf("%d", &x->idade);
    x->matricula = *num_matricula;
    *num_matricula = *num_matricula + 1;
    printf("\n1 - Para continuar\n0 - Para sair\n:  ");
    scanf("%d", &opt);
  } while(opt != 0);
}



void menu(){
  system("clear");
  int opt, matricula = 1, idade, p_matricula;
  do {
    printf("\n1 - Cadastrar Aluno\n2 - Pesquisar Aluno - idade\n3 - Pesquisar Aluno - matricula\n0 - Sair\n");
    scanf("%d", &opt);
    __fpurge(stdin);
    switch (opt){
      case 1:
        cadastrar(alunos, &matricula);
      break;

      case 2:
        printf("Procurar aluno de qual idade: ");
        scanf("%d", &idade);
      break;

      case 3:
        printf("Número de matricula do aluno: ");
        scanf("%d", &p_matricula);

      break;
    }
  } while(opt != 0);
}

int main(){

  menu();

  return 0;
}
