#include <stdio.h>

int sumOfSquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i * i;
    }
    return sum;
}

int squareOfSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum * sum;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", squareOfSum(100) - sumOfSquares(100));
    return 0;
}
