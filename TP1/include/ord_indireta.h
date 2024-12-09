#ifndef ORD_INDIRETA
#define ORD_INDIRETA


typedef struct OrdInd{
    char **records;  
    int *indices;    // Vetor de índices para ordenação indireta
    char **attributes;
    int num_records; 
    int num_attributes; // Número de atributos POR registro
} OrdInd_t, *OrdInd_ptr;


OrdInd_ptr Cria();

int Destroi (OrdInd_ptr poi);
int CarregaArquivo(OrdInd_ptr poi, char * nome_entrada);
int NumAtributos(OrdInd_ptr poi);
int NomeAtributo(OrdInd_ptr poi, int pos, char * nome);
int CriaIndice(OrdInd_ptr poi, int atrib_id);
int OrdenaIndice(OrdInd_ptr poi, int atrib_id, int id_algorithm);
int ImprimeOrdenadoIndice(OrdInd_ptr poi, int atrib_id);

#endif 