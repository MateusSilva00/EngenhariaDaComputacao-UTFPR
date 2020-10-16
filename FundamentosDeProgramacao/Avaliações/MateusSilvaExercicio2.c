#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int i, num, countdivs=0;
  printf("=== QUESTÃO A ===");

  do {
    printf("\nInforme um número.: ");
    scanf("%d", &num);

    if(num <= 0){
      break;
    }

    else{
      for(i=1; i<=num; i++){
        if(num % i == 0){
           countdivs++;
        }
      }
      printf("%d possui %d divisores", num, countdivs);
    }
  } while(num > 0);

  printf("\n\n=== QUESTÃO B ===\n");
  int limInf, limSup, countprimo=0;
  do {
    printf("Informe o limite inferior de um intervalo.: ");
    scanf("%d", &limInf);
    printf("Informe o limite superior de um intervalo.: ");
    scanf("%d", &limSup);

    if(limInf <= 0 || limSup <= 0 || limInf == limSup){
      if(limInf == limSup){
        printf("Os valores do limite inferior e superior devem ser diferentes!\n");
      }
      else{
        printf("Os valores devem ser maiores do que zero\n");
      }
    }

    else{
      for(limInf; limInf<=limSup; limInf++){
        for(i=1; i<=limInf; i++){
          if(limInf % i == 0){
            countprimo++;
          }
        }
        if(countprimo == 2){
          printf("%d  ", limInf);
        }
        countprimo=0;
      }
    }
  } while(limInf <= 0 || limSup <= 0 || limInf == limSup);

  printf("\n\n=== QUESTÃO C ===\n");
  int numperfeito=0;
  do {
    printf("\nInforme um número.: ");
    scanf("%d", &num);

    if(num <= 0){
      printf("Informe um número positivo");
    }

    else{
      for(i=1; i<=num; i++){
        if(num % i == 0 && i != num){
           numperfeito = numperfeito + i;
        }
      }
      if(numperfeito == num){
        printf("A soma dos divisores é %d, portanto %d é perfeito", numperfeito, num);
      }
      else{
        printf("A soma dos divisores é %d, portanto %d não é perfeito", numperfeito, num);
      }
    }
  } while(num <= 0);

  printf("\n\n=== QUESTÃO D ===\n");
  int countperfeitos = 0, count = 2;
  numperfeito=0;
  do {
    printf("\nInforme a quantidade de número perfeito que deseja imprimir.: ");
    scanf("%d", &num);

    if(num <= 0 || num > 3){
      if(num > 3){
        printf("Informe um número menor que 4\n");
      }
      else{
        printf("Insira um número positivo!\n");
      }
    }

    else{
      do {
        for(int j = 1; j<=count; j++){
          if (count % j == 0 && j != count){
             numperfeito = numperfeito + j;
          }
        }
        if(numperfeito == count){
          countperfeitos++;
          printf("%d ", count);
        }
        count++; numperfeito=0;

      } while(countperfeitos < num);

    }
  } while(num <= 0 || num > 3);


  printf("\n\n=== QUESTÃO E ===\n");
  int somadiv=0;
  for(int i=10; i<=100; i++){
    for(int j=1; j<=i; j++){
      if(i % j == 0 && i != j){
        somadiv = somadiv + j;
      }
    }
    if(somadiv > 1 && somadiv < i){
      printf("%1.d  \t", i);
    }
    somadiv = 0;
  }

  printf("\n\n=== QUESTÃO F ===\n");
  do {
    printf("Informe o limite inferior de um intervalo.: ");
    scanf("%d", &limInf);
    printf("Informe o limite superior de um intervalo.: ");
    scanf("%d", &limSup);

    if(limInf <= 0 || limSup <= 0 || limInf == limSup || limSup > limInf + 10){
      if(limInf == limSup){
        printf("Os valores do limite inferior e superior devem ser diferentes!\n");
      }
      else if(limInf <= 0 || limSup <= 0){
        printf("Os valores devem ser maiores do que zero\n");
      }
      else{
        printf("O valor do limite superior não pode ter uma diferença maior que 10 em relação ao limite inferior\n");
      }
    }

    else{
      for(limInf; limInf<= limSup; limInf++){
        if(limSup % limInf == 0){
          printf("%d é multiplo de %d\n", limInf, limSup);
        }
      }
    }

  } while(limInf <= 0 || limSup <= 0 || limInf == limSup || limSup > limInf + 10);

  return 0;
}
