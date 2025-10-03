#include <stdio.h>
#include <stdlib.h>

long long recursive_factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * recursive_factorial(n - 1);
}

void compute_series(int n) {
    for (int i = 1; i <= n; i++) {
        long long result = recursive_factorial(i);
        printf("Factorial of %d: %lld\n", i, result);
    }
}

int main() {
    int input = 20; // Factorials up to 20
    printf("Computing factorial series up to %d:\n", input);
    compute_series(input);
    return 0;
}
