#include <stdio.h>

#define MAX 100

void decimal_para_binario(int num) {
    int pilha[MAX];
    int topo = -1;

    if (num == 0) {
        printf("0\n");
        return;
    }

    while (num > 0) {
        pilha[++topo] = num % 2;
        num /= 2;
    }

    while (topo >= 0)
        printf("%d", pilha[topo--]);
    printf("\n");
}

int main() {
    int num;
    printf("Digite um número decimal: ");
    scanf("%d", &num);

    printf("Binário: ");
    decimal_para_binario(num);

    return 0;
}
