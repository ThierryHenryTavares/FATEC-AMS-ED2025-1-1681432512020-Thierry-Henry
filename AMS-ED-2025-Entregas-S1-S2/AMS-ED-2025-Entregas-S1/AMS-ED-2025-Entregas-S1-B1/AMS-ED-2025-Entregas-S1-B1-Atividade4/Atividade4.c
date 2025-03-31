#include <stdio.h>
#include <stdlib.h>

#define MAX 4 // O número máximo de elementos na pilha (X, Y, Z, T)

// Tipo para a pilha
typedef struct pilha {
    double dados[MAX];
    int topo;
} Pilha;

// Funções básicas da pilha

// Cria uma nova pilha
Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

// Verifica se a pilha está vazia
int vazia(Pilha* p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int cheia(Pilha* p) {
    return p->topo == MAX - 1;
}

// Adiciona um valor à pilha
void push(Pilha* p, double dado) {
    if (cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = dado;
}

// Remove e retorna o valor do topo da pilha
double pop(Pilha* p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  // Indicativo de erro
    }
    return p->dados[(p->topo)--];
}

// Retorna o valor no topo da pilha
double top(Pilha* p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;  // Indicativo de erro
    }
    return p->dados[p->topo];
}

// Função para avaliar a expressão RPN
void avaliar_rpn(Pilha* p, char* expressao) {
    int i = 0;
    char token[20];
    int j = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == ' ' || expressao[i] == '\n') {
            token[j] = '\0'; // Finaliza o token
            if (token[0] >= '0' && token[0] <= '9') { // Se for número
                push(p, atof(token));
            } else { // Se for operador
                double b = pop(p); // Operando 2
                double a = pop(p); // Operando 1
                double resultado;
                switch (token[0]) {
                    case '+':
                        resultado = a + b;
                        break;
                    case '-':
                        resultado = a - b;
                        break;
                    case '*':
                        resultado = a * b;
                        break;
                    case '/':
                        if (b == 0) {
                            printf("Erro: Divisão por zero!\n");
                            return;
                        }
                        resultado = a / b;
                        break;
                    default:
                        printf("Erro: Operador desconhecido %s\n", token);
                        return;
                }
                push(p, resultado);
            }
            j = 0; // Reinicia o índice do token
        } else {
            token[j++] = expressao[i]; // Adiciona o caractere ao token
        }
        i++;
    }

    // Se restar algo na pilha, exibe o resultado final
    if (!vazia(p)) {
        printf("Resultado: %.2f\n", top(p));
    }
}

int main() {
    Pilha* p = criar_pilha();
    char expressao[100];

    // Solicita a expressão RPN
    printf("Digite a expressão em RPN (exemplo: 3 4 + 2 *): ");
    fgets(expressao, sizeof(expressao), stdin);

    // Avaliar a expressão RPN
    avaliar_rpn(p, expressao);

    // Libera a memória da pilha
    free(p);
    return 0;
}
