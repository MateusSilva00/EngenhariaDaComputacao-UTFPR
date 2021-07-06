#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL, "Portuguese");

  char saldo, aplicacoes;
  printf("Saldo:\nP - Positivo\nN - negativo\n");
  scanf("%c", &saldo);
  saldo = toupper(saldo);

  if (saldo == 'P' || saldo == 'N'){

     if (saldo == 'P'){
       printf("Cliente sem risco!");
     }

     else if(saldo == 'N'){
       printf("O Cliente tem aplicações?\nS - Sim\nN - Não\n");
       scanf(" %c", &aplicacoes);
       aplicacoes = toupper(aplicacoes);
       if (aplicacoes == 'S' || aplicacoes == 'N'){
         if (aplicacoes == 'S') {
           printf("Cliente sem risco!");
         }
         else if (aplicacoes == 'N'){
           printf("Cliente com risco!");
         }
         else printf("Inválido");
       }
     }
   }
 else {
   printf("Invalido");
    }

 return 0;

}
