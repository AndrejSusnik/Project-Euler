#include <stdio.h>
#include <math.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

unsigned long lcm(const int* numbers, int len) {
    unsigned long lcm = 1;
    for (int i = 0; i < len; ++i) {
        lcm = lcm * numbers[i] / gcd(lcm, numbers[i]);
    }
    return lcm;
}

int main(int argc, char const *argv[])
{
    const int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    printf("%lu\n", lcm(numbers, 20));

    return 0;
}
