#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10
# define ARRAY_EMPTY -1

int input_array(int a[N], int *n);

void print_array(int a[N], int n);

int make_array_simple_figure(int a[N], int a_n, int b[N], int *b_n);

int main(void)
{
    setbuf(stdout, NULL);
    int arr_a[N], arr_b[N], a_n = 0, b_n = 0;
    int rc = input_array(arr_a, &a_n);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc =  make_array_simple_figure(arr_a, a_n, arr_b, &b_n);
    if (rc != EXIT_SUCCESS)
    {
        printf("\nError! The array B is empty!");
        return ARRAY_EMPTY;
    }
    
    printf("\nThe array of numbers up avg: ");
    print_array(arr_b, b_n);
    return EXIT_SUCCESS;
}

int input_array(int a[N], int *n)
{
    int rc = EXIT_SUCCESS;
    printf("Enter size of array: ");
    if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > N))
    {
        printf("\nError! The size of array is small or big!");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < *n; ++i)
    {
        //printf("\nEnter number: ");
        if (scanf("%d", &a[i]) != 1)
        {
            printf("\nError! The number is incorrect!");
            rc = EXIT_FAILURE;
            break;
        }
    }
    return rc;
}

void print_array(int a[N], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (i == (n - 1))
            printf("%d", a[i]);
        else
            printf("%d ", a[i]);
    }
}

int  make_array_simple_figure(int a[N], int a_n, int b[N], int *b_n)
{
    int i = 0;
    while (i < a_n)
    {
        if (a[i] > 1 && (a[i] == 2 || a[i] % 2 != 0))
        {
            b[*b_n] = a[i];
            (*b_n)++;
        }
        i++;
    }
    if (*b_n == 0)
        return 1;
    return 0;
}