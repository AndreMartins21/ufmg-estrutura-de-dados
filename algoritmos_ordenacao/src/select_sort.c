#include <stdio.h>
#include "../include/sort_methods.h"
#include "uteis.h"

int* select_sort(int *vetor, int n){
    /*
    => N° de comparações: 
        (n² - n) / 2  [C(n) = O(n²)]
    => N° de movimentações/trocas: 
        3*(n-1) = O(n)
    => Não é estável (pode mudar posições de valores que já estavam ordenadas)
    
    => Exemplo:
    [4, 3, 1]
        i = 0
        idx_min = 0
        j = 1
            idx_min = 1
        j = 2
            idx_min = 2
    [1, 3, 4]
        i = 1
        idx_min = 1
        j = 2
    [1, 3, 4]
    */
    printf("Rodando SELECT_SORT...");
    int i, j, idx_min;

    for(i=0; i<n-1;i++){
        idx_min = i;
        for(j=i+1; j<n; j++){
            if (vetor[j] < vetor[idx_min]){
                idx_min = j;
            } 
        }
        swap(&vetor[i], &vetor[idx_min]);
    }
    return vetor;
}
