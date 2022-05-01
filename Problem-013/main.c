#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS_LENGTH 50
#define NUM_DIGITS 100

char **readDigits()
{
    FILE *digits_file = fopen("digits.txt", "r");
    char **digits = (char **)malloc(sizeof(char *) * NUM_DIGITS);
    for (int i = 0; i <  NUM_DIGITS; ++i)
    {
        digits[i] = (char *)malloc(sizeof(char) * DIGITS_LENGTH);
    }

    char buffer[1024];
    int i = 0; 
    while (!feof(digits_file))
    {
        fgets(buffer, 1024, digits_file);
        if(buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        strcpy(digits[i++], buffer);
    }

    fclose(digits_file);
    return digits;
}

int main(void)
{
    char **digits = readDigits();
    char result[10];
    int carry = 0;

    for(int i = DIGITS_LENGTH - 1; i >= 0; --i) {
        int sum = carry;
        for(int j = 0; j < NUM_DIGITS; ++j)
        {
            sum += (int)(digits[j][i] - '0');
        }
        carry = sum / 10;
        if(i < 10)
        {
            result[i] = sum % 10 + '0';
        }
    }

    printf("%s\n", result);
    printf("%d\n", carry); 
    // Result is carry and digits in result 
    free(digits);
    return 0;
}
