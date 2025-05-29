#include <stdio.h>

int soma_lista(int lista[], int tamanho) {
    if (tamanho == 0)
        return 0;
    return lista[0] + soma_lista(lista + 1, tamanho - 1);
}

int main() {
    int lista[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Soma da lista: %d\n", soma_lista(lista, tamanho));

    return 0;
}
