#include <stdio.h>
#include <math.h>

int is_prime(long number)
{
    for (int i = 2; i < sqrtl(number); ++i)
    {
        if (i != number && number % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    long number = 600851475143;
    long largest_prime = 1;
    while (number != 1)
    {
        for (long i = 2; i < sqrtl(number); ++i)
        {
            if (is_prime(i) && number % i == 0)
            {
                number = number / i;
                if (i > largest_prime)
                    largest_prime = i;

                break;
            }
            else if(is_prime(number)) {

                if (number > largest_prime)
                    largest_prime = number;
                number = 1;
            }
        }
    }
    printf("Largest prime facto is %ld\n", largest_prime);
    return 0;
}
