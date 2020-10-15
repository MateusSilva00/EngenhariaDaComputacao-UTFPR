#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){

  setlocale(LC_ALL,"Portuguese");
  int num, aux=1, auxdois;
  char ch;
  do {
    do {
      printf("Informe um valor entre 2 a 12.: ");
      scanf("%d", &num);
      if (num<2 || num > 12){
        printf("Número precisa estar entre 2 e 12!\n");
      }
      else{
        auxdois = num - 1;
        do {
          printf("%d + %d = %d\n", aux, auxdois, aux + auxdois);
          aux++; auxdois--;

        } while(aux != num);
        printf("\nDeseja continuar o programa <S ou N> ?");
        scanf(" %c", &ch);
        ch = toupper(ch);
        if (ch == 'S'){
          aux = 1;
        }
      }
    } while(num<2 || num >12);
  } while(ch == 'S');


  return 0;
}
