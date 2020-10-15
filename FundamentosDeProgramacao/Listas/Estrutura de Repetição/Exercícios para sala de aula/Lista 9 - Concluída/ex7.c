#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");

  int i=1,num, count=0, raiz;
  do {
    printf("Informe o valor de n.: ");
    scanf("%d", &num);
    if(num <= 0){
      printf("Informe um valor positivo!\n");
    }
    else{
      for(i; i<=num; i++){
        raiz = sqrt(i*i);
        printf("%d => raiz de %d\n", i*i, raiz);
      }
    }

  } while(num <= 0);

  return 0;
}
