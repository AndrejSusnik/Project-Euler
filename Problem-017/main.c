#include <math.h>
#include <stdio.h>
#include <string.h>

static const char *map[] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"};

int intToString(int number)
{
    const int nums = floor(log10(number));
    int count = 0;
    for (int i = nums; i >= 0; i--)
    {
        const int digit = number / pow(10, i);
        switch (i)
        {
        case 3:
            if (digit == 0)
                continue;
            count += strlen(map[digit - 1]) + strlen("thousand");
            break;
        case 2:
            if (digit == 0)
                continue;
            count += strlen(map[digit - 1]) + strlen("hundred");
            if (number - digit * pow(10, i) != 0)
            {
                count += strlen("and");
            }
            break;
        case 1:
            if (digit == 0)
                continue;
            if (number >= 10 && number <= 19)
            {
                count += strlen(map[number - 1]);
                return count;
            }
            count += strlen(map[digit + 17]);
            break;
        case 0:
            if (digit == 0)
                continue;
            count += strlen(map[digit - 1]);
            break;
        default:
            break;
        }
        number -= digit * pow(10, i);
    }

    return count;
}

int main(void)
{
    int count = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        count += intToString(i);
    }
    printf("%d\n", count);
    return 0;
}
