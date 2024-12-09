#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ord_indireta.h"
#include "alg_ordenacao.h"


OrdInd_ptr Cria() {
    OrdInd_ptr poi = (OrdInd_ptr) malloc(sizeof(OrdInd_t));
    poi->records = NULL;
    poi->indices = NULL;
    poi->attributes = NULL;
    poi->num_records = 0;
    poi->num_attributes = 0;
    return poi;
}

int Destroi(OrdInd_ptr poi) {
    // Irá liberar a memória de todos os atributos da struct criada
    if (poi->records) {
        for (int i = 0; i < poi->num_records; i++) {
            free(poi->records[i]);
        }
        free(poi->records);
    }
    if (poi->indices) {
        free(poi->indices);
    }
    if (poi->attributes) {
        for (int i = 0; i < poi->num_attributes; i++) {
            free(poi->attributes[i]);
        }
        free(poi->attributes);
    }
    free(poi);
    return 0;
}

int CarregaArquivo(OrdInd_ptr poi, char *nomeentrada) {
    FILE *file = fopen(nomeentrada, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo .xcsv");
        return -1;
    }

    fscanf(file, "%d\n", &poi->num_attributes);

    poi->attributes = (char**) malloc(poi->num_attributes * sizeof(char*));
    char buffer[1024];
    for (int i = 0; i < poi->num_attributes; i++) {
        /*
        PS: 
        -  Vamos desconsiderar, por ora, o tipo de dado, considerando todas os campos como string. 
            Para o propósito do trabalho, não vejo sentido em nos preocuparmos se será string (s) ou inteiro (i), por exemplo;
        - Usei um esquema de regex para conseguir separar o nome do atributo do tipo dele, que estão separados por vírgula;
        */
        fscanf(file, "%[^,],%*s\n", buffer);
        poi->attributes[i] = strdup(buffer);
    }

    fscanf(file, "%d\n", &poi->num_records);

    poi->records = (char**) malloc(poi->num_records * sizeof(char*));
    for (int i = 0; i < poi->num_records; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remover quebra de linhas (\n), substituindo-o pelo carácter nulo (\0)
        poi->records[i] = strdup(buffer);
    }
    
    fclose(file);
    return 0;
}



int NumAtributos(OrdInd_ptr poi) {
    return poi->num_attributes;
}


int NomeAtributo(OrdInd_ptr poi, int pos, char *nome) {
    if (pos < 0 || pos >= poi->num_attributes) {
        printf("Índice '%d' inválido!", pos);
        return -1; 
    }
    // printf("\nAtributo = %s", poi->attributes[pos]);
    strcpy(nome, poi->attributes[pos]);
    return 0;
}


int CriaIndice(OrdInd_ptr poi, int atrib_id) {
    if (atrib_id < 0 || atrib_id >= poi->num_attributes) {
        printf("Índice '%d' inválido!", atrib_id);
        return -1; 
    }
    poi->indices = (int*) malloc(poi->num_records * sizeof(int));
    for (int i = 0; i < poi->num_records; i++) {
        poi->indices[i] = i;
    }
    return 0;
}

int OrdenaIndice(OrdInd_ptr poi, int atrib_id, int id_algorithm) {
    if (atrib_id < 0 || atrib_id >= poi->num_attributes) {
        printf("Índice '%d' inválido!", atrib_id);
        return -1; 
    }

    int n = poi->num_records;

    switch (id_algorithm) {
        case 1: // quick_sort
            quick_sort(poi->indices, 0, n - 1, poi, atrib_id);
            break;
        case 2: // MergeSort
            merge_sort(poi->indices, 0, n - 1, poi, atrib_id);
            break;
        case 3: // InsertionSort
            insertion_sort(poi->indices, n, poi, atrib_id);
            break;
        default:
            return -1; // Algoritmo inválido
    }

    return 0;
}


int ImprimeOrdenadoIndice(OrdInd_ptr poi, int atrib_id) {
    for (int i = 0; i < poi->num_records; i++) {
        printf("%s\n", poi->records[poi->indices[i]]);
    }
    return 0;
}