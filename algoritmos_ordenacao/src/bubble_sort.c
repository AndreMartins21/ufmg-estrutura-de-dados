#include <stdio.h>
#include "../include/sort_methods.h"
#include "uteis.h"

int* bubble_sort(int *vetor, int n){
    /*
    => N° de comparações: 
        (n² - n) / 2  [C(n) = O(n²)]
    => N° de movimentações/trocas: 
        - pior caso: 3 movimentações (aux=a; a=b; b=aux) = 3*C(n) = O(n²)
        - melhor caso: Vetor ordenado = O(1)
    => É estável (Não muda posições de valores que já estavam ordenadas)

    => Exemplo:
    [4, 3, 1]
        i = 0
        j = 1
        [3, 4, 1]
            j = 2
            [3, 1, 4]
    [3, 1, 4]
        i = 1
        j = 1
        [1, 3, 4]
    */
    printf("Rodando BUBBLE_SORT...");
    int i, j;

    for(i=0; i<n-1;i++){
        for(j=1; j<n-1; j++){
            if (vetor[j] < vetor[j-1]){
                swap(&vetor[j], &vetor[j-1]);
            }
        }
    }
    return vetor;
}
