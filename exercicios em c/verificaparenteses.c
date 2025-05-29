#include <stdio.h>
#include <string.h>

#define MAX 100

int verifica_balanceamento(const char *exp) {
    char pilha[MAX];
    int topo = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{') {
            pilha[++topo] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (topo == -1)
                return 0; // fechando sem abrir

            char topoChar = pilha[topo--];
            if ((c == ')' && topoChar != '(') ||
                (c == ']' && topoChar != '[') ||
                (c == '}' && topoChar != '{'))
                return 0;
        }
    }

    return topo == -1; // pilha deve estar vazia
}

int main() {
    char exp[100];

    printf("Digite a expressão: ");
    scanf("%s", exp);

    if (verifica_balanceamento(exp))
        printf("Expressão balanceada.\n");
    else
        printf("Expressão não balanceada.\n");

    return 0;
}
