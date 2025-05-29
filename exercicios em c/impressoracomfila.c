#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[100];
    int paginas;
} Documento;

Documento fila[MAX];
int frente = 0, tras = 0;

void adicionar_documento(const char *nome, int paginas) {
    if (tras < MAX) {
        strcpy(fila[tras].nome, nome);
        fila[tras].paginas = paginas;
        printf("Documento '%s' (%d pág.) adicionado à fila.\n", nome, paginas);
        tras++;
    } else {
        printf("Fila de impressão cheia!\n");
    }
}

void imprimir_proximo() {
    if (frente < tras) {
        Documento doc = fila[frente++];
        printf("Imprimindo '%s' (%d pág.)...\n", doc.nome, doc.paginas);
    } else {
        printf("Nenhum documento na fila.\n");
    }
}

int main() {
    adicionar_documento("Relatório.pdf", 5);
    adicionar_documento("Resumo.docx", 2);
    adicionar_documento("Apresentacao.ppt", 10);

    imprimir_proximo();
    imprimir_proximo();
    imprimir_proximo();
    imprimir_proximo();  // fila vazia

    return 0;
}
