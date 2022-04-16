#include "allocate.h"

int **allocate_matrix(int n, int m)
{
    int **data = malloc(n * sizeof(int *) + n * m * sizeof(int));
    if (!data)
        data = NULL;
    else
    {
        for (int i = 0; i < n; i++)
            data[i] = (int *)((char *) data + n * sizeof(int *) + i * m * sizeof(int));
    }

    return data;
}
void free_matrix(int ***data)
{
    free(*data);
    *data = NULL;
}
