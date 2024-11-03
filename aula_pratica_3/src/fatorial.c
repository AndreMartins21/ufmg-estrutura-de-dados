#include <stdio.h>


unsigned long long int fatorial_recursivo(int n){
    if (n<=0) return 1;

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