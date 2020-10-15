#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num, maior, menor, count=0, countmedia = 0;
  float media = 0;
  char ch;

  do {
    do {
      printf("Informe um valor.: ");
      scanf("%d", &num);
      if(count == 0){
        maior = num;
        menor = num;
      }
      count++;

      if (num > maior && num != 0){
        maior = num;
      }
      else if(num < menor && num != 0){
        menor = num;
      }

      if(num < 0){
        media = media + num;
        countmedia++;
      }


    } while(num != 0);

    printf("\n\nO maior número é.: %d\nO menor número é.: %d", maior, menor);
    if(countmedia >= 1){
      media = media / countmedia;
      printf("\nA media dos negativos é.: %.2f", media);
    }

    printf("\n\nDeseja repetir o programa (S ou N): ");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      count=0; countmedia = 0; media = 0; printf("\n");
    }
  } while(ch == 'S');

  return 0;
}
