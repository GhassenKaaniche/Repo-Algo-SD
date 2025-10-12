#include<stdio.h>
#include<time.h>
#include "Fibonacci.h"

int main() {
    int n = 40;
    int DPFib[n + 1];

    for (int i = 0; i <= n; i++) {
        DPFib[i] = -1;
    }

    clock_t start_naive = clock();
    printf("Fibonacci(%d) = %d\n", n, Fibonacci_naive(n));
    clock_t end_naive = clock();

    double time_naive = (double)(end_naive - start_naive) / CLOCKS_PER_SEC;
    printf("Execution time (naive): %.6f seconds\n\n", time_naive);

    clock_t start_dynamic = clock();
    printf("Fibonacci(%d) = %d\n", n, Fibonacci_dynamic(n, DPFib));
    clock_t end_dynamic = clock();

    double time_dynamic = (double)(end_dynamic - start_dynamic) / CLOCKS_PER_SEC;
    printf("Execution time (dynamic): %.6f seconds\n", time_dynamic);
}
