#include <stdlib.h>
#include <stdio.h>

unsigned int collatzLength(unsigned long n)
{
    unsigned int count = 1;

    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        ++count;
    }

    return count;
}

int main(void)
{
    unsigned int maxCount = 0, maxN = 0;
    for (unsigned int i = 1; i < 1e6; ++i)
    {
        const unsigned int length = collatzLength(i);
        if (length > maxCount)
        {
            maxCount = length;
            maxN = i;
        }
    }
    printf("%d\n", maxN);

    return 0;
}
