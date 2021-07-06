#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int count;
  do {
    printf("\nQuantos números impares quer mostrar?");
    scanf("%d", &count);
    if (count == 0){
      printf("Insira um número maior que 0\n");
    }
    else {
      int num = 1, aux = 0;
        do {
          printf("%d\n", num);
          num = num + 2;
          aux++;
        } while(aux < count);
      }
  } while(count >= 0);


  return 0;
}
