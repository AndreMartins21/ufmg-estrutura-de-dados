#include <iostream>
#include "heap.hpp"


int main() {
    int n;
    std::cin >> n;

    Heap heap(n);

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        heap.Inserir(x);
    }

    while (!heap.Vazio()) {
        std::cout << heap.Remover() << " ";
    }
    std::cout << std::endl;

    return 0;
}
