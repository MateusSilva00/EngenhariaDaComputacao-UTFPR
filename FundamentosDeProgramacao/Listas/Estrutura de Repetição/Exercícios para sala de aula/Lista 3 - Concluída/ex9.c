// Ler dois valores que representam os limites de um intervalo. O usuário pode informar
// os valores em ordem crescente ou decrescente. Para os limites do intervalo validar para
// que:
// 1) O programa não aceite valores iguais, ou seja, que o limite inferior seja igual ao
// superior e vice-versa;
// 2) Em cada limite não seja informado valor menor ou igual a zero.
// Apresentar os valores separados por tabulação. Fazer a média dos valores que são
// divisíveis por 11 e por 7, desse intervalo.
#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int i, limInf, limSup, count7 = 0, count11 = 0;
  float div7 = 0, div11=0;

  do {
    printf ("Informe um valor para o limite inferior de um intervalo.: ");
    scanf("%d", &limInf);
    printf ("Informe um valor para o limite superior de um intervalo.: ");
    scanf("%d", &limSup);

    if (limInf == limSup || limInf <= 0 || limSup <= 0){
      printf("Valor dos inválidos. Informe valores diferentes!\n");
    }

    else if (limInf < limSup){
      for (limInf; limInf <= limSup; limInf++) {
          printf("\n%d ", limInf);
          if (limInf % 11 == 0 || limInf % 7 == 0){
            if (limInf % 7 == 0 && limInf % 11 == 0){
              printf("\t Divisivel por e 11 e 7");
              div7 = div7 + limInf;
              div11 = div11 + limInf;
              count7++; count11++;
            }
            else if(limInf % 11 ==0){
              printf("\t Divisivel por 11");
              div11 = div11 + limInf;
              count11++;
            }
            else{
              printf("\t Divisivel por 7");
              div7 = div7 + limInf;
              count7++;
            }
          }
      }
    }

    else if (limInf > limSup){
      for (limInf; limInf >= limSup; limInf--){
          printf("\n%d ", limInf);
          if (limInf % 11 == 0 || limInf % 7 == 0){
            if (limInf % 7 == 0 && limInf % 11 == 0){
              printf("\t Divisivel por e 11 e 7");
              div7 = div7 + limInf;
              div11 = div11 + limInf;
              count7++; count11++;
            }
            else if(limInf % 11 ==0){
              printf("\t Divisivel por 11");
              count7++;
            }
            else{
             printf("\t Divisivel por 7");
             count11++;
           }
         }
      }
    }

  div7 = div7 / count7;
  div11 = div11 / count11;
  printf("\nMedia dos divisíveis por 7.: %.2f\nMedia dos divisíveis por 11.: %.2f", div7, div11);

  } while(limInf == limSup || limInf <= 0 || limSup <= 0);

  return 0;
}
