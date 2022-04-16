#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define M 10

#define SIZE_ARR    1
#define ELEMENT_ERR 2
#define DEL_ERR     3

int input_matrix(int a[][M], size_t *n, size_t *m);

int sum_digits(int num);

void find_min_sum_digits(int a[][M], size_t n, size_t m, size_t *min_i, size_t *min_j);

void del_row_by_pos(int a[][M], size_t *n, size_t m, size_t i);

void del_column_by_pos(int a[][M], size_t n, size_t *m, size_t j);

void print_matrix(int a[][M], size_t n, size_t m);

int main()
{
    setbuf(stdout, NULL);
    int matrix[N][M];
    size_t n = 0, m = 0;
    int rc = EXIT_SUCCESS;
    size_t min_i = 0, min_j = 0;
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        if (rc == ELEMENT_ERR)
            printf("Error! The element(s) of matrix is incorrect!");
        return rc;
    }
    find_min_sum_digits(matrix, n, m, &min_i, &min_j);
    del_row_by_pos(matrix, &n, m, min_i);
    del_column_by_pos(matrix, n, &m, min_j);
    if (n == 0 || m == 0)
    {
        printf("Warning! All rows and column is deleted!");
        return DEL_ERR;
    }
    printf("Our matrix:\n");
    print_matrix(matrix, n, m);
    return 0;
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

void print_matrix(int a[][M], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (j == m - 1)
                printf("%d\n", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
    }
}

int sum_digits(int num)
{
    int sum = 0;
    num = abs(num);
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void find_min_sum_digits(int a[][M], size_t n, size_t m, size_t *min_i, size_t *min_j)
{
    int min = sum_digits(a[0][0]);
    int buff = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            buff = sum_digits(a[i][j]);
            if (min > buff)
            {
                min = buff; 
                *min_i = i;
                *min_j = j;
            }
        }
}

void del_row_by_pos(int a[][M], size_t *n, size_t m, size_t i)
{
    for (; i < *n; i++)
        for (size_t j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    (*n)--;
}

void del_column_by_pos(int a[][M], size_t n, size_t *m, size_t j)
{
    for (; j < *m; j++)
        for (size_t i = 0; i < n; i++)
            a[i][j] = a[i][j + 1];
    (*m)--;
}
