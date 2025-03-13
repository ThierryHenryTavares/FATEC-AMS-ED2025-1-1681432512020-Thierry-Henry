/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-2                          */
/*             Objetivo: Programa de  seleção para RESIDÊNCIA MÉDICA                */
/*                                                                                  */
/*                                  Autor: Thierry Henry Tavares de Andrade         */
/*                                                                   Data:08/03/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>

struct Cand {
    char nome[100];
    float PE[4], AC[5], PP[10], EB[3];
    float notaFinal;
};

float calcularNota(float *notas, int qtd) {
    if (qtd < 3) return 0; // Se tiver menos de 3 notas, não faz sentido calcular

    float soma = 0, maior = notas[0], menor = notas[0];
    for (int i = 0; i < qtd; i++) {
        soma += notas[i];
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }
    return (soma - maior - menor) / (qtd - 2); // Média sem a maior e menor nota
}

void inserirCandidato(struct Cand *c) {
    printf("Nome do candidato: ");
    getchar(); // Evita problema no buffer
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = 0;

    printf("\nNotas da Prova Escrita (4 notas):\n");
    for (int i = 0; i < 4; i++) scanf("%f", &c->PE[i]);

    printf("\nNotas da Análise Curricular (5 notas):\n");
    for (int i = 0; i < 5; i++) scanf("%f", &c->AC[i]);

    printf("\nNotas da Prova Prática (10 notas):\n");
    for (int i = 0; i < 10; i++) scanf("%f", &c->PP[i]);

    printf("\nNotas da Entrevista em Banca (3 notas):\n");
    for (int i = 0; i < 3; i++) scanf("%f", &c->EB[i]);

    // Calculando a nota final com os pesos certos
    c->notaFinal = (calcularNota(c->PE, 4) * 0.3) + (calcularNota(c->AC, 5) * 0.1) +
                   (calcularNota(c->PP, 10) * 0.4) + (calcularNota(c->EB, 3) * 0.2);
}

void ordenarCandidatos(struct Cand *candidatos, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (candidatos[j].notaFinal < candidatos[j + 1].notaFinal) {
                struct Cand temp = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = temp;
            }
        }
    }
}

void exibirTop5(struct Cand *candidatos, int total) {
    if (total == 0) {
        printf("\nNenhum candidato cadastrado ainda.\n");
        return;
    }

    ordenarCandidatos(candidatos, total);
    int qtd = (total < 5) ? total : 5;
    printf("\n===== TOP %d Candidatos =====\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("\n%dº Lugar: %s", i + 1, candidatos[i].nome);
        printf("\nNota Final: %.2f\n", candidatos[i].notaFinal);
    }
}

int main() {
    struct Cand candidatos[50];
    int totalCan = 0, opcao;

    do {
        printf("\n1 - Cadastrar Candidato\n2 - Exibir Ranking\n3 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalCan < 50) {
                    inserirCandidato(&candidatos[totalCan]);
                    totalCan++;
                } else {
                    printf("\nLimite de candidatos atingido!\n");
                }
                break;
            case 2:
                exibirTop5(candidatos, totalCan);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}

