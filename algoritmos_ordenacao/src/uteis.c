#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/uteis.h"

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}


void print_vetor(int* vetor, int n){
    printf("\n");
    for (int i = 0; i<n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int get_random_number(int min_v, int max_v){
    return min_v + rand() % (max_v - min_v + 1);
}

int* criar_vetor_aleatorio(int len_vetor, int min_v, int max_v){
    srand(time(NULL));

    int i;
    int *vetor = (int*) malloc(sizeof(int)*len_vetor);

    for (i=0; i < len_vetor; i++){
        vetor[i] = get_random_number(min_v, max_v);
    }

    return vetor;
}