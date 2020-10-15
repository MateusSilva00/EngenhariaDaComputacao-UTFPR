#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  int a, div5, div3, div2;
  printf("Insira um número.: ");
  scanf("%d", &a);
  div5 = a % 5;
  div3 = a % 3;
  div2 = a % 2;

  if (div5 == 0 || div3 == 0 || div2 == 0){

    if (div5 == 0 && div3 == 0 && div2 == 0){

        printf("\n%d é divisível por 5, 3 e 2", a);
    }

    else if ((div5 == 0 || div3 == 0) && div2 != 0){

      if (div5 == 0 && div3 == 0){

        printf("\n%d é divisível somente por 5 e 3", a);
      }

      else if(div3 == 0){

        printf("\n%d é divisível somente por 3", a);
      }

      else printf("\n%d é divisível somente por 5", a);
    }

    else if ((div3 == 0 || div2 == 0) && div5 != 0){

      if (div3 == 0 && div2 == 0){

        printf("\n%d é divisível somente por 3 e 2", a);
      }

      else if(div3 == 0){

        printf("\n%d é divisível somente por 3", a);
      }

      else printf("\n%d é divisível somente por 2", a);

    }

    else if ((div5 == 0 || div2 == 0) && div3 != 0){

      if (div5 == 0 && div2 == 0){

        printf("\n%d é divisível somente por 5 e 2", a);
      }

      else if(div5 == 0){

        printf("\n%d é divisível somente por 5", a);
      }

      else printf("\n%d é divisível somente por 2", a);

    }
  }

  else{
    printf("\n%d não é divisível por 5, 3 e 2", a);
  }

  return 0;
}
