#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

#define SIZE_ARR  1

int input_size_matrix(size_t *n, size_t *m);

void hod_cow(int a[][M], size_t n, size_t m);

void print_matrix(int a[][M], size_t n, size_t m);

int main(void)
{
    int matrix[N][M];
    size_t n, m;
    
    int rc = input_size_matrix(&n, &m);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        return rc;
    }
    
    hod_cow(matrix, n, m);
    printf("\nOur matrix:\n");
    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}

int input_size_matrix(size_t *n, size_t *m)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2 || *n > N || *m > M || *n <= 0 || *m <= 0)
        return SIZE_ARR;
    return EXIT_SUCCESS;
}

void hod_cow(int a[][M], size_t n, size_t m)
{
    int number = (int) (n * m);
    for (size_t i = 0; i < m; i++)
    {
        if (i % 2 != 0)
            for (size_t j = 0; j < n; j++)
                a[j][i] = number--;
        else
            for (int j = n - 1; j >= 0; j--)
                a[j][i] = number--;
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
