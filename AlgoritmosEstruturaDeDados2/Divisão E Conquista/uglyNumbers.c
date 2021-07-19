#include <stdio.h>
#include <stdlib.h>

// Função que divide a maior potência de B
int maxDivide(int a, int b){
    while (a % b == 0)
        a = a / b;
    return a;
}

// Função para chegar se um número é feio ou não
int isUgly(int num){
    num = maxDivide(num, 2);
    num = maxDivide(num, 3);
    num = maxDivide(num, 5);

    return (num == 1) ? 1 : 0;
}

// Pegar o n-ésimo número feio
int getNthUglyNum(int num){

    int i = 1;
    int count = 1;

    while (num > count){
        i++;
        if(isUgly(i))
            count++;
    }
    return i;
}

int main(){

    unsigned num = getNthUglyNum(150);
    printf("120th ugly number is %d\n", num);

    return 0;
}