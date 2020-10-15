// Crie um programa que leia uma data no formato ddmmaaaa e imprima se a data é válida ou
// não.
#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "Portuguese");
  int data, dia, mes, ano;

  printf("Insira a data no formato ddmmaaaa.: ");
  scanf("%d", &data);
  dia = data / 1000000;
  mes = (data / 10000)%100;
  ano = (data % 1000000)%10000;

  if (dia > 0 && dia <= 31 && mes > 0 && mes <=12 && ano >= 0){

    if (dia <= 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
      printf("Data Válida %d/%d/%d", dia, mes, ano);
    }

    else if (dia <= 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
      printf("Data Válida %d/%d/%d", dia, mes, ano);
    }
    else if (( (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0 ) && mes == 2 && dia <= 29){
      printf("Data Válida %d/%d/%d", dia, mes, ano);
    }
    else if (mes == 2 && dia <= 28){
      printf("Data Válida %d/%d/%d", dia, mes, ano);
    }
    else printf("Data Inválida");

  }
  else {
    printf("Data Inválida");
  }

  return 0;
}
