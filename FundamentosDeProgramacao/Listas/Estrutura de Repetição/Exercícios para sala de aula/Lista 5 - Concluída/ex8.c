#include <stdio.h>

int main(){

  int num, i, soma=0;
  printf("Insira um numero.: ");
  scanf("%d", &num);
  printf("\tDivisores\n");
  for (i=1; i<=num; i++){
    if(num % i == 0 && i != num){
      printf("\t   |%d|\n",i);
      soma = soma + i;
    }
  }
  printf("\t   ---\n\t   |%d|\n", soma);

  if (soma > num){
    printf("%d Eh um numero abundante porque a soma dos divisores eh maior que %d.", num, num);
  }
  else printf("%d Nao eh um numero abundante porque a soma dos divisores eh menor que %d.", num, num);



  return 0;
}
