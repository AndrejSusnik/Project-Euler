#include <stdio.h>

int main()
{
    long x = 1, prevX = 0, sum = 0;
    while (x < 4e6)
    {
        const long tmp = x;
        x = x + prevX;

        prevX = tmp;
        if (x % 2 == 0)
            sum += x;
    }
    printf("Sum of all even terms of Fibonacci sequence below 4 million is %ld\n", sum);
    return 0;
}
