#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int qtd_elementos = 10;
  int a[qtd_elementos];
  for (i = 0; i < qtd_elementos-1; i++)
    a[i] = i;
    
  for (i = 0; i < qtd_elementos-1; i++){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}