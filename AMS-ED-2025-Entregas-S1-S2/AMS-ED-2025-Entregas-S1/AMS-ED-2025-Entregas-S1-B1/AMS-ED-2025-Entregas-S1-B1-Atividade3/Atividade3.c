#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char descricao[100];
    char status[20];
} Pedido;

Pedido lista[100];
int totalPedidos = 0;

int pedidoExiste(int numero) {
    for (int i = 0; i < totalPedidos; i++) {
        if (lista[i].numero == numero) {
            return 1;
        }
    }
    return 0;
}

void inserirPedido() {
    int numero;
    char descricao[100], status[20];
    
    printf("Digite o número do pedido: ");
    scanf("%d", &numero);
    getchar(); // Limpar buffer
    
    if (pedidoExiste(numero)) {
        printf("Erro: Pedido %d já existe.\n", numero);
        return;
    }
    
    printf("Digite a descrição do pedido: ");
    fgets(descricao, sizeof(descricao), stdin);
    descricao[strcspn(descricao, "\n")] = 0; // Remover nova linha
    
    printf("Digite o status do pedido: ");
    fgets(status, sizeof(status), stdin);
    status[strcspn(status, "\n")] = 0;
    
    if (totalPedidos < 100) {
        lista[totalPedidos].numero = numero;
        strcpy(lista[totalPedidos].descricao, descricao);
        strcpy(lista[totalPedidos].status, status);
        totalPedidos++;
        printf("Pedido %d inserido com sucesso!\n", numero);
    } else {
        printf("Erro: Lista de pedidos cheia.\n");
    }
}

void exibirPedidos() {
    if (totalPedidos == 0) {
        printf("Lista de pedidos vazia.\n");
        return;
    }
    for (int i = 0; i < totalPedidos; i++) {
        printf("Pedido #%d\nDescrição: %s\nStatus: %s\n---------------------------\n", 
                lista[i].numero, lista[i].descricao, lista[i].status);
    }
}

void buscarPedido() {
    int numero;
    printf("Digite o número do pedido para buscar: ");
    scanf("%d", &numero);
    
    for (int i = 0; i < totalPedidos; i++) {
        if (lista[i].numero == numero) {
            printf("Pedido encontrado:\nPedido #%d\nDescrição: %s\nStatus: %s\n", 
                    lista[i].numero, lista[i].descricao, lista[i].status);
            return;
        }
    }
    printf("Pedido %d não encontrado.\n", numero);
}

void atualizarStatus() {
    int numero;
    char novoStatus[20];
    
    printf("Digite o número do pedido para atualizar o status: ");
    scanf("%d", &numero);
    getchar(); // Limpar buffer
    
    for (int i = 0; i < totalPedidos; i++) {
        if (lista[i].numero == numero) {
            printf("Digite o novo status: ");
            fgets(novoStatus, sizeof(novoStatus), stdin);
            novoStatus[strcspn(novoStatus, "\n")] = 0;
            strcpy(lista[i].status, novoStatus);
            printf("Status do pedido %d atualizado para '%s'.\n", numero, novoStatus);
            return;
        }
    }
    printf("Pedido %d não encontrado.\n", numero);
}

void removerPedido() {
    int numero;
    printf("Digite o número do pedido para remover: ");
    scanf("%d", &numero);
    
    int encontrado = 0;
    for (int i = 0; i < totalPedidos; i++) {
        if (lista[i].numero == numero) {
            encontrado = 1;
            for (int j = i; j < totalPedidos - 1; j++) {
                lista[j] = lista[j + 1];
            }
            totalPedidos--;
            printf("Pedido %d removido com sucesso.\n", numero);
            break;
        }
    }
    if (!encontrado) {
        printf("Pedido %d não encontrado.\n", numero);
    }
}

void liberarLista() {
    totalPedidos = 0;
    printf("Lista de pedidos liberada.\n");
}

void menu() {
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir pedido\n");
        printf("2. Exibir pedidos\n");
        printf("3. Buscar pedido\n");
        printf("4. Atualizar status\n");
        printf("5. Remover pedido\n");
        printf("6. Liberar lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer
        
        switch (opcao) {
            case 1:
                inserirPedido();
                break;
            case 2:
                exibirPedidos();
                break;
            case 3:
                buscarPedido();
                break;
            case 4:
                atualizarStatus();
                break;
            case 5:
                removerPedido();
                break;
            case 6:
                liberarLista();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
