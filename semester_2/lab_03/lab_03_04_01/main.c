#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
#define M 10

#define SIZE_ARR           1
#define ELEMENT_ERR        2
#define NOT_SQUARE_MATRIX  3

int input_matrix(int a[][M], size_t *n, size_t *m);

void print_matrix(int a[][M], size_t n, size_t m);

void fill_array(int *buff, int *arr, size_t m, size_t j);

void replace_row_matrix(int a[][M], size_t n, size_t m);

int main(void)
{
    int matrix[N][M];
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
    replace_row_matrix(matrix, n, m);
    printf("Our matrix:\n");
    print_matrix(matrix, n, m);
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

void fill_array(int *buff, int *arr, size_t m, size_t j)
{
    for (size_t i = j; i < m / 2; i++)
        buff[i] = arr[i];
    for (int i = m - j - 1; i > 0; i--)
        buff[i] = arr[i];
}

void replace_row_matrix(int a[][M], size_t n, size_t m)
{
    size_t j = 0;
    int buff[M];
    for (size_t i = 0; i < n / 2; i++, j++)
    {
        fill_array(buff, a[i], m, j);
        fill_array(a[i], a[n - 1 - j], m, j);
        fill_array(a[n - 1 - j], buff, m, j);        
    }
}