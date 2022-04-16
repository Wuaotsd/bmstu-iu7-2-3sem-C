#include "print.h"

void print_matrix(int **data, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%-3d ", data[i][j]);
        printf("\n");
    }
}