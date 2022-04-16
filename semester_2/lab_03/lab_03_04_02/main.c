#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define M 10
#define NUMBER_NOT_FIND -3
#define NOT_SQUARE_MATRIX -2

int input_matrix(int a[][M], size_t *n, size_t *m);

int find_max_finishfive(int a[][M], size_t n, size_t m, int *max);

int main(void)
{
    int matrix[N][M], max;
    size_t n, m;
    int rc = EXIT_SUCCESS;
    
    setbuf(stdout, NULL);
    
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc = find_max_finishfive(matrix, n, m, &max);
    if (rc == NUMBER_NOT_FIND)
        printf("Error! Not found number!");
    if (rc == EXIT_SUCCESS)
        printf("Max element of matrix end on five: %d", max);
    return rc;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
    int rc = EXIT_SUCCESS;
    
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2)
    {
        printf("\nError! The size of matrix is incorrect!");
        return EXIT_FAILURE;
    }   
    if (!(0 < *n && *n <= N) || !(0 < *m && *m <= M))
    {
        printf("\nError! The size of matrix is incorrect!");
        return EXIT_FAILURE;
    }
    if (*n != *m)
    {
        printf("\nError! Matrix is not square!");
        return NOT_SQUARE_MATRIX;
    }
    printf("\nEnter elements of matrix:\n");
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Error! The element(s) of matrix is incorrect!");
                rc = EXIT_FAILURE;
                break;
            }
        if (rc == EXIT_FAILURE)
            break;
    }
    return rc;
}

int find_max_finishfive(int a[][M], size_t n, size_t m, int *max)
{
    int rc = EXIT_SUCCESS;
    *max = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (*max % 10 == 5)
            {
                if (i + j > n - 1 && abs(a[i][j]) % 10 == 5 && a[i][j] > *max)
                    *max = a[i][j];
            }
            else if (i + j > n - 1 && abs(a[i][j]) % 10 == 5)
                *max = a[i][j];
        }
    if (abs(*max) % 10 != 5)
        return NUMBER_NOT_FIND;
    return rc;
}
