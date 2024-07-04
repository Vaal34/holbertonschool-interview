#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int *left, int left_size, int *right, int right_size);
void merge_sort(int *array, size_t size);
void print_array(int *array, size_t size);

int main(void)
{
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original array:\n");
    print_array(array, n);

    merge_sort(array, n);

    printf("Sorted array:\n");
    print_array(array, n);

    return 0;
}

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
    size_t mid, i;
    int *left, *right;
    size_t left_size, right_size;

    if (size < 2)
        return;

    mid = size / 2;
    left_size = mid;
    right_size = size - mid;

    left = malloc(left_size * sizeof(int));
    right = malloc(right_size * sizeof(int));

    if (!left || !right) {
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

void print_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
