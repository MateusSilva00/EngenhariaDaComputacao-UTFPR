// Use a função criada no exercício anterior para mostrar todos os números felizes existentes no intervalo de
// 1 até 500.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int numeroFeliz(int x){
  int aux, inicial = x, cont =0;
  do {
    aux = 0;
    do {
      aux = aux + (x%10)*(x%10); //Variavel aux vai o resto do número ao quadrado
      x = x/10;
    } while(x > 0); //Divido o número por 10 para separar suas casas decimais
    x = aux; //Agora x vai ter o valor de aux para retornar ao loop
    cont++;
    if((x == inicial && x != 1) || cont > 20){ //Se voltou para seu valor inicial, o número não é feliz.
      //Ou se o número já passou mais de 20x pelo loop, provavelmente nao é feliz
      return 0;
      break;
    }
    if(aux == 1){
      return 1;
    }
  } while(aux != 1);
}


int main(){
  setlocale(LC_ALL,"Portuguese");

  int i;
  char ch;
  do {
    for(i=1; i<=500; i++){
      if(numeroFeliz(i) == 1){
        printf("%d  ", i);
      }
    }

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
