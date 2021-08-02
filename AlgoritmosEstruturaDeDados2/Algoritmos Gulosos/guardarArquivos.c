#include <stdio.h>
#include <stdlib.h>

int quantidadeArquivos(int C, int arr[]){
    int quant = 0;
    while (C > 0){
        C -= arr[quant];
        quant++;
    }

    return (C < 0) ? quant -1: quant;
}

int main(){
    
    int arquivos[] = {10, 10, 20, 20, 30, 45, 50};
    int capacidade = 100;

    printf("%d", quantidadeArquivos(capacidade, arquivos));
}