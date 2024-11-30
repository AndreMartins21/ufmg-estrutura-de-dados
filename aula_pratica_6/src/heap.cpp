#include "heap.hpp"
#include <iostream>


void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


Heap::Heap(int maxsize) : tamanho(0), data(new int[maxsize]) {}

Heap::~Heap() {
    delete[] this->data;
}

bool Heap::Vazio() {
    return this->tamanho == 0;
}

int Heap::GetAncestral(int posicao){
    return (posicao - 1) / 2;
}


int Heap::GetSucessorDir(int posicao){
    return 2*posicao + 2;
}

int Heap::GetSucessorEsq(int posicao){
    return 2*posicao + 1;
}

void Heap::HeapifyPorCima(int posicao) {
    while (posicao > 0 && this->data[posicao] < this->data[GetAncestral(posicao)]) {
        swap(&this->data[posicao], &this->data[GetAncestral(posicao)]);
        posicao = GetAncestral(posicao);
    }
}

void Heap::HeapifyPorBaixo(int posicao) {
    int menor = posicao;
    int esq = GetSucessorEsq(posicao);
    int dir = GetSucessorDir(posicao);

    if (esq < this->tamanho && this->data[esq] < this->data[menor])
        menor = esq;

    if (dir < this->tamanho && this->data[dir] < this->data[menor])
        menor = dir;

    if (menor != posicao) {
        swap(&this->data[posicao], &this->data[menor]);
        HeapifyPorBaixo(menor);
    }
}

void Heap::Inserir(int x) {
    this->data[this->tamanho++] = x;
    HeapifyPorCima(this->tamanho - 1);
}

int Heap::Remover() {
    if (Vazio()) {
        std::cout << "\nVazio!\n";
    }
    int menor = data[0];
    data[0] = data[--tamanho];
    HeapifyPorBaixo(0);
    return menor;
}