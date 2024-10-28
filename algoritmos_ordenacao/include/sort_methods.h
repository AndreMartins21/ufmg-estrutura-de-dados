#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

int* bubble_sort(int *vetor, int n);
int* select_sort(int *vetor, int n);
int* insert_sort(int *vetor, int n);
int* shell_sort(int *vetor, int n);
int* merge_sort(int *vetor, int n);
void merge(int *vetor, int *left_array, int l_size, int *right_array, int r_size);

#endif // BUBBLE_SORT_H
