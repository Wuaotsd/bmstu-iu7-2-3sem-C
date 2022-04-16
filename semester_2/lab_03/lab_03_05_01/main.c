#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10

#define SIZE_ARR           1
#define ELEMENT_ERR        2
#define ARRAY_EMPTY        3

int input_matrix(int a[][M], size_t *n, size_t *m);

int get_sum_figures(int number);

void check_sum_add_array(int a[][M], int b[N + M], size_t n, size_t m, size_t *size);

void cyclic_left_shift(int b[N + M], size_t size, size_t sd);

void return_in_matrix(int a[][M], int b[N + M], size_t n, size_t m);

void print_matrix(int a[][M], size_t n, size_t m);

int main(void)
{
    int matrix[N][M], array[N + M];
    size_t n, m, size = 0, sd = 3;
    int rc = EXIT_SUCCESS;
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
    
    check_sum_add_array(matrix, array, n, m, &size);
    if (size == 0)
    {
        printf("Array is empty!");
        return ARRAY_EMPTY;
    }   
        
    cyclic_left_shift(array, size, sd);
    return_in_matrix(matrix, array, n, m);
    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
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

int get_sum_figures(int number)
{
    int sum = 0;
    number = abs(number);
    while (number > 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    if (sum > 10)
        return 1;
    return 0;
}

void check_sum_add_array(int a[][M], int b[N + M], size_t n, size_t m, size_t *size)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (get_sum_figures(a[i][j]))
            {
                b[(*size)] = a[i][j];
                (*size)++;
            }
        }
}

void cyclic_left_shift(int b[N + M], size_t size, size_t sd)
{
    for (size_t j = 0; j < sd; j++)
    {
        int buff = b[0];
        for (size_t i = 0; i < size - 1; i++)
            b[i] = b[i + 1];
        b[size - 1] = buff;
    }
}

void return_in_matrix(int a[][M], int b[N + M], size_t n, size_t m)
{
    size_t k = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (get_sum_figures(a[i][j]))
            {
                a[i][j] = b[k];
                k++;
            }
}

void print_matrix(int a[][M], size_t n, size_t m)
{
    printf("\nOur matrix:\n");
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (j == m - 1)
                printf("%d\n", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
}
    