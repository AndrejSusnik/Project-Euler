#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define SIZE 20

uint8_t **readNumbers(char *file_name)
{
    uint8_t **numbers = (uint8_t **)malloc(sizeof(uint8_t *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = (uint8_t *)malloc(sizeof(uint8_t) * SIZE);
    }

    FILE *numbers_file = fopen(file_name, "r");
    char buffer[1024];
    if (numbers_file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int i = 0, j = 0;
    while (!feof(numbers_file))
    {
        fgets(buffer, 1024, numbers_file);
        char *token = strtok(buffer, "\n");
        while (token != NULL)
        {
            char *number = strtok(token, " ");
            while (number != NULL)
            {
                numbers[i][j] = atoi(number);
                number = strtok(NULL, " ");
                ++j;
            }
            ++i;
            j = 0;
            token = strtok(NULL, "\n");
        }
    }

    fclose(numbers_file);
    return numbers;
}

unsigned long getProductAbove(uint8_t **numbers, int row, int col)
{
    unsigned long product = 1;
    for (int i = 0; i < 4; i++)
    {
        if (row - i >= 0)
        {
            product *= numbers[row - i][col];
        }
    }
    return product;
}

unsigned long getProductBelow(uint8_t **numbers, int row, int col)
{
    unsigned long product = 1;
    for (int i = 0; i < 4; i++)
    {
        if (row + i < SIZE)
        {
            product *= numbers[row + i][col];
        }
    }
    return product;
}

unsigned long getProductLeft(uint8_t **numbers, int row, int col)
{
    unsigned long product = 1;
    for (int i = 0; i < 4; i++)
    {
        if (col + i < SIZE)
        {
            product *= numbers[row][col + i];
        }
    }
    return product;
}

unsigned long getProductRight(uint8_t **numbers, int row, int col)
{
    unsigned long product = 1;
    for (int i = 0; i < 4; i++)
    {
        if (col - i >= 0)
        {
            product *= numbers[row][col - i];
        }
    }
    return product;
}

unsigned long getProductDiagonal(uint8_t **numbers, int row, int col)
{
    unsigned long product = 1;
    for (int i = 0; i < 4; i++)
    {
        if(row - i >= 0 && col + i < SIZE)
        {
            product *= numbers[row - i][col + i];
        }
    }
    return product;
}

unsigned long getProductOfAdjacentNumbers(uint8_t **numbers)
{
    unsigned long maxProduct = 1;

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int product = getProductAbove(numbers, i, j);
            if(product > maxProduct)
            {
                maxProduct = product;
            }
            product = getProductBelow(numbers, i, j);
            if(product > maxProduct)
            {
                maxProduct = product;
            }
            product = getProductLeft(numbers, i, j);
            if(product > maxProduct)
            {
                maxProduct = product;
            }
            product = getProductRight(numbers, i, j);
            if(product > maxProduct)
            {
                maxProduct = product;
            }
            product = getProductDiagonal(numbers, i, j);
            if(product > maxProduct)
            {
                maxProduct = product;
            }
        }
    }
    return maxProduct;
}

int main(int argc, char const *argv[])
{
    uint8_t **numbers = readNumbers("numbers.txt");
    printf("%lu\n", getProductOfAdjacentNumbers(numbers));
    return 0;
}
