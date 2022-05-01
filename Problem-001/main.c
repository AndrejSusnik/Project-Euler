#include <stdio.h>


int main(void)
{
    int sum = 0;
    for(int i = 0; i < 1000; ++i) {
        if(i % 3 == 0 || i % 5 == 0) 
            sum += i;
    }
    printf("Sum of all multiples of 3 or 5 below 1000 is %d\n", sum);
    return 0;
}
