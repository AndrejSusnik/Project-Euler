#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_perfect_square(int num)
{
    const int root = sqrt(num);
    return root * root == num;
}

int pythagorean(int a, int b)
{
    if(is_perfect_square(a * a + b * b))
    {
        return sqrt(a*a + b*b);
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    for(int i = 1; i < 500; ++i)
    {
        for(int j = 1; j < i; ++j){
            if(i + j + pythagorean(i, j) == 1000)
            {
                printf("%d\n", i * j * pythagorean(i, j));
                return 0;
            }

        }
    }

    return 0;
}
