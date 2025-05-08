# 1. Simulação de Fila de Atendimento
from collections import deque

class FilaBanco:
    def __init__(self):
        self.fila = deque()

    def entrar_na_fila(self, cliente):
        self.fila.append(cliente)

    def atender_cliente(self):
        if self.fila:
            return self.fila.popleft()
        return "Nenhum cliente na fila."

# 2. Verificação de Palíndromo com Pilha e Fila
def eh_palindromo(texto):
    texto = texto.lower().replace(" ", "")

    pilha = []
    fila = deque()

    for char in texto:
        pilha.append(char)
        fila.append(char)

    while pilha:
        if pilha.pop() != fila.popleft():
            return False

    return True

# 3. Fila Circular

class FilaCircular:
    def __init__(self, capacidade):
        self.fila = [None] * capacidade
        self.capacidade = capacidade
        self.inicio = 0
        self.fim = 0
        self.tamanho = 0

    def enfileirar(self, item):
        if self.tamanho == self.capacidade:
            print("Fila cheia!")
            return
        self.fila[self.fim] = item
        self.fim = (self.fim + 1) % self.capacidade
        self.tamanho += 1

    def desenfileirar(self):
        if self.tamanho == 0:
            return "Fila vazia!"
        item = self.fila[self.inicio]
        self.inicio = (self.inicio + 1) % self.capacidade
        self.tamanho -= 1
        return item
    
# 4. Simulação de Impressora

class Impressora:
    def __init__(self):
        self.fila = deque()

    def adicionar_documento(self, nome, paginas):
        self.fila.append((nome, paginas))

    def imprimir_proximo(self):
        if self.fila:
            doc = self.fila.popleft()
            return f"Imprimindo: {doc[0]} - {doc[1]} páginas"
        return "Fila de impressão vazia"
    
# 5. Fila de Prioridade

import heapq

class FilaPrioridade:
    def __init__(self):
        self.fila = []

    def adicionar_tarefa(self, prioridade, tarefa):
        heapq.heappush(self.fila, (prioridade, tarefa))

    def obter_proxima(self):
        if self.fila:
            return heapq.heappop(self.fila)[1]
        return "Fila vazia"