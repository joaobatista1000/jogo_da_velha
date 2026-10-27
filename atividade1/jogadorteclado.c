#include <stdio.h>
#include "jogadorteclado.h"
#include "tabuleiro.h"

void joga(JogadorTeclado *j) {
    int x, y;
    while(1) {
        printf("\nJogador %c (linha e coluna de 0 a 2, ex: 0 0): ", j->tipo == 1 ? 'O' : 'X');
        fflush(stdout); // Força o texto a aparecer imediatamente na tela
        
        if(scanf("%d %d", &x, &y) != 2) {
            // Limpa o lixo do teclado se o usuário digitar uma letra por engano
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Erro: Digite apenas numeros!\n");
            continue;
        }
        
        // Verifica se a jogada é válida (dentro da matriz e casa vazia)
        if(x >= 0 && x < 3 && y >= 0 && y < 3 && getPosicao(x, y) == 0) {
            marcaJogada(x, y, j->tipo);
            break;
        } else {
            printf("Jogada invalida! Posicao ocupada ou fora dos limites (0-2). Tente novamente.\n");
        }
    }
}
