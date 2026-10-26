#include <stdio.h>
#include "partida.h"
#include "tabuleiro.h"
#include "jogadorteclado.h"
#include "jogadoria.h"

JogadorTeclado humano;
JogadorIA inteligencia;

void configuraJogadores() {
    humano.tipo = 1;        // 'O' (Primeiro jogador)
    inteligencia.tipo = 4;  // 'X' (Segundo jogador - IA)
}

void inicia() {
    configuraJogadores();
    int jogadas = 0;
    int turno = 1; // 1 para Humano, 2 para IA

    while(jogadas < 9) {
        desenha();
        
        if(turno == 1) {
            printf("\nTurno do Humano (O):");
            joga(&humano);
            turno = 2;
        } else {
            printf("\nTurno da IA (X)...");
            jogaIA(&inteligencia);
            turno = 1;
        }
        
        jogadas++;

        if(temVencedor()) {
            desenha();
            // Quem ganhou foi o jogador do turno anterior
            if(turno == 2) {
                printf("\nVencedor: O (Humano)\n");
            } else {
                printf("\nVencedor: X (IA)\n");
            }
            return;
        }
    }
    desenha();
    printf("\nEmpate!\n");
}