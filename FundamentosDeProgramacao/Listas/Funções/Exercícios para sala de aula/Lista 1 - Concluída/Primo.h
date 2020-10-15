#ifndef PRIMO_H_INCLUDED
#define PRIMO_H_INCLUDED

  int primo(int x){
    int i, countprimo=0;
    for(i=1; i<=x; i++){
      if(x % i == 0){
        countprimo++;
      }
    }
    if(countprimo == 2){
      return 0;
    }
    else {
      return 1;
    }
  }

#endif
