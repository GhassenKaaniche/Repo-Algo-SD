#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int n = 25;
    int target = 17;

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = 2 * i + 1;
    }

    printf("Tableau : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Vérifier si le tableau est trié
    if (is_sorted_nondecreasing(arr, n)) {
        printf("Le tableau est trie dans l'ordre croissant.\n");
    } else {
        printf("Le tableau n'est pas trie.\n");
    }

    
    clock_t start, end;
    double cpu_time_used;
    int position;

    
    start = clock();
    position = linear_search(arr, n, target);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Linear Search: l'element %d se trouve a la position %d (temps = %.6f s)\n", target, position, cpu_time_used);


    start = clock();
    position = jump_search(arr, n, target);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Jump Search: l'element %d trouve a la position %d (temps = %.6f s)\n", target, position, cpu_time_used);
    

    start = clock();
    position = binary_search(arr, n, target);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search: l'element %d se trouve a la position %d (temps = %.6f s)\n", target, position, cpu_time_used);

    free(arr);

    return 0;
}
