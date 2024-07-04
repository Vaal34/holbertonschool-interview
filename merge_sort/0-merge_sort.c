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
    int mid, i;
    int *left, *right;
    size_t left_size, right_size;

    if (size < 2)
        return;

    mid = size / 2;
    left_size = mid;
    right_size = size - mid;

    left = malloc(left_size * sizeof(int));
    right = malloc(right_size * sizeof(int));

    /* Ensure malloc succeeded */
    if (!left || !right) {
        /* Handle memory allocation failure */
        free(left);
        free(right);
        return;
    }

    for (i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    merge(array, left, left_size, right, right_size);

    free(left);
    free(right);
}