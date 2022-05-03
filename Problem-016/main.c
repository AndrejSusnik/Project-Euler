#include <gmp.h>
#include <string.h>
#include <stdio.h>

#define MAX_SIZE 1000 

int main(int argc, char const *argv[])
{
    mpz_t num;
    char str[MAX_SIZE];
    mpz_init2(num, MAX_SIZE);
    mpz_ui_pow_ui(num, 2, MAX_SIZE);
    mpz_get_str(str, 10, num);
    int sum = 0;
    for(int i = 0; i < strlen(str); i++)
    {
        sum += (int)(str[i] - '0');
    }
    printf("%d\n", sum);
    return 0;
}

