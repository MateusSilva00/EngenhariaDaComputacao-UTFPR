#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

void mostraVetor(float array[], int elementos){
  int i;
  for(i=0; i < elementos; i++){
    printf("%.1f  ", array[i]);
  }
  printf("\n");
}

void troca(float *xp, float *yp){
  float temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void bubbleSort(float array[], int elementos){
  for(int i = 0; i < elementos - 1; i++){
    for(int j = 0; j < elementos-1-i; j++){
      if(array[j] > array[j+1]){
        troca(&array[j], &array[j+1]);
      }
    }
  }
}

int main(){

  int qt_elementos, i, qt_vezes = 1;
  float aux;
  char ch;

  do {

    do {
      printf("Informe a quantidade de elementos do vetor.: ");
      scanf("%d", &qt_elementos);
      if(qt_elementos <= 0){
        printf("Informe um valor maior que zero.: ");
      }

      else{

        float vetor[qt_elementos];

        for(i = 0; i < qt_elementos; i++){
          printf("Valor do elemento %d do vetor.: ", i+1);
          scanf("%f", &vetor[i]);
        }

        printf("\n\n=== VETOR ===\n");
        mostraVetor(vetor, qt_elementos);

        bubbleSort(vetor, qt_elementos);
        printf("\n\n=== VETOR ORDENADO ===\n");
        mostraVetor(vetor, qt_elementos);

        for(i=0; i < qt_elementos; i++){
          if(vetor[i] == vetor[i+1]){
            qt_vezes++;
          }
          else{
            if(qt_vezes > 1){
              printf("%.1f ocorre %d vezes.\n", vetor[i], qt_vezes);
            }
            else{
              printf("%.1f ocorre %d vez.\n", vetor[i], qt_vezes);
            }
            qt_vezes = 1;
          }
        }

      }

    } while(qt_elementos <= 0);

    printf("\n\nDeseja repetir o programa (S/N) ? ");
    __fpurge(stdin);
    scanf("%c", &ch);

  } while(toupper(ch) == 'S');


  return 0;
}
