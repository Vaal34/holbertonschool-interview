#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *left, int left_size, int *right, int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *array, size_t size)
{
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, left, mid, right, size - mid);

    free(left);
    free(right);
}