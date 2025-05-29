#include <stdio.h>
#include <string.h>

#define MAX 100

char fila[MAX][100];
int frente = 0, tras = 0;

void enfileirar(const char *nome) {
    if (tras < MAX) {
        strcpy(fila[tras++], nome);
        printf("Cliente '%s' entrou na fila.\n", nome);
    } else {
        printf("Fila cheia!\n");
    }
}

void desenfileirar() {
    if (frente < tras) {
        printf("Atendendo cliente: %s\n", fila[frente++]);
    } else {
        printf("Fila vazia!\n");
    }
}

int main() {
    enfileirar("João");
    enfileirar("Maria");
    enfileirar("Carlos");

    desenfileirar();
    desenfileirar();
    desenfileirar();
    desenfileirar();  // fila vazia

    return 0;
}
