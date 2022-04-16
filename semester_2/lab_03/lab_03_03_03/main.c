#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10

#define SIZE_ARR    1
#define ELEMENT_ERR 2

int input_matrix(int a[][M], size_t *n, size_t *m);

int min_array(int a[M], size_t m);

void matrix_sort_maxrows(int a[][M], size_t n, size_t m);

void print_matrix(int a[][M], size_t n, size_t m);

int main(void)
{
    int matrix[N][M];
    size_t n, m;
    int rc;
    
    setbuf(stdout, NULL);
    
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        if (rc == ELEMENT_ERR)
            printf("Error! The element(s) of matrix is incorrect!");
        return rc;
    }
    matrix_sort_maxrows(matrix, n, m);
    printf("\nOur matrix:\n");
    print_matrix(matrix, n, m);
    return rc;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2 || *n > N || *m > M || *n <= 0 || *m <= 0)
        return SIZE_ARR;
    printf("\nEnter elements of matrix:\n");
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ELEMENT_ERR;
    return EXIT_SUCCESS;
}

int min_array(int a[M], size_t m)
{
    int min = a[0];
    for (size_t i = 0; i < m; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

void matrix_sort_maxrows(int a[][M], size_t n, size_t m)
{
    size_t max;
    
    for (size_t k = 0; k < n; k++)
    {
        max = k;
        for (size_t i = k + 1; i < n; i++)
        {
            int last = 0, next = 0;
            last = min_array(a[max], m);
            next = min_array(a[i], m);
            if (last < next)
                max = i;
        }   
        for (size_t j = 0; j < m; j++)
        {
            int buff = a[max][j];
            a[max][j] = a[k][j];
            a[k][j] = buff;
        }   
    }
}

void print_matrix(int a[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (j == m - 1)
                printf("%d\n", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
}