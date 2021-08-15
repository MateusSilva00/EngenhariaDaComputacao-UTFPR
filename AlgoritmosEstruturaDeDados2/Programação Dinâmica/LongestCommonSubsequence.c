#include <stdio.h>
#include <string.h>

int i, j, m, n, LCS_table[40][40];
char phrase1[40] = "Linux is my king";
char phrase2[40] = "Linux is not good";
char b[40][40];


void lcsAlgo(){
    m = strlen(phrase1);
    n = strlen(phrase2);

    //Enchendo a matriz com 0;
    for(i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for(i = 0; i <= n; i++)
        LCS_table[0][i] = 0;

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++){
            if(phrase1[i-1] == phrase2[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;

            else if(LCS_table[i - 1][j] >= LCS_table[i][j-1])
                LCS_table[i][j] = LCS_table[i - 1][j];

            else 
                LCS_table[i][j] = LCS_table[i][j-1];
        }
    
    int index = LCS_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    int i = m, j = n;
    while(i > 0 && j > 0){
        if(phrase1[i - 1] == phrase2[j - 1]){
            lcsAlgo[index - 1] = phrase1[i - 1];
            i--;
            j--;
            index--;
        }
        else if(LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else j--;
    }

    printf("Phrase 1 : %s\nPhrase 2: %s\n", phrase1, phrase2);
    printf("LCS: %s", lcsAlgo);

}

int main(){

    lcsAlgo();
    printf("\n");
    return 0;
}