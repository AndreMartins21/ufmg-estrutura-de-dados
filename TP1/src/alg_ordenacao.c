#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alg_ordenacao.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare_records(int indexA, int indexB, OrdInd_ptr poi, int atrib_id) {
    char *recordA = strdup(poi->records[indexA]);
    char *recordB = strdup(poi->records[indexB]);

    char *campoA = strtok(recordA, ",");
    char *campoB = strtok(recordB, ",");

    for (int i = 0; i < atrib_id; i++) {
        campoA = strtok(NULL, ",");
        campoB = strtok(NULL, ",");
    }

    int result = strcmp(campoA, campoB);

    free(recordA);
    free(recordB);

    return result;
}


int partition_quick_sort(int *indices, int low, int high, OrdInd_ptr poi, int atrib_id) {
    int pivot = indices[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare_records(indices[j], pivot, poi, atrib_id) < 0) {
            i++;
            swap(&indices[i], &indices[j]);
        }
    }
    swap(&indices[i + 1], &indices[high]);
    return i + 1;
}

void quick_sort(int *indices, int low, int high, OrdInd_ptr poi, int atrib_id) {
    if (low < high) {
        int pivot = partition_quick_sort(indices, low, high, poi, atrib_id);
        quick_sort(indices, low, pivot - 1, poi, atrib_id);
        quick_sort(indices, pivot + 1, high, poi, atrib_id);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void insertion_sort(int *indices, int n, OrdInd_ptr poi, int atrib_id) {
    for (int i = 1; i < n; i++) {
        int key = indices[i];
        int j = i - 1;

        while (j >= 0 && compare_records(indices[j], key, poi, atrib_id) > 0) {
            indices[j + 1] = indices[j];
            j--;
        }
        indices[j + 1] = key;
    }
}


void merge_sort(int *indices, int left, int right, OrdInd_ptr poi, int atrib_id) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(indices, left, mid, poi, atrib_id);
        merge_sort(indices, mid + 1, right, poi, atrib_id);
        merge(indices, left, mid, right, poi, atrib_id);
    }
}

void merge(int *indices, int left, int mid, int right, OrdInd_ptr poi, int atrib_id) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = indices[left + i];
    for (int i = 0; i < n2; i++) R[i] = indices[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare_records(L[i], R[j], poi, atrib_id) <= 0) {
            indices[k++] = L[i++];
        } else {
            indices[k++] = R[j++];
        }
    }

    while (i < n1) indices[k++] = L[i++];
    while (j < n2) indices[k++] = R[j++];

    free(L);
    free(R);
}