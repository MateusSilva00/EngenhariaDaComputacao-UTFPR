#include <stdio.h>
#include <ctype.h>


int main(){

  char ch;
  do {
    int i, posicao = 1, countMedia = 0;
    float alturaPessoa[5], maior, media = 0;

    for(int i = 1; i <= 5; i++){
      printf("Informe a altura da pessoa %d.: ", i);
      scanf("%f", &alturaPessoa[i]);
    }

    for(i = 1; i <= 5; i++){
      if(i == 1)maior = alturaPessoa[i];
      else if(maior < alturaPessoa[i]){
        maior = alturaPessoa[i];
        posicao = i;
      }
      if(alturaPessoa[i] > 1.50){
        media = media + alturaPessoa[i];
        countMedia++;
      }
    }

    printf("Maior altura é %.2f e está na posição %d do vetor", maior, posicao);
    if(countMedia > 1){
      media = media / countMedia;
      printf("\nMedia das alturas maiores que um metro e meio %.2f\n", media);
    }

    printf("\n\nDeseja repetir o programa (S/N).: ");
    scanf(" %c", &ch);
  } while(toupper(ch) == 'S');

  return 0;
}
