#include <stdio.h>
#include <ctype.h>

int main(){

  int i,j, fatorial;
  char ch;

  do {
    for(i=1; i<=12; i++){
      printf("%d! => ", i);
      for(fatorial=1 ,j=i; j>1; j--){
        if(j != 1){
          printf("%d * ",j);
        }
        else{
          printf("%d ",j);
        }
        fatorial = fatorial * j;
      }
      printf("= %d\n", fatorial);
    }
    printf("\nDeseja continuar o programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);

  } while(ch == 'S');



  return 0;
}
