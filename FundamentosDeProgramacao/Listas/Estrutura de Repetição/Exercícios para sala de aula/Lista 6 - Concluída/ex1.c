// Ler um número positivo, validar a entrada repetindo a leitura até que seja informado um
// número que atende essa condição. Esse número representa a quantidade de números
// ímpares a serem mostrados. Apresentar esses valores n por linha, sendo n um número
// maior que zero, informado pelo usuário. Os valores são apresentados separados por
// tabulação. Fazer a média dos números ímpares mostrados.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int num, impar=1, i=1, nlinha;
  float media = 0;
  char ch;

  do {
    do {
      printf("Insira o número.: ");
      scanf("%d", &num);
      if(num < 0){
        printf("Insira um numero positivo!\n");
      }
      else{

        do {
          printf("Quantos valores devem ser mostrados por linha ? ");
          scanf("%d", &nlinha);
          if (nlinha < 0){
            printf("Insira um numero positivo!\n");
          }
          else {
            while (i <= num) {
              printf("\t%d", impar);
              impar = impar + 2;
              if(i % nlinha == 0){
                printf("\n");
              }
              i++;
              media = media + impar;
            }
            media = media / num;
            printf("\nMedia dos impares.:%.2f\n", media);
            printf("\nDigite S para continuar.: ");
            fflush(stdin);
            scanf(" %c", &ch);
            ch = toupper(ch);
            if (ch == 'S'){
              impar=1; i=1; media = 0;
            }
          }
        } while(nlinha < 0);
      }

    } while(num < 0);

  } while(ch == 'S');


  return 0;
}
