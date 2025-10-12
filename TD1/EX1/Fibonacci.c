#include <stdio.h>
#include "Fibonacci.h"

int Fibonacci_naive(int n){
    if (n==0 || n==1)
    {
        return n;
    }
    else
    {
        return Fibonacci_naive(n-1)+Fibonacci_naive(n-2) ;
    }
        
}

int Fibonacci_dynamic(int n, int DPFib[n+1]){
    if (n<=1){
        return n;
    }
    if (DPFib[n] != -1){
        return DPFib[n];
    }
    
    DPFib[n]= Fibonacci_dynamic(n-1,DPFib) + Fibonacci_dynamic(n-2,DPFib);
    return DPFib[n];
}