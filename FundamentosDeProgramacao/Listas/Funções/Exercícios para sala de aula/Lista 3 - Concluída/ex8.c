#include <stdio.h>
#include <locale.h>
#include <ctype.h>

void criaDiamente(int x);

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num;
  char ch;
  do {
    do {
      printf("Insira um número impar.: ");
      scanf("%d", &num);
      if(num % 2 == 0){
        printf("Por favor informe um número impar!\n");
      }
      else{
        criaDiamente(num);
        printf("Deseja repetir o programa (S ou N).: ");
        scanf(" %c", &ch);
        ch = toupper(ch);
      }
    } while(ch == 'S');
  } while(num % 2 == 0);

  return 0;
}

void criaDiamente(int x){
  int i, j, fator=1, espacos;
  espacos = (1 + ((x-1)*2))/2; //O espaço é dado pela metade de uma progressão aritmética
  printf("\n");
  for(i=0; i<x; i++){
    //Parte decima do diamente
    if(i < x/2+1){
      for(j=0; j < espacos; j++){
        printf(" ");
      }
      for(j=0; j<fator; j++){
        printf(" *");
      }
      fator+=2;
      espacos-=2;
      printf("\n");
      if(i == x/2){
        fator-=2;
        espacos+=2;
      }
    }
    // Parte debaixo do diamente
    else {
      fator-=2;
      espacos+=2;
      for(j=0; j < espacos; j++){
        printf(" ");
      }

      for(j=0; j < fator; j++){
        printf(" *");
      }
      printf("\n");
    }
  }
}
