#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define M 10

#define SIZE_ARR    1
#define ELEMENT_ERR 2
#define DEL_ERR     3
#define DIGIT_ERR   4

int input_matrix(int a[][M], size_t *n, size_t *m, int *digit);

int check_digit_number(int num, int digit);

void del_rows(int a[][M], size_t *n, size_t m, int digit);

void del_row_by_pos(int a[][M], size_t *n, size_t m, size_t i);

void print_matrix(int a[][M], size_t n, size_t m);

int main()
{
    setbuf(stdout, NULL);
    int matrix[N][M];
    size_t n = 0, m = 0;
    int rc = EXIT_SUCCESS;
    int digit = 0;
    rc = input_matrix(matrix, &n, &m, &digit);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        if (rc == ELEMENT_ERR)
            printf("Error! The element(s) of matrix is incorrect!");
        if (rc == DIGIT_ERR)
            printf("\nError! The digit is incorrect!");
        return rc;
    }
    del_rows(matrix, &n, m, digit);
    if (n == 0)
    {
        printf("\nWarning! All rows is deleted!");
        return DEL_ERR;
    }
    printf("\nOur matrix:\n");
    print_matrix(matrix, n, m);
    return 0;
}

int input_matrix(int a[][M], size_t *n, size_t *m, int *digit)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2 || *n > N || *m > M || *n <= 0 || *m <= 0)
        return SIZE_ARR;
    printf("\nEnter elements of matrix:\n");
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return ELEMENT_ERR;
    printf("Enter digit '0-9':");
    if (scanf("%d", digit) != 1 || *digit <= 0 || *digit > 9)
        return DIGIT_ERR;
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

int check_digit_number(int num, int digit)
{
    num = abs(num);
    while (num > 0)
    {
        if (digit == num % 10)
            return 1;
        num /= 10;
    }
    return 0;
}

void del_row_by_pos(int a[][M], size_t *n, size_t m, size_t i)
{
    for (; i < *n; i++)
        for (size_t j = 0; j < m; j++)
            a[i][j] = a[i + 1][j];
    (*n)--;
}


void del_rows(int a[][M], size_t *n, size_t m, int digit)
{
    int count = 0;
    for (size_t i = 0; i < *n;)
    {
        count = 0;
        for (size_t j = 0; j < m; j++)
            if (check_digit_number(a[i][j], digit))
                count++;
        if (count > 0)
            del_row_by_pos(a, n, m, i);
        else
            i++;
    }
}