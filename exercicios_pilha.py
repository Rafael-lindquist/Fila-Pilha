# 1. Inversão de String

def inverter_string(texto):
    pilha = []
    for char in texto:
        pilha.append(char)

    resultado = ""
    while pilha:
        resultado += pilha.pop()

    return resultado

# 2. Verificação de Parênteses Balanceados

def verifica_balanceamento(expressao):
    pilha = []
    aberturas = "({["
    fechamentos = ")}]"

    for char in expressao:
        if char in aberturas:
            pilha.append(char)
        elif char in fechamentos:
            if not pilha:
                return False

    topo = pilha.pop()
    if aberturas.index(topo) != fechamentos.index(char):
        return False
    return len(pilha) == 0

# 3. Conversão Decimal para Binário

def decimal_para_binario(numero):
    if numero == 0:
        return "0"

    pilha = []
    while numero > 0:
        resto = numero % 2
        pilha.append(str(resto))
        numero = numero // 2

    binario = ""
    while pilha:
        binario += pilha.pop()

    return binario

# 4. Desfazer Operações

class EditorTexto:
    def __init__(self):
        self.texto = ""
        self.historico = []

    def adicionar_texto(self, novo_texto):
        self.historico.append(self.texto)
        self.texto += novo_texto

    def desfazer(self):
        if self.historico:
            self.texto = self.historico.pop()
        else:
            print("Nada para desfazer.")

    def mostrar_texto(self):
        return self.texto
    
# 5. 

def avaliar_posfixa(expressao):
    tokens = expressao.split()
    pilha = []

    for token in tokens:
        if token.isdigit():
            pilha.append(int(token))
        else:
            b = pilha.pop()
            a = pilha.pop()
            if token == '+':
                pilha.append(a + b)
            elif token == '-':
                pilha.append(a - b)
            elif token == '*':
                pilha.append(a * b)
            elif token == '/':
                pilha.append(int(a / b))  # Para resultado inteiro
            else:
                raise ValueError(f"Operador desconhecido: {token}")

    return pilha.pop()