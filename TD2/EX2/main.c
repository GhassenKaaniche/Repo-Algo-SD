#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    int n = 10000;
    int *arr = malloc(n * sizeof(int));
    int *tmp = malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;

    clock_t start, end;
    double time_used;

    copy_array(arr, tmp, n);
    start = clock();
    selection_sort(tmp, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection sort: %.6f s\n", time_used);

    copy_array(arr, tmp, n);
    start = clock();
    insertion_sort(tmp, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion sort: %.6f s\n", time_used);

    copy_array(arr, tmp, n);
    start = clock();
    bubble_sort(tmp, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble sort: %.6f s\n", time_used);

    copy_array(arr, tmp, n);
    start = clock();
    merge_sort(tmp, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge sort: %.6f s\n", time_used);

    copy_array(arr, tmp, n);
    start = clock();
    quick_sort(tmp, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick sort: %.6f s\n", time_used);

    free(arr);
    free(tmp);
    return 0;
}
