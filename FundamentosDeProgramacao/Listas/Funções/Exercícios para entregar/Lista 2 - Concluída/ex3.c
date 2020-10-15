#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>

int raizQuadrada(int x){
  int raiz, i, aux=0, soma=0;
  raiz = sqrt(x);
  for(i=1; i<=x; i+=2){
    //Um quadrado perfeito também pode ser reconhecido através da soma dos números impares
    soma = soma + i;
    if(soma == x){
      aux++;
    }
  }

  if(aux == 1){
      printf("%d é um quadrado perfeito ==> raiz quadradada de %d é %d\n",x,x,raiz);
  }
  return aux;
}


int main(){
  setlocale(LC_ALL,"Portuguese");

  int opcao, limInf, limSup, num, i;
  char ch;
  do {
    printf("1 - Verifica se um numero é um quadrado perfeito\n2 - Mostra os número quadrados perfeitos que pertecem a um intervalo\nOpção.: ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        printf("Informe um número.: ");
        scanf("%d", &num);
        if(raizQuadrada(num) == 0){
          printf("%d Não é um quadado perfeito\n", num);
        }
        break;

      case 2:
        do {
          printf("Informe um limite inferior.: ");
          scanf("%d", &limInf);
          if(limInf <= 0){
            printf("Limite inferior deve ser maior que 0!\n");
          }
          else{
            do {
              printf("Informe um limite superior.: ");
              scanf("%d", &limSup);
              if (limSup <= limInf){
                printf("Limite superior deve ser maior que o inferior!\n");
              }
              else{
                for(i = limInf; i<=limSup; i++){
                  raizQuadrada(i);
                }
              }
            } while(limSup <= limInf);
          }
        } while(limInf <= 0);
        break;

      default:
      printf("Opção Inválida!\n");
    }

    printf("\nDeseja continuar o programa (S ou N).:");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
        printf("\n");
    }

  } while(ch == 'S');


  return 0;
}
