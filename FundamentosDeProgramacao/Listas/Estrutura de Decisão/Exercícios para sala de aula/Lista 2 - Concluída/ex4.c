// 4) Ler o gênero (F ou f para feminino, M ou m para masculino. Para qualquer outro
// caractere informar que é inválido e finalizar o programa). Se informado um caractere
// válido, ler a altura da pessoa e calcular e mostrar o seu peso ideal, utilizando as seguintes
// fórmulas:
// a) Para homens: (72.7 * h) - 58;
// b) Para mulheres: (62.1 * h) - 44.7.
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main(){
  setlocale(LC_ALL,"Portuguese");
  char genero, genero_toupper;
  float altura, peso_ideal;
  printf("DIGITE SUA ALTURA.: ");
  scanf("%f", &altura);
  printf("SELECIONE O SEU GÊNERO:\nM - MULHER\nH - HOMEM ");
  scanf("%s", &genero);
  genero_toupper = toupper(genero);

  if (genero_toupper == 'M' || genero_toupper == 'H'){
    if (genero_toupper == 'M'){
      peso_ideal = (62.1*altura) - 44.7;
      printf("\nGênero Mulher\nSeu Peso Ideal:%.2f Kg", peso_ideal);
    }
    else{
      peso_ideal = (72.7*altura) - 58;
      printf("\nGênero Homem\nSeu Peso Ideal:%.2f Kg", peso_ideal);
    }
  }

  else{
      printf("\nVocê inseriu um caractere inválido!");
  }

  return 0;
}
