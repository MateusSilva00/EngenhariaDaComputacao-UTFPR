#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main (){

  setlocale(LC_ALL, "Portuguese");
  int dia_nasc, mes_nasc, opcao;
  printf("Insira o dia de seu nascimento.: ");
  scanf("%d", &dia_nasc);
  printf("Insira o mês do seu nascimento.: ");
  scanf("%d", &mes_nasc);

  // Verificando se o dia existe
  if (dia_nasc < 0 || dia_nasc >= 32){
      printf("Data Inválida");
      exit(0);
  }
  switch (mes_nasc) {

    case 1:
        if (dia_nasc <= 20){
            printf ("Voce é do signo de Capricornio");
        }
        else  printf ("Voce é do signo de Aquario");
    break;

    case 2:
      if (dia_nasc <= 19){
          printf("Você é do signo de Aquário");
      }
      else printf("Você é do signo de Peixes");
    break;

    case 3:
      if (dia_nasc <= 20){
        printf("Você é do signo de Peixes");
      }
      else printf("Você é do signo de Aries");
    break;

    case 4:
      if (dia_nasc <= 20){
        printf("Você é do Signo de Aries");
      }
      else printf("Você é do Signo de Touro");
    break;

    case 5:
      if (dia_nasc <= 20){
        printf("Você é do Signo de Touro");
      }
      else printf("Você é do Signo de Gêmeos");
    break;

    case 6:
      if (dia_nasc <= 20){
        printf("Você é do Signo de Gêmeos");
      }
      else printf("Você é do Signo de Câncer");
    break;

    case 7:
      if (dia_nasc <= 21){
        printf("Você é do Signo de Câncer");
      }
      else printf("Você é do Signo de Leão");
    break;

    case 8:
      if (dia_nasc <= 22){
        printf("Você é do Signo de Leão");
      }
      else printf("Você é do Signo de Virgem");
    break;

    case 9:
      if (dia_nasc <= 22){
        printf("Você é do Signo de Virgem");
      }
      else printf("Você é do Signo de Libra");
    break;

    case 10:
      if (dia_nasc <= 22){
        printf("Você é do Signo de Libra");
      }
      else printf("Você é do Signo de Escorpião");
    break;

    case 11:
      if (dia_nasc <= 21){
        printf("Você é do Signo de Escorpião");
      }
      else printf("Você é do Signo de Sagitário");
    break;

    case 12:
      if (dia_nasc <= 21){
        printf("Você é do Signo de Sagitário");
      }
      else printf("Você é do Signo Capricórnio");
    break;

    default:
      printf("Data Inválida");

  }

  return 0;
}
