#ifndef MATRIZ_H
#define MATRIZ_H


typedef struct {
    int **dados;
    int n_linhas;
    int n_colunas;
} Matriz;


Matriz* criar_matriz(int linhas, int colunas);
void preencher_matriz_com_valores_aleatorios(Matriz* m, int n_max);
void destruir_matriz(Matriz* m);
void inserir_valor_na_matriz(Matriz* m, int linha, int coluna, int valor);

void exibir_matriz(Matriz* m);

Matriz* somar_matrizes(Matriz matriz_a, Matriz matriz_b);
Matriz* multiplicar_matrizes(Matriz matriz_a, Matriz matriz_b);
Matriz* transpor_matriz(Matriz m)

#endif // MATRIZ_H