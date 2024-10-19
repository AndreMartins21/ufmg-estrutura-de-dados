#include <stdio.h>
#include <stdlib.h>
#include "../include/mat.h"
#include <time.h>


Matriz* criar_matriz(int linhas, int colunas){
    Matriz* m = (Matriz*) malloc(sizeof(Matriz));
    
    m->n_linhas = linhas;
    m->n_colunas = colunas;

    m->dados = (int**) malloc(linhas*sizeof(int*));

    for (int i = 0; i < linhas; i++){
        m->dados[i] = (int*) malloc(colunas * sizeof(int));
    }

    return m;
}


void destruir_matriz(Matriz* m){
    for (int i = 0; i < m->n_linhas; i++){
        free(m->dados[i]);
    }

    free(m->dados);
    free(m);
}

void inserir_valor_na_matriz(Matriz* m, int linha, int coluna, int valor){
    linha --;
    coluna --;
    if (
        linha >= 0 && linha < m->n_linhas && 
        coluna >= 0 && coluna < m->n_colunas
    ){
        m->dados[linha][coluna] = valor;
    } else {
        printf("Index (%i, %i) fora dos limites da matriz (%ix%i)", linha, coluna, m->n_linhas, m->n_colunas);
    }
}

void preencher_matriz_com_valores_aleatorios(Matriz* m, int n_max){
    for(int l = 0; l < m->n_linhas; l++){
        for(int c = 0; c < m->n_colunas; c++){
            m->dados[l][c] = rand() % (n_max+1);
        }
    }
}

void exibir_matriz(Matriz* m){
    printf("\n");
    for(int l = 0; l < m->n_linhas; l++){
        for(int c = 0; c < m->n_colunas; c++){
            printf("[ %d ]  ", m->dados[l][c]);
        }
        printf("\n");
    }
}

Matriz* somar_matrizes(Matriz matriz_a, Matriz matriz_b){
    // Garantindo que as matrizes tenham a mesma dimensão (n_linhas x n_colunas)
    if (
        (matriz_a.n_colunas != matriz_b.n_colunas) ||
        (matriz_a.n_linhas != matriz_b.n_linhas)
    ){
        printf("As matrizes tem que ter a mesma dimensão (n_linhas x n_colunas)!");
        return NULL;
    } 

    Matriz* matriz_soma = criar_matriz(matriz_a.n_linhas, matriz_a.n_colunas);

    for (int l = 0; l < matriz_a.n_linhas; l++){
        for (int c = 0; c < matriz_a.n_colunas; c++){
            matriz_soma->dados[l][c] = matriz_a.dados[l][c] + matriz_b.dados[l][c];
        }
    }

    return matriz_soma;
}

Matriz* multiplicar_matrizes(Matriz matriz_a, Matriz matriz_b){
    // Para multiplicar duas matrizes, o num de colunas da matriz_a tem que ser igual ao num de linhas da matriz B
    if ((matriz_a.n_colunas != matriz_b.n_linhas)){
        printf("O n_colunas da primeira matriz tem que ser igual ao n_linhas da segunda matriz!");
        return NULL;
    } 

    Matriz* matriz_produto = criar_matriz(matriz_a.n_linhas, matriz_b.n_colunas);

    for (int l = 0; l < matriz_produto->n_linhas; l++){
        for (int c = 0; c < matriz_produto->n_colunas; c++){
            for(int aux = 0; aux < matriz_a.n_colunas; aux++){
                matriz_produto->dados[l][c] += matriz_a.dados[l][aux] * matriz_b.dados[aux][c];
            }
        }
    }

    return matriz_produto;
}

Matriz* transpor_matriz(Matriz m){
    Matriz* m_transposta = criar_matriz(m.n_colunas, m.n_linhas);

    for (int l = 0; l < m.n_linhas; l++){
        for (int c = 0; c < m.n_colunas; c++){
            m_transposta->dados[c][l] = m.dados[l][c];
        }
    }

    return m_transposta;
}

int main(){
    srand(time(NULL));

    Matriz* m1 = criar_matriz(3, 2);
    Matriz* m2 = criar_matriz(2, 3);

    preencher_matriz_com_valores_aleatorios(m1, 10);
    preencher_matriz_com_valores_aleatorios(m2, 10);

    exibir_matriz(m1);
    exibir_matriz(m2);
    // Matriz* matriz_soma = somar_matrizes(*m1, *m2);
    Matriz* matriz_produto = multiplicar_matrizes(*m1, *m2);
    exibir_matriz(matriz_produto);

    Matriz* m_transposta = transpor_matriz(*matriz_produto);
    exibir_matriz(m_transposta);
}
