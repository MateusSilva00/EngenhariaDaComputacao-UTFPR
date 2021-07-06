#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int i, numjogos, resultado, alice=0,beto=0;
  char ch;
  do {
    printf("Informe o número de jogos.: ");
    scanf("%d", &numjogos);
    for(i=1; i<=numjogos; i++){
      do {
        printf("Informe o resultado do jogo %d.: ", i);
        scanf("%d", &resultado);
        if(resultado != 0 && resultado != 1){
          printf("Resultado Inválido!\n");
        }
      } while(resultado != 0 && resultado != 1);
      if(resultado == 0){
        alice++;
      }
      else beto++;
    }
    printf("Alice ganhou %d jogo(s) e Beto ganhou %d jogo(s)", alice, beto);
    printf("\nDeseja continuar o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S'){
      alice=0; beto=0; printf("\n");
    }
  } while(ch == 'S');


  return 0;
}
