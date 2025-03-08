#include <stdio.h>

int main() {
    
    int tabuleiro[10][10];
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};

    // atribuindo o valor zero para o tabuleiro
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    /* Atribuindo as cordenadas dos navios: cord navio 1: (3,1), (3,2), (3,3) 
    cord navio 2: (4,7), (5,7), (6,7)*/

    for (int i = 3, j = 1, cont = 0; j <= 3; j++, cont++) {
        tabuleiro[i][j] = navio1[cont];
    }

    for (int i = 4, j = 7, cont = 0; i <= 6; i++, cont++) {
        tabuleiro[i][j] = navio2[cont];
    }

    // Imprimindo o tabuleiro
    printf("\n--TABULEIRO BATALHA NAVAL--\n");
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++)
    {   
        if (i == 9) {
            printf("%d ", i+1);
        }
        else {
        printf(" %d ", i+1);
        }

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }   
    
    return 0;
}