#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int eh_palindromo(const char *str) {
    char pilha[MAX], fila[MAX];
    int topo = -1, frente = 0, tras = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char c = tolower(str[i]);
            pilha[++topo] = c;
            fila[tras++] = c;
        }
    }

    while (topo >= 0 && frente < tras) {
        if (pilha[topo--] != fila[frente++])
            return 0;
    }

    return 1;
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (eh_palindromo(palavra))
        printf("É palíndromo.\n");
    else
        printf("Não é palíndromo.\n");

    return 0;
}
