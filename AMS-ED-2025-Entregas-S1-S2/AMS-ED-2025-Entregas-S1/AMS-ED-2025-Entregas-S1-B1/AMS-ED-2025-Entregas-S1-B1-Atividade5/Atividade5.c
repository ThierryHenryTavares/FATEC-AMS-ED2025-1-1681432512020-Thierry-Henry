/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-5                          */
/*             Objetivo: Transforma Lista Ligada em Pilha                           */
/*                                                                                  */
/*                                  Autor: Thierry Henry Tavares de Andrade         */
/*                                                                   Data:01/04/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#define MAX_PEDIDOS 100

typedef struct {
    int numero;
    char descricao[100];
    char status[20];
} Pedido;

Pedido pilha[MAX_PEDIDOS];
int topo = -1;

void inserirPedido() {
    if (topo >= MAX_PEDIDOS - 1) {
        printf("Erro: Pilha de pedidos cheia.\n");
        return;
    }

    Pedido novoPedido;
    printf("Digite o número do pedido: ");
    scanf("%d", &novoPedido.numero);
    getchar(); // Limpar buffer

    printf("Digite a descrição do pedido: ");
    fgets(novoPedido.descricao, sizeof(novoPedido.descricao), stdin);
    novoPedido.descricao[strcspn(novoPedido.descricao, "\n")] = 0;

    printf("Digite o status do pedido: ");
    fgets(novoPedido.status, sizeof(novoPedido.status), stdin);
    novoPedido.status[strcspn(novoPedido.status, "\n")] = 0;

    pilha[++topo] = novoPedido;
    printf("Pedido %d inserido com sucesso!\n", novoPedido.numero);
}

void exibirPedidos() {
    if (topo == -1) {
        printf("Pilha de pedidos vazia.\n");
        return;
    }
    for (int i = topo; i >= 0; i--) {
        printf("Pedido #%d\nDescrição: %s\nStatus: %s\n---------------------------\n",
               pilha[i].numero, pilha[i].descricao, pilha[i].status);
    }
}

void removerPedido() {
    if (topo == -1) {
        printf("Erro: Pilha vazia.\n");
        return;
    }
    printf("Pedido %d removido.\n", pilha[topo].numero);
    topo--; // Remove o último elemento
}

void liberarPilha() {
    topo = -1;
    printf("Pilha de pedidos esvaziada.\n");
}

void menu() {
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Inserir pedido\n");
        printf("2. Exibir pedidos\n");
        printf("3. Remover pedido (desfazer último pedido)\n");
        printf("4. Esvaziar pilha\n");
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
                removerPedido();
                break;
            case 4:
                liberarPilha();
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
