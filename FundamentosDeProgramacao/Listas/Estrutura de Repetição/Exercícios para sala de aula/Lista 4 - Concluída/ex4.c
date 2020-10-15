// Ler números informados pelo usuário. Parar a leitura quando informado o número zero, que não deve ser
// considerado. Fazer a média dos valores negativos informados. Dos valores positivos contar quantos são
// ímpares.
#include <stdio.h>

int main (){

  int num, countimpar=0,count=0;
  float media=0;

  do {
    printf("Insira um número.: ");
    scanf("%d", &num);
    if(num == 0){
      break;
    }
    else if (num % 2 != 0 && num > 0){
      countimpar++;
    }
    else if (num < 0){
      media = media + num;
      count++;
    }

  } while(num != 0);

  media = media / count;

  printf("A media dos numeros negativo e.: %.2f\nForam informados %d numeros positivos que sao impares", media, countimpar);

  return 0;
}
