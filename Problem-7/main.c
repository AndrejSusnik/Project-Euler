#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num)
{
    if (num == 2)
    {
        return 1;
    }
    if (num % 2 == 0)
    {
        return 0;
    }
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

long nth_prime(int n)
{
    int count = 0;
    long num = 2;
    while (count < n)
    {
        if (is_prime(num))
        {
            count++;
        }
        num++;
    }
    return num - 1;
}
int main(int argc, char const *argv[])
{
    printf("%ld\n", nth_prime(10001));
    return 0;
}
