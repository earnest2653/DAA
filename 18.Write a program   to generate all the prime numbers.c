#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int limit) {
    bool primes[limit + 1];
    for (int i = 0; i <= limit; i++) {
        primes[i] = true;
    }

    for (int p = 2; p * p <= limit; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i <= limit; i += p) {
                primes[i] = false;
            }
        }
    }

    printf("Prime numbers up to %d:\n", limit);
    for (int p = 2; p <= limit; p++) {
        if (primes[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int limit;

    printf("Enter the limit: ");
    scanf("%d", &limit);

    sieveOfEratosthenes(limit);

    return 0;
}
