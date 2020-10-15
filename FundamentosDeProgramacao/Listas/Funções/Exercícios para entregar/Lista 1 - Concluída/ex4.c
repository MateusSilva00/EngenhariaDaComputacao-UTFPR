#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int multiplica (int x, int y){
  return x * y;
}

int main(){
  setlocale(LC_ALL,"Portuguese");

  int num1, num2;
  char ch;
  do {
    printf("Informe um número.: ");
    scanf("%d", &num1);
    printf("Informe outro número.: ");
    scanf("%d", &num2);
    printf("%d * %d = %d", num1, num2, multiplica(num1,num2));

    printf("\n\nInforme um número.: ");
    scanf("%d", &num1);
    for(int i=0; i<=10; i++){
      printf("%d * %d = %d\n", num1, i, multiplica(num1, i));
    }

    printf("\nDeseja continuar no programa (S ou N) ?");
    scanf(" %c", &ch);
    ch = toupper(ch);
    if(ch == 'S') printf("\n");

  } while(ch == 'S');


  return 0;
}
