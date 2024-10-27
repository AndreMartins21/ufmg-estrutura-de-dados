#include <stdio.h>
#include "../include/sort_methods.h"
#include "uteis.h"

int* insert_sort(int *vetor, int n){
    /*
    => N° de comparações: 
        - melhor caso: Itens já ordenados = C(n) = n-1 = O(n)
        - pior caso: Itens ordenados desc = (n² - n) / 2  [C(n) = O(n²)]
        
    => N° de movimentações/trocas: 
        - melhor caso: Nunca entrar no loop interno = C(n) = 2*(n-1) = O(n)
        - pior caso: Sempre entra no loop interno = 2*(n-1) + (n² - n) / 2  [C(n) = O(n²)]

    => É estável (não muda posições de valores que já estavam ordenadas)
        
    => Exemplo:
    [4, 3, 1]
        i = 1
        aux = 3
        j = 0
    [3, 4, 1]
        i = 2
        aux = 1
        j = 1
        [3, 1, 4]
            j = 0
            [1, 3, 4]
    */
    printf("Rodando INSERT_SORT...");

    int i, j, aux;

    for(i=1; i < n; i++){
        aux = vetor[i];
        j = i-1;

        while (
            (j >= 0) &&
            (aux < vetor[j])
        ){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
    return vetor;
}