#include <stdio.h>
#include <locale.h>


int main (){

  int i, contDiv=0, num;
  setlocale(LC_ALL, "Portuguese");
  printf("Informe um número.: ");
  scanf("%d", &num);

  for (i=1; i<=num; i++){
    if (num % i == 0) {
      contDiv++;
    }
  }

  if (contDiv == 2){
    printf("%d é primo!", num);
  }
  else{
    printf("%d não é primo!", num);
  }



  return 0;
}
