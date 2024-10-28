#include <stdio.h>
#include "../include/sort_methods.h"
#include "uteis.h"

int* shell_sort(int *vetor, int n){
    /*
    => N° de comparações: 
        - Pior caso: O(N^(3/2))          

    => NÃO é estável para n/2^i (muda posições relativas de valores idênticos)
        
    => Exemplo:
    [4, 3, 1, 7, 2, 5, 9, 8]
        h = 8/2 = 4
        (
        compare([4, 2]) => Troca
        compare([3, 5]) => Não troca
        compare([1, 9]) => Não troca
        compare([7, 8]) => Não troca
        )
        [2, 3, 1, 7, 4, 5, 9, 8]
            h = 4/2 = 2
            (
            compare([2, 1]) => Troca
            compare([3, 7]) => Não troca
            compare([1, 4]) => Não troca
            compare([7, 5]) => Troca
            compare([4, 9]) => Não troca
            compare([5, 8]) => Não troca
            )
            [1, 3, 2, 5, 4, 7, 9, 8]
                h = 2/2 = 1  # insert_sort
                (
                compare([1, 3]) => Não troca
                compare([3, 2]) => troca
                compare([3, 5]) => Não troca
                compare([5, 4]) => troca
                compare([5, 7]) => Não troca
                compare([7, 9]) => Não troca
                compare([9, 8]) => troca
                )
                [1, 2, 3, 4, 5, 7, 8, 9]
    */
    printf("Rodando SHELL_SORT...");

    int i, j, aux, h;

    for (h=n/2; h>0; h/=2){
        // printf("\nValor de H: %d\n", h);
        for(i=h; i<n; i++){
            j = i;

            while((j >= h) && (vetor[j] < vetor[j-h])){
                aux = vetor[j];
                vetor[j] = vetor[j-h];
                vetor[j-h] = aux;
                j -= h;
            }
        }
    }

    return vetor;
}