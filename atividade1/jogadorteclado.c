#include <stdio.h>
#include "jogadorteclado.h"
#include "tabuleiro.h"

void joga(JogadorTeclado *j) {
    int x, y;
    while(1) {
        printf("\nJogador %c (linha coluna 0-2): ", j->tipo == 1 ? 'O' : 'X');
        if(scanf("%d %d", &x, &y) != 2) break;
        if(x >= 0 && x < 3 && y >= 0 && y < 3 && getPosicao(x, y) == 0) {
            marcaJogada(x, y, j->tipo);
            break;
        }
    }
}