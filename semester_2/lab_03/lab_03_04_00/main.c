#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define M 10

#define SIZE_ARR           1
#define ELEMENT_ERR        2
#define NUMBER_NOT_FIND    3
#define NOT_SQUARE_MATRIX  4

int input_matrix(int a[][M], size_t *n, size_t *m);

int find_min_odd(int a[][M], size_t n, size_t m, int *max);

int main(void)
{
    int matrix[N][M], min;
    size_t n, m;
    int rc = EXIT_SUCCESS;
    
    setbuf(stdout, NULL);
    
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        if (rc == ELEMENT_ERR)
            printf("Error! The element(s) of matrix is incorrect!");
        if (rc == NOT_SQUARE_MATRIX)
            printf("\nError! Matrix is not square!");
        return rc;
    }
    rc = find_min_odd(matrix, n, m, &min);
    if (rc == NUMBER_NOT_FIND)
        printf("Error! Not found number!");
    if (rc == EXIT_SUCCESS)
        printf("Min odd element of matrix under main diagonal: %d", min);
    return rc;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2 || *n > N || *m > M || *n <= 0 || *m <= 0)
        return SIZE_ARR;
    if (*n != *m)
        return NOT_SQUARE_MATRIX;
    printf("\nEnter elements of matrix:\n");
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ELEMENT_ERR;
    return EXIT_SUCCESS;
}

int find_min_odd(int a[][M], size_t n, size_t m, int *min)
{
    int rc = EXIT_SUCCESS;
    *min = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (i > j && a[i][j] % 2 != 0)
            {
                *min = a[i][j];
                break;
            }
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (i > j && a[i][j] % 2 != 0 && *min > a[i][j])
                *min = a[i][j];
    if (*min % 2 == 0)
        return NUMBER_NOT_FIND;
    return rc;
}
