#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/fatorial.h"
#include "../include/fibonacci.h"


int parse_input(int argc, char *argv[], int *n, char **task, char **method) {
    if (argc != 4) {
        printf("Uso: %s <número> <tarefa> <método>\n", argv[0]);
        printf("Tarefa: 'fibonacci' ou 'fatorial'\n");
        printf("Método: 'recursive' para recursivo ou 'iterative' para iterativo\n");
        return 0;
    }

    *n = atoi(argv[1]);
    *task = argv[2];
    *method = argv[3];
    return 1;
}


int main(int argc, char *argv[]) {
    int n;
    unsigned long long int result;
    char *task, *method;
    clock_t start, end;

    // Parseando os argumentos de entrada
    if (!parse_input(argc, argv, &n, &task, &method)) {
        return 1;
    }

    // Medindo o tempo de execução
    start = clock();

    if (strcmp(task, "fibonacci") == 0) {
        if (strcmp(method, "recursive") == 0) {
            result = fibonacci_recursivo(n);
        } else if (strcmp(method, "iterative") == 0) {
            result = fibonacci_iterativo(n);
        } else {
            printf("Método inválido para a Sequência Fibonacci. Use 'recursive' ou 'iterative'.\n");
            return 1;
        }
    } else if (strcmp(task, "fatorial") == 0) {
        if (strcmp(method, "recursive") == 0) {
            result = fatorial_recursivo(n);
        } else if (strcmp(method, "iterative") == 0) {
            result = fatorial_iterativo(n);
        } else {
            printf("Método inválido para Fatorial. Use 'recursive' ou 'iterative'.\n");
            return 1;
        }
    } else {
        printf("Método inexistente. Tente: 'fibonacci' ou 'fatorial'.\n");
        return 1;
    }

    end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s de %d usando %s: %lli\n", task, n, method, result);
    printf("Tempo de execução: %.6f segundos\n", elapsed_time);

    return 0;
}