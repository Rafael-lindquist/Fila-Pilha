#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int avaliar_posfixa(const char *expr) {
    int pilha[MAX];
    int topo = -1;

    char copia[100];
    strcpy(copia, expr);

    char *token = strtok(copia, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            pilha[++topo] = atoi(token);
        } else {
            int b = pilha[topo--];
            int a = pilha[topo--];
            switch (token[0]) {
                case '+': pilha[++topo] = a + b; break;
                case '-': pilha[++topo] = a - b; break;
                case '*': pilha[++topo] = a * b; break;
                case '/': pilha[++topo] = a / b; break;
                default: printf("Operador inválido: %s\n", token); return 0;
            }
        }
        token = strtok(NULL, " ");
    }

    return pilha[topo];
}

int main() {
    char expr[100];
    printf("Digite a expressão pós-fixa (ex: 3 4 + 2 *): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0; // remove o \n

    int resultado = avaliar_posfixa(expr);
    printf("Resultado: %d\n", resultado);

    return 0;
}
