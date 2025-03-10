/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B1-2                          */
/*             Objetivo: Programa de  seleção para RESIDÊNCIA MÉDICA                */
/*                                                                                  */
/*                                  Autor: Thierry Henry Tavares de Andrade         */
/*                                                                   Data:08/03/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>

#define MAX_CANDIDATOS 50

struct Cand {
    char nomeal[100];
    float ntPE[4], ntAC[5], ntPP[10], ntEB[3];
    float ntfinal;
};

float calcularNota(float *notas, int qtdnotas) {
    float soma = 0.0, maior = notas[0], menor = notas[0];
    
    for (int i = 0; i < qtdnotas; i++) {
        soma += notas[i];
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
    }
    
    return (soma - maior - menor) / (qtdnotas - 2);
}

void inserirCand(struct Cand *candidato) {
    printf("Insira o nome do candidato: ");
    scanf(" %[^
]", candidato->nomeal);
    
    printf("\nDigite as 4 notas da Prova Escrita (PE):\n");
    for(int i = 0; i < 4; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidato->ntPE[i]);
    }
    
    printf("\nDigite as 5 notas da Análise Curricular (AC):\n");
    for(int i = 0; i < 5; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidato->ntAC[i]);
    }
    
    printf("\nDigite as 10 notas da Prova Prática (PP):\n");
    for(int i = 0; i < 10; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidato->ntPP[i]);
    }
    
    printf("\nDigite as 3 notas da Entrevista em Banca (EB):\n");
    for(int i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &candidato->ntEB[i]);
    }
    
    float PE = calcularNota(candidato->ntPE, 4);
    float AC = calcularNota(candidato->ntAC, 5);
    float PP = calcularNota(candidato->ntPP, 10);
    float EB = calcularNota(candidato->ntEB, 3);
    
    candidato->ntfinal = (PE * 0.3) + (AC * 0.1) + (PP * 0.4) + (EB * 0.2);
}

void ordenarCandidatos(struct Cand *candidatos, int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (candidatos[j].ntfinal < candidatos[j + 1].ntfinal) {
                struct Cand temp = candidatos[j];
                candidatos[j] = candidatos[j + 1];
                candidatos[j + 1] = temp;
            }
        }
    }
}

void top5(struct Cand *candidatos, int total) {
    int qtd = (total < 5) ? total : 5;
    printf("\n===== TOP %d Candidatos =====\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("\n%dº Lugar: %s", i + 1, candidatos[i].nomeal);
        printf("\nNota Final: %.2f\n", candidatos[i].ntfinal);
    }
}

int main() {
    struct Cand candidatos[MAX_CANDIDATOS];
    int totalCan, opcao;

    do {
        printf("\n1 - Cadastrar Candidato\n2 - Exibir Ranking\n3 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (totalCan < MAX_CANDIDATOS) {
                    printf("\n== Candidato %d ==\n", totalCan + 1);
                    inserirCand(&candidatos[totalCan]);
                    totalCan++;
                } else {
                    printf("\nLimite de candidatos atingido!\n");
                }
                break;
            case 2:
                if (totalCan > 0) {
                    ordenarCandidatos(candidatos, totalCan);
                    top5(candidatos, totalCan);
                } else {
                    printf("\nNenhum candidato cadastrado ainda.\n");
                }
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
