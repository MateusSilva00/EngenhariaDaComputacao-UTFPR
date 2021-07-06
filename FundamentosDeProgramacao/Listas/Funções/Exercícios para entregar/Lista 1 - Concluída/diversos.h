#ifndef DIVERSOS_H_INCLUDED
#define DIVERSOS_H_INCLUDED

  int quadrado(int num){
    return num * num;
  }

  float polegadas(int num){
    return num * 0.393701;
  }

  float ConversorMoeda(float valor, float cotacao, char tipo){
    switch (tipo) {
      case 'D':
        return valor / cotacao;
        break;

      case 'R':
        return valor * cotacao;
        break;

      default:
        printf("Conversao inválida!\n");
    }
  }

  int multiplicacao(int x, int y){
    return x * y;
  }

#endif
