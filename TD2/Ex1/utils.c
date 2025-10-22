#include "utils.h"

bool is_sorted_nondecreasing(int *arr, int n)
{
    if (n <= 1) return true;        // 0 ou 1 élément : trié
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1])    // si un élément est plus grand que le suivant => non trié
            return false;
    }
    return true;
}
int min_int(int a, int b)
{
    if (a>=b) return b;
    else return a;
}