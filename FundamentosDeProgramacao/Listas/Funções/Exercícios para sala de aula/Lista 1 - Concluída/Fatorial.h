#ifndef FATORIAL_H_INCLUDED
#define FATORIAL_H_INCLUDED

  int calcFatorial(int x){
    int i, fatorial = x;
    for(i=x-1; i>=1; i--){
      fatorial = fatorial * i;
    }
    return fatorial;
  }

  void mostraFatorial(int x){
    int i;
    for(i=x; i>=1; i--){
      if(i == x){
        printf("%d! = ", x);
      }

      if(i == 1){
        printf("%d = ", i);
      }
      else{
        printf("%d * ", i);
      }
    }
  }

#endif
