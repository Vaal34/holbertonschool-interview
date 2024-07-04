#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int *left, int left_size, int *right, int right_size);
void merge_sort(int *array, size_t size);
void print_array(int *array, size_t size);

#endif