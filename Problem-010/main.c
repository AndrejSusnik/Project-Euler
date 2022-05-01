#include <stdio.h>
#include <stdlib.h>

unsigned int* primeSieve(int n) {
    unsigned int* primes = (unsigned int*)malloc(sizeof(unsigned int) * n);
    int i, j;
    for (i = 2; i < n; i++) {
        primes[i] = 1;
    }
    for (i = 2; i < n; i++) {
        if (primes[i]) {
            for (j = i + i; j < n; j += i) {
                primes[j] = 0;
            }
        }
    }
    return primes;
}

unsigned long sumPrimes(int* primes, int n) {
    unsigned long sum = 0;
    for (int i = 2; i < n; i++) {
        if (primes[i]) {
            sum += i;
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%lu\n", sumPrimes(primeSieve(2000000), 2000000));
}
