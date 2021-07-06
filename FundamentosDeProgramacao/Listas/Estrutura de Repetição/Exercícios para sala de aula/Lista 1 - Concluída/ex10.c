#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main (){
  setlocale(LC_ALL,"Portuguese");
  int qt, qtmasc=0, qtfemin=0, qtinfal=0, total;
  char categoria;

  do {
    printf("Informe a quantidade.: ");
    scanf("%d", &qt);
    if (qt <= 0){
      break;
    }
    printf("\nInforme a categoria - Feminino (F), Masculino (M) ou Infatil (I).: ");
    scanf(" %c", &categoria);
    categoria = toupper(categoria);

    if (categoria == 'M'){
      qtmasc = qtmasc + qt;
    }
    else if (categoria == 'F'){
      qtfemin = qtfemin + qt;
    }
    else if (categoria == 'I'){
      qtinfal = qtinfal + qt;
    }
    else printf("Categoria Inválida");

  } while(qt > 0);
  total = qtmasc+ qtfemin + qtinfal;
  printf("Quantidade total %d", total);

  qtmasc = ((float)qtmasc/(float)total) * 100;
  qtfemin = ((float)qtfemin/(float)total) * 100;
  qtinfal = ((float)qtinfal/(float)total) * 100;
  printf("\n%d%% Feminino\n%d%% Masculino\n%d%% Infatil", qtfemin, qtmasc, qtinfal);

  return 0;
}
