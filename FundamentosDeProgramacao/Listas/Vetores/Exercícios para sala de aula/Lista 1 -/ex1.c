#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int i, qtvetor=0, num[9], pares=0, div_3_5=0, menorOUmaior=0, menorEmaior=0, impar=0;
  float porcentagem;
  char ch;

  do {
    for(i=0; i<=9; i++){
      printf("Informe o elemento que esta na posição %d.: ", i+1);
      scanf("%d", &num[i]);
      qtvetor++;
      if(i == 9){
        // Exibindo os números pares após receber os valores do vetor
        printf("\n=== PARES ===\n");
        for(i=0; i<=9; i++){
          if(num[i] % 2 == 0){
            printf("%d ", num[i]);
            pares++;
          }
        }
        printf("\nExistem %d numeros pares no vetor\n", pares);

        // Exibindo diviseis por 3 e por 5
        printf("\n=== DIVISIVEIS POR 3 E POR 5 ===\n");
        for(i=0; i<=9; i++){
          if(num[i] % 3 == 0 && num[i] % 5 == 0){
            printf("%d ", num[i]);
            div_3_5++;
          }
        }
        printf("\nExistem %d números divisiveis por 3 e por 5 no vetor\n", div_3_5);

        // Exibindo números menores que 10 ou maiores que 100
        printf("\n=== MENORES QUE 10 OU MAIORES QUE 100 ===\n");
        for(i=0; i<=9; i++){
          if(num[i] < 10 || num[i] > 100 ){
            printf("%d ", num[i]);
            menorOUmaior++;
          }
        }
        printf("\nExistem %d números menores que 10 ou maiores que 100\n", menorOUmaior);

        // Exibindo números menores que 10 e maiores que 100
        printf("\n=== MAIORES QUE 10 E MENORES QUE 100 ===\n");
        for(i=0; i<=9; i++){
          if(num[i] > 10 && num[i] < 100 ){
            printf("%d ", num[i]);
            menorEmaior++;
          }
        }
        printf("\nExistem %d números maiores que 10 e menores que 100\n", menorEmaior);

        // Exibindo os impares
        printf("\n=== IMPARES ===\n");
        for(i=0; i<=9; i++){
          if(num[i] % 2 != 0){
            printf("%d ", num[i]);
            impar++;
          }
        }
        porcentagem = ((float)impar/(float)qtvetor) * 100;
        printf("\nExistem %d números impares representando %.2f%% dos elementos do vetor\n", impar, porcentagem);

      }
    }

    printf("Deseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      printf("\n"); qtvetor=0; pares=0; div_3_5=0; menorOUmaior=0; menorEmaior=0; impar=0;
    }

  } while(ch == 'S');

  return 0;
}
