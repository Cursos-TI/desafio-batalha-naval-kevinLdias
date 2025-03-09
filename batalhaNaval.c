#include <stdio.h>
#include <stdlib.h>

void mostrarTabuleiro(int tab[10][10]) {
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
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    } 
}

int main() {
    
    int tabuleiro[10][10];
    int navio = 3;

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
        tabuleiro[i][j] = navio;
    }

    for (int i = 4, j = 7, cont = 0; i <= 6; i++, cont++) {
        tabuleiro[i][j] = navio;
    }
    
    /* Atribuindo as cordenadas dos navios na diagonal: cord navio 1: (8,0), (7,1), (6,2) 
    cord navio 2: (9,7), (8,6), (7,5)*/

    for (int i = 8, j = 0; i >=6 && j <= 2; i--, j++) {
        tabuleiro[i][j] = 3;
    }
    for (int i = 9, j = 7; i >=7 && j >= 5; i--, j--) {
        tabuleiro[i][j] = 3;
    }
    // chama uma função que mostra o tabuleiro
    mostrarTabuleiro(tabuleiro);
    
    return 0;
}