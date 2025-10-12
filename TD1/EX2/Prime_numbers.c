#include<stdio.h>
#include<stdbool.h>
#include "Prime_numbers.h"

int prime_numbers_naive(int n){
    if (n < 2) return 0;

    int s=0;
    for (int i=2 ; i<=n ; i++){
        int count = 0;
        for (int j=2 ; j<=i ; j++){
            if (i % j == 0){
                count++;
            }
        }
    if (count <= 1){
        s++;
    }
}
return s; }

int prime_numbers_sieve(int n) {
    if (n < 2) return 0;

    bool is_prime[n + 1];
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int s = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            s++;
        }
    }

    return s;
}
