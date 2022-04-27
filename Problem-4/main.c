#include <stdio.h>
#include <math.h>

// Checks if a number is plaindrome
int is_palindrome(int num) {
    int temp = num;
    int rev = 0;
    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == num;

}

int main()
{
    const int limit = 1000;
    int largest = 0;
    for (int i = 100; i < limit; ++i)
    {
        for (int j = 100; j < limit; ++j)
        {
            const int num = i * j;
            if (is_palindrome(num))
            {
                largest = largest < num ? num : largest;
            }
        }
    }

    printf("Largest palindrom is %d\n", largest);
    return 0;
}
