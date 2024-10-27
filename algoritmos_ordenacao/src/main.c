#include <stdio.h>
#include "../include/sort_methods.h"
#include "../include/uteis.h"


int main(){
    int n = 15;
    int *vetor = criar_vetor_aleatorio(n, 1, 10);

    print_vetor(vetor, n);
    // int* ordenado = bubble_sort(vetor, n);
    // int* ordenado = select_sort(vetor, n);
    int* ordenado = insert_sort(vetor, n);

    print_vetor(ordenado, n);

    return 1;
}