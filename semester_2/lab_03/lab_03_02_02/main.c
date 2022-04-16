#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20
#define M 20
#define OUT 10

#define SIZE_ARR    1
#define ELEMENT_ERR 2

int input_matrix(int a[][M], size_t *n, size_t *m);

int sum_digits(int num);

int number_odd_sum_digits(int a[M], size_t m);

int matrix_insert_line(int a[][M], size_t *n, size_t m);

void print_matrix(int a[][M], size_t n, size_t m);

int main()
{
    setbuf(stdout, NULL);
    int matrix[N][M];
    size_t n = 0, m = 0;
    int rc = EXIT_SUCCESS;
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        if (rc == ELEMENT_ERR)
            printf("Error! The element(s) of matrix is incorrect!");
        return rc;
    }
    rc = matrix_insert_line(matrix, &n, m);
    if (rc != EXIT_SUCCESS)
        return rc;
    printf("Our matrix:\n");
    print_matrix(matrix, n, m);
    return EXIT_SUCCESS;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2 || *n > OUT || *m > OUT || *n <= 0 || *m <= 0)
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

int number_odd_sum_digits(int a[M], size_t m)
{
    int count = 0;
    int sum;
    for (size_t i = 0; i < m; i++)
    {
        sum = sum_digits(a[i]);
        if (sum % 2 != 0)
            count++;
    }
    return count;
}
// insert under row
int matrix_insert_line(int a[][M], size_t *n, size_t m)
{
    for (size_t i = 0; i < *n ; ++i)
        if (number_odd_sum_digits(a[i], m) >= 2)
        {
            for (size_t k = *n; k > i; k--)
            {
                for (size_t j = 0; j < m; j++)
                    a[k][j] = a[k - 1][j];
            }
            for (size_t j = 0; j < m; j++)
                a[i][j] = -1;
            i++;
            (*n)++;
            if (*n > N)
                return EXIT_FAILURE;
        }
    return EXIT_SUCCESS;
}