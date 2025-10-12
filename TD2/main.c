#include <stdio.h>
#include <time.h>
#include "Prime_numbers.h"

int main() {
    int n = 100000;
    clock_t start, end;
    double cpu_time_used;

    printf("Testing up to %d\n", n);

    start = clock();
    int naive_count = prime_numbers_naive(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("[Naive] There are %d prime numbers before %d (time: %.5f s)\n", naive_count, n, cpu_time_used);

    start = clock();
    int sieve_count = prime_numbers_sieve(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("[Sieve] There are %d prime numbers before %d (time: %.5f s)\n", sieve_count, n, cpu_time_used);

    return 0;
}
