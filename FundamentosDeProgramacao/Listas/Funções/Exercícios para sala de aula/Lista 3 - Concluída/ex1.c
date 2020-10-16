#include <stdio.h>
#include <ctype.h>
#include <locale.h>

void mostraMultiplos(int numero, int valorMultiplo){
  int i, soma=0;
  printf("%d = ", numero);
  for(i=1; i<=numero; i++){
    if(i % valorMultiplo == 0){
      printf("%d ", i);
      soma = soma + i;
    }
  }
  printf(" => Soma: %d", soma);
}

void multiplosIntervalo (int i, int j, int valorMultiplo){
  int soma, x;
  for(i; i<=j; i++){
    soma = 0;
    printf("%d = ", i);
    for(x = valorMultiplo; x<=i; x = x + valorMultiplo){
      printf("%d ", x);
      soma = soma + x;
    }
    printf(" => Soma: %d\n", soma);
  }
}

int main(){
  setlocale(LC_ALL,"Portuguese");
  int opcao, num, multiplos, limInf, limSup;
  char ch;
  do {
    printf("1 - Mostra e soma os multiplos de um número\n2 - Mostra e soma os multiplos dos números de um intervalo\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe um número.: ");
        scanf("%d", &num);
        printf("Mostrar os multiplos de.: ");
        scanf("%d", &multiplos);
        mostraMultiplos(num, multiplos);
        break;

      case 2:
        do {
          printf("Informe o valor do limite inferior de um intervalo.: ");
          scanf("%d", &limInf);
          if(limInf <= 0){
            printf("Valor do limite inferior deve ser positivo!\n");
          }
          else{
            do {
              printf("Informe o valor do limite superior de um intervalo.: ");
              scanf("%d", &limSup);
              if(limSup <= limInf){
                printf("Valor do limite superior deve ser maior que o limite inferior!\n");
              }
              else{
                do {
                  printf("Para cada número do intervalo, mostrar os múltiplos de.: ");
                  scanf("%d", &multiplos);
                  if(multiplos < 1){
                    printf("Valor dos múltiplos deve ser maior que 0!\n");
                  }
                  else{
                    multiplosIntervalo(limInf,limSup,multiplos);
                  }
                } while(multiplos < 1);
              }
            } while(limSup <= limInf);
          }
        } while(limInf <= 0);
        break;

      default:
        printf("Valor Inválido!\n");
    }

    printf("\n\nDeseja repetir o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
