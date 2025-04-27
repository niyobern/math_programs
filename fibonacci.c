#include <stdio.h>
#include <stdlib.h>

#define MAX_FIB 100

long long fib_cache[MAX_FIB];

void init_cache() {
    for (int i = 0; i < MAX_FIB; i++) {
        fib_cache[i] = -1;
    }
    // Base cases
    fib_cache[0] = 0;
    fib_cache[1] = 1;
}

long long fibonacci(int n) {
    if (n < 0) {
        printf("Invalid input: n must be non-negative\n");
        return -1;
    }
    
    if (n >= MAX_FIB) {
        printf("Input too large: maximum supported value is %d\n", MAX_FIB - 1);
        return -1;
    }

    // If value is already computed, return it
    if (fib_cache[n] != -1) {
        return fib_cache[n];
    }

    fib_cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib_cache[n];
}

int main() {
    int n;
    init_cache();

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    long long result = fibonacci(n);
    if (result != -1) {
        printf("The %d-th Fibonacci number is: %lld\n", n, result);
    }

    return 0;
} 