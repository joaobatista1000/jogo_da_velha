#include <stdio.h>
#include "partida.h"
#include "tabuleiro.h"
#include "jogadorteclado.h"

JogadorTeclado j1, j2;

void configuraJogadores() {
    j1.tipo = 1; // 'O'
    j2.tipo = 4; // 'X'
}

void inicia() {
    configuraJogadores();
    int jogadas = 0;
    JogadorTeclado *vez = &j1;

    while(jogadas < 9) {
        desenha();
        joga(vez);
        jogadas++;

        if(temVencedor()) {
            desenha();
            printf("\nVencedor: %c\n", vez->tipo == 1 ? 'O' : 'X');
            return;
        }

        vez = (vez == &j1) ? &j2 : &j1;
    }
    desenha();
    printf("\nEmpate!\n");
}