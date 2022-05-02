#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 20
#define EDGES_SIZE (GRID_SIZE + 1)
unsigned long *cache;
unsigned long solve(int x, int y)
{
    if (x == GRID_SIZE && y == GRID_SIZE)
    {
        return 1;
    }

    unsigned long total = 0;
    if (x < GRID_SIZE)
    {
        const int nextIdx = (x + 1) * EDGES_SIZE + y;
        if (cache[nextIdx] == 0)
        {
            cache[nextIdx] = solve(x + 1, y);
        }
        total += cache[nextIdx];
    }
    if (y < GRID_SIZE)
    {
        const int nextIdx = x * EDGES_SIZE + y + 1;
        if (cache[nextIdx] == 0)
        {
            cache[nextIdx] = solve(x, y + 1);
        }
        total += cache[nextIdx];
    }

    return total;
}

int main(void)
{
    cache = (unsigned long *)calloc(EDGES_SIZE * EDGES_SIZE, sizeof(unsigned long));
    for (int i = 0; i < EDGES_SIZE * EDGES_SIZE; ++i)
    {
        cache[i] = 0;
    }

    printf("%ld\n", solve(0, 0));
    free(cache);
    return 0;
}
