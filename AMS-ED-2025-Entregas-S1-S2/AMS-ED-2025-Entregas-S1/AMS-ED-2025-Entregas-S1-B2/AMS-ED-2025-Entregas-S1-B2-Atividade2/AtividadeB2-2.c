/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: Atividade B2-2                          */
/*             Objetivo: BubbleSort                                                 */
/*                                                                                  */
/*                                  Autor: Thierry Henry Tavares de Andrade         */
/*                                                                   Data:06/05/2025*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n);

    int array[n];

    for(i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Array ordenado: ");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
