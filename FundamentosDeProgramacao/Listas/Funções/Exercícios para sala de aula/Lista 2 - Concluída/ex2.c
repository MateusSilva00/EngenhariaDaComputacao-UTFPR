#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int quantidadeDivisores(int x){
  int i, qtDivisores=0;
  for(i=1; i <= x; i++){
    if(x % i == 0){
      qtDivisores++;
    }
  }
  return qtDivisores;
}

void divisores(int x){
  int i;
  for(i=1; i <= x; i++){
    if(x % i == 0){
      printf("%d ", i);
    }
  }
}

int somaDivisor(int x){
  int i, soma = 0;
  for(i=1; i <= x; i++){
    if(x % i == 0){
      soma = soma + i;
    }
  }
  return soma;
}

int maximoDivisor(int x, int y){
  int i, menor, mdc;
  if(x < y){
    menor = x;
  }
  else{
    menor = y;
  }

  for(i=menor; i>=i; i--){
    if(x % i == 0 && y % i == 0){
      mdc = i;
      break;
    }
  }
  return mdc;
}

int main(){
  setlocale(LC_ALL,"Portuguese");
  int opcao, num, firstValue, secondValue, limInf, limSup;
  char ch;
  do {
    printf("1 - Quantidade de divisores de um número\n2 - Divisores de um número\n3 - Divisores, quantidade e soma de um intervalo\n4 - Máximo Divisor Comum de dois números\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("\nInforme um número para mostrar a quantidade de divisores.: ");
        scanf("%d", &num);
        printf("%d divisores\n", quantidadeDivisores(num));
        break;

      case 2:
        printf("\nInforme um número para mostrar os seus divisores.: ");
        scanf("%d", &num);
        divisores(num);
        break;

      case 3:
        printf("Informe o limite inferior.: ");
        scanf("%d", &limInf);
        printf("Informe o limite superior.: ");
        scanf("%d", &limSup);
        for(limInf; limInf <= limSup; limInf++){
          // /printf("%d - %d =>  Qtde.: => Soma.: %d\n", limInf, divisores(limInf), somaDivisor(limInf));
          printf("%d - ", limInf);
          divisores(limInf);
          printf("=> Qtde.: %d => Soma.: %d\n", quantidadeDivisores(limInf), somaDivisor(limInf));
        }
        break;

      case 4:
        printf("Infomre o primeiro valor.: ");
        scanf("%d", &firstValue);
        printf("Informe o segundo valor.: ");
        scanf("%d", &secondValue);
        printf("MDC: %d", maximoDivisor(firstValue, secondValue));
        break;

      default:
      printf("Opção Inválida!\n");
    }

    printf("\n\nDeseja continuar no programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
