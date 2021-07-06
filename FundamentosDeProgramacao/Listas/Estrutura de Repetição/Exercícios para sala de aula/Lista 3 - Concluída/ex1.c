#include <stdio.h>

int main(){
  int i;
  for (i = 1; i<=1000; i++){
    printf("\n%d", i);
    if (i % 11 == 0 ){
      printf("\t Divisível por 11");
    }
  }


  return 0;
}
