#include <string.h>
#include "../include/alg_ordenacao.h"


int main(int argc, char ** argv){
    char nome_atrib_aux[100];
    OrdInd_ptr poi = Cria();
    int id_algoritmo_ordenacao = 2;  // 1: quick_sort | 2: merge_sort | 3: insert_sort
    CarregaArquivo(poi, "/home/andrew/Documents/Facul/ESTRUTURA_DE_DADOS/ufmg-estrutura-de-dados/TP1/files/input.xcsv");

    int numatrib = NumAtributos(poi);
    printf("num_atrib = %d\n", numatrib);
    for (int i = 0; i<numatrib; i++){
        if (NomeAtributo(poi, i, nome_atrib_aux) == 0){
            if (!strcmp(nome_atrib_aux,"Nome")||!strcmp(nome_atrib_aux,"CPF")||!strcmp(nome_atrib_aux,"End")){
                CriaIndice(poi,i);
                OrdenaIndice(poi,i, id_algoritmo_ordenacao); 
                ImprimeOrdenadoIndice(poi,i);
            }
        }
    }
    Destroi(poi);
}