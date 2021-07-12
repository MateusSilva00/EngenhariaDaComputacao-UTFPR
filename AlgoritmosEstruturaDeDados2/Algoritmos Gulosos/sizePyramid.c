#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

int comp(const void *elem1, const void *elem2){
    int f = *((int *)elem1);
    int s = *((int *)elem2);
    if (f > s)
        return 1;
    if (f < s)
        return -1;
    return 0;
}

int maxLevel(int boxes[], int n){
    qsort(boxes, n, sizeof(int), comp);

    int ans = 1;

    // Largura total do andar anterior e o numeros total
    // de caixas no andar anterior
    int prev_width = boxes[0];
    int prev_cont = 1;

    // Numero de objetos no andar atual
    int curr_count = 0;
    // Largura do andar atual
    int curr_width = 0;
    for(int i = 1; i < n; i++){
        curr_width += boxes[i];
        curr_count += 1;

        if(curr_width > prev_width && curr_count > prev_cont){
            prev_width = curr_width;
            prev_cont = curr_count;
            curr_count = 0;
            curr_width = 0;
            // Aumentar os andares
            ans++;
        }
    }

    return ans;
}

int main(){

    int boxes[TAM];
    printf("Boxes: ");
    for(int i = 0; i < TAM; i++){
        boxes[i] = rand () % 100 + 1;
        printf("[%d] ", boxes[i]);
    }
    int size = sizeof(boxes)/sizeof(boxes[0]);
    int max = maxLevel(boxes, size);
    printf("Numbers of levels: %d", max);

}