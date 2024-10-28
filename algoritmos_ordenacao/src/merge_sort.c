#include <stdio.h>
#include "../include/sort_methods.h"
#include "uteis.h"
#include <stdlib.h>


int* merge_sort(int *vetor, int n){
    /*
    => Tempo de execução:  
        - Custo linear = n
        - Para n = 1, T(1) = 0
        - Para n>1:
            . Uma vez para n/2 elementos
            . Uma vez para n/2 elementos
        - Logo, T(n) = 2T(n/2) + n
        T(n) = O(nlog[n])
        
    => A maior desvantagem desse método é que requer espaço extra proporcional a n
        
    => É estável (Se os elementos são iguais, não há troca de ordem)

    => Exemplo:
    [7, 3, 5, 2]
        middle = 2
        left_array = [7, 3]
        right_array = [5, 2]
        {
            merge_sort(left_array, 2)
                middle = 1
                left_array = [7]
                right_array = [3]
                merge_sort(left_array, 1)
                merge_sort(right_array, 1)
                merge([7, 3, 5, 2], [7], 1, [3], 1)
                    vetor = [3, 7, 5, 2]
        }
        {
            merge_sort(right_array, 2)
                middle = 1
                left_array = [5]
                right_array = [2]
                merge_sort(left_array, 1)
                merge_sort(right_array, 1)
                merge([7, 3, 5, 2], [5], 1, [2], 1)
                    vetor = [7, 3, 2, 5]
        }

        => Depois disso, vamos voltar ao vetor com 4 elementos:
            middle = 2
            left_array = [3, 7]
            right_array = [2, 5]
            merge([3, 7, 2, 5], [3, 7], 2, [2, 5], 2)
                while(li < 2 && ri < 2):
                    [3, 7, 2, 5]
                    [2, 7, 3, 5]
                    [2, 3, 7, 5]
                while(ri < 2):
                    [2, 3, 5, 7]
    */
    
    if (n <= 1) return NULL;

    int middle = n / 2;
    int *left_array = (int*) malloc(middle*sizeof(int));
    int *right_array = (int*) malloc((n-middle)*sizeof(int));

    int i = 0, pos_right = 0;

    for(; i < n; i++){
        if(i < middle){
            left_array[i] = vetor[i];
        } else{
            right_array[pos_right] = vetor[i];
            pos_right++;

        }
    }

    merge_sort(left_array, middle);
    merge_sort(right_array, (n-middle));
    merge(vetor, left_array, middle, right_array, n-middle);

    return vetor;
}


void merge(int *vetor, int *left_array, int l_size, int *right_array, int r_size){
    int i = 0, li = 0, ri = 0;  // Indexes

    while (li < l_size && ri < r_size){
        if(left_array[li] < right_array[ri]){
            vetor[i] = left_array[li];
            li++;
        } else{
            vetor[i] = right_array[ri];
            ri++;
        }
        i++;
    }

    // Casos que sobrar. Ex:
    // quando preencheu a camada de cima com todos do left_array, restando preencher o right_array
    while (li < l_size){
        vetor[i] = left_array[li];
        i++;
        li++;
    }

    while (ri < r_size){
        vetor[i] = right_array[ri];
        i++;
        ri++;
    }
    
}
