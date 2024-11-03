unsigned long long int fibonacci_recursivo(int posicao){
    if (posicao <= 1) return 1;

    return fibonacci_recursivo(posicao-1) + fibonacci_recursivo(posicao-2);
}


unsigned long long int fibonacci_iterativo(int posicao){
    int i, aux, v0 = 1, v1 = 1;

    for (i=1; i < posicao; i++){
        aux = v0;
        v0 = v1;
        v1 += aux;
    }

    return v1;
}