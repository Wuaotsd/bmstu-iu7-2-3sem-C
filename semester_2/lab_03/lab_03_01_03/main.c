#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

#define SIZE_ARR    -1
#define MATRIX_ERR  -2

int input_matrix(int a[][M], size_t *n, size_t *m);

void print_array(int a[N], size_t n);

int check_strok_monotonous(int a_i[M], size_t m);

void make_arrstrmono(int a[][M], int b[N], size_t n, size_t m);

int main()
{
    setbuf(stdout, NULL);
    int matrix[N][M];
    int array[N];
    size_t n = 0, m = 0;
    int rc = EXIT_SUCCESS;
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
        return rc;
    make_arrstrmono(matrix, array, n, m);
    printf("Array: ");
    print_array(array, n);
    return rc;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
    printf("Enter size of matrix nxm: ");
    if (scanf("%zu", n) != 1 || *n <= 0 || *n > N)
    {
        printf("Error! The size n of matrix is incorrect!");
        return SIZE_ARR;
    }
    if (scanf("%zu", m) != 1 || *m <= 0 || *m > M)
    {
        printf("Error! The size m of matrix is incorrect!");
        return SIZE_ARR;
    }
    printf("\nEnter elements of matrix:\n");
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Error! The element(s) of matrix is incorrect!");
                return MATRIX_ERR;
            }
    return EXIT_SUCCESS;
}

void print_array(int a[N], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (i < n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

int check_strok_monotonous(int a_i[M], size_t m)
{
    if (m < 2)
        return 0;
    int flag_dec = 1, flag_inc = 1;
    
    for (size_t j = 0; j < m - 1; j++)
        if (!(a_i[j] >= a_i[j + 1]))
        {
            flag_dec = 0;
            break;
        }
    for (size_t j = 0; j < m - 1; j++)
        if (!(a_i[j] <= a_i[j + 1]))
        {
            flag_inc = 0;
            break;
        }
    if (!flag_dec && !flag_inc)
        return 0;
    return 1;
}

void make_arrstrmono(int a[][M], int b[N], size_t n, size_t m)
{
    int ib = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (check_strok_monotonous(a[i], m))
            b[ib++] = 1;
        else
            b[ib++] = 0;
    }
}