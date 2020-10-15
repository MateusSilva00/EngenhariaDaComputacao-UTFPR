#include <stdio.h>
#include <ctype.h>
#include <locale.h>

void verificaSomaImpares(int num){
  int j, soma = 0;
  printf("%d = ", num);
  for(j=1; j<=num; j+=2){
    printf("%d ", j);
    soma = soma + j;
    if(soma == num){
      printf("=> Equivale a soma dos impares!\n");
      break;
    }
    else if(soma > num || num == 2){
      printf("=> Não equivale a soma dos impares!\n");
      break;
    }
  }
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int opcao, num, limInf, limSup, i;
  char ch;
  do {
    printf("1 - Verifica se um número equivale a soma dos impares\n2 - Verifica os números que equivalem a soma dos impares de um intervalo\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe um número.: ");
        scanf("%d", &num);
        verificaSomaImpares(num);
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
                for(i=limInf; i<=limSup; i++){
                  verificaSomaImpares(i);
                }
              }
            } while(limSup <= limInf);
          }
        } while(limInf <= 0);
        break;

      default:
        printf("Valor Inválido!\n");
    }
    printf("\n\nDeseja repetir o programa (S ou N)?");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');


  return 0;
}
