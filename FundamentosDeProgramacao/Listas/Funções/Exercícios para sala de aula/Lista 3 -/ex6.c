// Para saber se um número é feliz, você deve obter o quadrado de cada dígito deste número, em seguida
// você faz a soma desses resultados. A seguir o mesmo procedimento deve ser feito com o valor resultante
// desta soma. Se ao repetir o procedimento diversas vezes obtivermos o valor 1, o número inicial é considerado
// feliz.
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

  int num;
  char ch;
  do {
    printf("Informe um para saber se é um número feliz.: ");
    scanf("%d", &num);
    if(numeroFeliz(num) == 1){
      printf("%d é um número feliz!\n", num);
    }
    else{
      printf("%d Não é um número feliz!\n", num);
    }

    printf("\n\nDeseja continuar o programa (S ou N).: ");
    scanf(" %c", &ch);
    ch = toupper(ch);
  } while(ch == 'S');

  return 0;
}
