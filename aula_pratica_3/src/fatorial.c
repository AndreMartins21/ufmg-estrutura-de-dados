#include <stdio.h>
#include <math.h>  


void consumir_recursos(){
    double x = 1.0;
    for (int i = 0; i < 1000000; i++) {
        sin(x);  // Calcular o seno repetidamente
    }
}

unsigned long long int fatorial_recursivo(int n){
    if (n<=0) return 1;
    consumir_recursos();

    return n*fatorial_recursivo(n-1);
}


unsigned long long int fatorial_iterativo(int n){
    int r = n;
    n--;
    while(n > 0){
        r*= n;
        n--;
    }

    return r;
}
