#include <stdio.h>

#define TAM 5

int fila[TAM];
int frente = 0, tras = 0, qtd = 0;

void enfileirar(int valor) {
    if (qtd == TAM) {
        printf("Fila cheia!\n");
        return;
    }

    fila[tras] = valor;
    tras = (tras + 1) % TAM;
    qtd++;
    printf("Enfileirado: %d\n", valor);
}

void desenfileirar() {
    if (qtd == 0) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Removido: %d\n", fila[frente]);
    frente = (frente + 1) % TAM;
    qtd--;
}

void mostrar_fila() {
    printf("Fila: ");
    for (int i = 0; i < qtd; i++)
        printf("%d ", fila[(frente + i) % TAM]);
    printf("\n");
}

int main() {
    enfileirar(10);
    enfileirar(20);
    enfileirar(30);
    enfileirar(40);
    enfileirar(50);

    mostrar_fila();

    desenfileirar();
    desenfileirar();

    mostrar_fila();

    enfileirar(60);
    enfileirar(70);

    mostrar_fila();

    return 0;
}
