#include <stdio.h>
#include <string.h>

#define MAX 100

char pilha[MAX][100];
int topo = -1;

void adicionar_acao(const char *acao) {
    if (topo < MAX - 1)
        strcpy(pilha[++topo], acao);
}

void desfazer() {
    if (topo >= 0) {
        printf("Desfazendo: %s\n", pilha[topo--]);
    } else {
        printf("Nada para desfazer.\n");
    }
}

int main() {
    adicionar_acao("Escreveu 'Olá'");
    adicionar_acao("Apagou 'O'");
    adicionar_acao("Digitou 'Oi'");

    desfazer();
    desfazer();
    desfazer();
    desfazer();  // sem ações restantes

    return 0;
}
