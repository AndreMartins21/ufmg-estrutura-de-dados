#ifndef ALG_ORDENACAO
#define ALG_ORDENACAO

#include <stdio.h>
#include "ord_indireta.h"


int partition_quick_sort(int *indices, int low, int high, OrdInd_ptr poi, int atrib_id);
void quick_sort(int *indices, int low, int high, OrdInd_ptr poi, int atrib_id);
void merge_sort(int *indices, int left, int right, OrdInd_ptr poi, int atrib_id);
void merge(int *indices, int left, int mid, int right, OrdInd_ptr poi, int atrib_id);
void insertion_sort(int *indices, int n, OrdInd_ptr poi, int atrib_id);

#endif 