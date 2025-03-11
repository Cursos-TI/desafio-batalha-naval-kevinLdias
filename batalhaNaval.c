#include <stdio.h>

void mostrarTabuleiro(int tab[10][10]) {
    printf("\n--TABULEIRO BATALHA NAVAL--\n");
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void naviosVertical_Horizontal(int tab[10][10]) {
    for (int j = 1; j <= 3; j++) {
        tab[3][j] = 3;
    }
    for (int i = 4; i <= 6; i++) {
        tab[i][7] = 3;
    }
}

void naviosDiagonal(int tab[10][10]) {
    for (int i = 8, j = 0; i >= 6 && j <= 2; i--, j++) {
        tab[i][j] = 3;
    }
    for (int i = 9, j = 7; i >= 7 && j >= 5; i--, j--) {
        tab[i][j] = 3;
    }
}

void cone(int tab[10][10]) {
    int x = 2;
    for (int i = 0; i < 3; i++) {
        int y = 5;
        int inicio = x;
        if (x == 2) y -= 2;
        else if (x == 1) y -= 1;

        for (int k = inicio; k < y; k++) {
            tab[i][k] = 1;
        }
        x--;
    }
}

void cruz(int tab[10][10]) {
    for (int i = 1; i < 4; i++) {
        int inicio, fim;
        if (i == 2) {
            inicio = 5;
            fim = 9;
        } else {
            inicio = 7;
            fim = 7;
        }
        for (int k = inicio; k <= fim; k++) {
            tab[i][k] = 7;
        }
    }
}

void octaedro(int tab[10][10]) {
    for (int i = 6; i < 9; i++) {
        int inicio, fim;
        if (i == 7) {
            inicio = 7;
            fim = 9;
        } else {
            inicio = 8;
            fim = 8;
        }
        for (int k = inicio; k <= fim; k++) {
            tab[i][k] = 5;
        }
    }
}

int main() {
    char resp;
    int tabuleiro[10][10];

    printf("\n---BEM VINDO A BATALHA NAVAL---\n");
    printf("Descricao:\n");
    printf("0 = agua\n");
    printf("3 = navio\n");
    printf("1 = cone\n");
    printf("7 = cruz\n");
    printf("5 = octaedro\n");
    printf("------------------------\n");

    do {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                tabuleiro[i][j] = 0;
            }
        }

        printf("\nESCOLHA O QUE DESEJA IMPRIMIR NO TABULEIRO:\n");
        printf("[1] - SOMENTE O MAR\n");
        printf("[2] - NAVIOS VERTICAL/HORIZONTAL\n");
        printf("[3] - NAVIOS DIAGONAL\n");
        printf("[4] - HABILIDADE CONE\n");
        printf("[5] - HABILIDADE CRUZ\n");
        printf("[6] - HABILIDADE OCTAEDRO\n");
        printf("[7] - TODOS ACIMA\n");
        printf("DIGITE: ");

        int escolha;
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                break;
            case 2:
                naviosVertical_Horizontal(tabuleiro);
                break;
            case 3:
                naviosDiagonal(tabuleiro);
                break;
            case 4:
                cone(tabuleiro);
                break;
            case 5:
                cruz(tabuleiro);
                break;
            case 6:
                octaedro(tabuleiro);
                break;
            case 7:
                naviosVertical_Horizontal(tabuleiro);
                naviosDiagonal(tabuleiro);
                cone(tabuleiro);
                cruz(tabuleiro);
                octaedro(tabuleiro);
                break;
            default:
                printf("OPCAO INVALIDA\n");
        }

        mostrarTabuleiro(tabuleiro);

        printf("\nDESEJA JOGAR NOVAMENTE? [S/N] ");
        scanf(" %c", &resp);

    } while (resp != 'N' && resp != 'n');

    return 0;
}