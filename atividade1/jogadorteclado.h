#ifndef JOGADORTECLADO_H
#define JOGADORTECLADO_H

typedef struct {
    int tipo; // 1 para 'O', 4 para 'X'
} JogadorTeclado;

void joga(JogadorTeclado *j);

#endif