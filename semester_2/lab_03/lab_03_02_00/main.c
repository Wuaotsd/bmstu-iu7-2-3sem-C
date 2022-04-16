#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define M 100
#define OUT 10

int input_matrix(int a[][M], size_t *n, size_t *m, int *digit);

int matrix_insert_line(int a[][M], size_t *n, size_t m, int digit);

void print_matrix(int a[][M], size_t n, size_t m);

int first_digit(int number, int digit);

int last_digit(int number, int digit);

int number_begin_end(const int *a, size_t m, int digit);

int main(void)
{
    int matrix[N][M];
    size_t n, m;
    int rc;
    int digit;

    setbuf(stdout, NULL);

    rc = input_matrix(matrix, &n, &m, &digit);
    if (rc != EXIT_SUCCESS)
        return EXIT_FAILURE;
    rc = matrix_insert_line(matrix, &n, m, digit);
    if (rc != EXIT_SUCCESS)
        return EXIT_FAILURE;
    print_matrix(matrix, n, m);
    return rc;
}

int input_matrix(int a[][M], size_t *n, size_t *m, int *digit)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2)
    {
        printf("\nError! The size of matrix is incorrect!");
        return EXIT_FAILURE;
    }
    if (!(0 < *n && *n <= OUT) || !(0 < *m && *m <= OUT))
    {
        printf("\nError! The size of matrix is incorrect!");
        return EXIT_FAILURE;
    }
    printf("\nEnter elements of matrix:\n");
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Error! The element(s) of matrix is incorrect!");
                return EXIT_FAILURE;
            }
    printf("Enter digit '0-9':");
    if (scanf("%d", digit) != 1)
    {
        printf("\nError! The digit is incorrect!");
        return EXIT_FAILURE;
    }
    if (!(0 <= *digit && *digit < 10))
    {
        printf("\nError! The digit is incorrect!");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void print_matrix(int a[][M], size_t n, size_t m)
{
    printf("\nOur matrix:\n");
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

int first_digit(int number, int digit)
{
    while (abs(number) >= 10)
        number /= 10;
    if (abs(number) == digit)
        return 1;
    return 0;
}

int last_digit(int number, int digit)
{
    number = number % 10;
    if (abs(number) == digit)
        return 1;
    return 0;
}

int number_begin_end(const int *a, size_t m, int digit)
{
    int begin_digit = 0;
    int end_digit = 0;
    for (size_t i = 0; i < m; i++)
    {
        if (first_digit(a[i], digit))
            begin_digit += 1;
        if (last_digit(a[i], digit))
            end_digit += 1;
    }
    if (begin_digit == end_digit)
        if ((end_digit != 0) || (begin_digit != 0))
            return 1;
    return 0;
}

int matrix_insert_line(int a[][M], size_t *n, size_t m, int digit)
{
    for (size_t i = 0; i < *n ; ++i)
        if (number_begin_end(a[i], m, digit))
        {
            for (size_t k = *n; k > i + 1; k--)
            {
                for (size_t j = 0; j < m; j++)
                    a[k][j] = a[k - 1][j];
            }
            for (size_t j = 0; j < m; j++)
                a[i + 1][j] = 100;
            i++;
            (*n)++;
            if (*n > OUT)
                return EXIT_FAILURE;
        }
    return EXIT_SUCCESS;
}
