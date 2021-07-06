#include <stdio.h>
#include <locale.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int numConta, divfirst, divsecon, divthird, divforth, inverso, aux, x, digVerif;

  do {
    printf("Informe o número da conta corrente.: ");
    scanf("%d", &numConta);
    if (numConta <= 999 || numConta >= 10000){
      printf("Número inválido!\n");
    }
    else{
      divfirst = numConta / 1000;
      divsecon = (numConta / 100) % 10;
      divthird = (numConta / 10) % 100 % 10;
      divforth = (numConta % 1000) % 100 % 10;
      printf("Primeiro Digito = %d\nSegundo Digito = %d\nTerceiro Digito = %d\nQuarta Digito = %d\n\n", divfirst, divsecon, divthird, divforth);
      inverso = (divthird*100) + (divsecon*10) + divfirst;
      printf("\nInverso = %d",inverso);
      aux = (divfirst*100 + divsecon*10 + divthird) + inverso;
      printf("\n%d + %d = %d\n\n", numConta/10,inverso,aux);

      divfirst = (aux / 1000);
      divsecon = (aux / 100) % 10;
      divthird = (aux/ 10) % 100 % 10;
      divforth = (aux % 1000) % 100 % 10;
      printf("\nPrimeiro Digito = %d\nSegundo Digito = %d\nTerceiro Digito = %d\nQuarta Digito = %d", divfirst, divsecon, divthird, divforth);

      x = divfirst*0 + divsecon*1+ divthird*2 + divforth*3;
      digVerif = x % 10;
      printf("\nX = %d\nDigito verificador = %d", x, digVerif);
      printf("\nO digito verificador está correto!");

    }

  } while(numConta <= 999 || numConta >= 10000);



  return 0;
}
