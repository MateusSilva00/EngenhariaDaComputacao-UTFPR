#include <stdio.h>
#include <locale.h>
#include <ctype.h>

float polegadas(int num){
  return num * 0.393701;
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    int cm;
    char ch;
    do {
      printf("Informe uma medida em centimetros.: ");
      scanf("%d", &cm);
      printf("O equivalente em polegas é %.2f", polegadas(cm));
      printf("\n=== TABELA DE CONVERSÃO == \nCENTIMETROS\tPOLEGADAS");
      for(int i = 1; i<=20; i++){
        printf("\n%d\t\t%2.2f", i, polegadas(i));
      }
      printf("\n\nDeseja continuar o programa (S ou N) ? ");
      scanf(" %c", &ch);
      ch = toupper(ch);
      if(ch == 'S'){
        printf("\n");
      }
    } while(ch == 'S');

    return 0;
}
