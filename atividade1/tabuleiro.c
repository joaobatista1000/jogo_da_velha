#include <stdio.h>
#include "tabuleiro.h"

int M[3][3] = {0};

void desenha() {
    printf("\033[2J\033[H");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            char c = M[i][j] == 1 ? 'O' : (M[i][j] == 4 ? 'X' : ' ');
            printf(" %c %s", c, j < 2 ? "|" : "");
        }
        printf("\n%s", i < 2 ? "---|---|---\n" : "");
    }
}

int temVencedor() {
    int s;
    for(int i=0; i<3; i++) {
        s = M[i][0] + M[i][1] + M[i][2];
        if(s == 3 || s == 12) return s;
        s = M[0][i] + M[1][i] + M[2][i];
        if(s == 3 || s == 12) return s;
    }
    s = M[0][0] + M[1][1] + M[2][2];
    if(s == 3 || s == 12) return s;
    s = M[0][2] + M[1][1] + M[2][0];
    if(s == 3 || s == 12) return s;
    return 0;
}

void marcaJogada(int x, int y, int tipo) {
    if(x >= 0 && x < 3 && y >= 0 && y < 3 && M[x][y] == 0)
        M[x][y] = tipo;
}

int getPosicao(int x, int y) {
    return M[x][y];
}