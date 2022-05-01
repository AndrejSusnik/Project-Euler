#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long triangleNumber(int n)
{
    return n * (n + 1) / 2;
}

int getNumberOfDivisors(unsigned long num)
{
    const int maxFactor = floor(sqrt(num));
    int *primeFactors = (int *)calloc(maxFactor, sizeof(int));

    for (int i = 2; i < maxFactor; i++)
    {
        while (num % i == 0)
        {
            primeFactors[i]++;
            num /= i;
        }
    }

    int divisors = 1;
    for (int i = 0; i < maxFactor; i++)
    {
        if (primeFactors[i] > 0)
        {
            divisors *= (primeFactors[i] + 1);
        }
    }

    free(primeFactors);
    return divisors;
}

int main(void)
{
    int i;
    for (i = 0; getNumberOfDivisors(triangleNumber(i)) < 500; i++)
    {
    }
    printf("%ld\n", triangleNumber(i));
    return 0;
}
