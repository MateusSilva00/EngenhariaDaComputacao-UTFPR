#include <stdio.h>
#include <string.h>

int main(){

  char senhaArmazenada[7] = "123456", tentativa[7];
  int count = 0;

  do {
    printf("Informe a senha.: ");
    fgets(tentativa, sizeof(tentativa), stdin);
    if(strcmp(senhaArmazenada, tentativa) == 0){
      printf("Senha válida!\n");
      break;
    }
    else{
      count++;
      if(count == 3){
        printf("Acesso negado!\n");
        break;
      }
      else printf("Senha inválida!\n");
    }
  } while(senhaArmazenada != tentativa || count == 3);

  return 0;
}
