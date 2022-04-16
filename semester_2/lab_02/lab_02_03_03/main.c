#include<stdio.h>
#include<stdlib.h>

#define N 10

int read_array(int *arr, int *n)
{
    printf("Enter size of array: ");
    if ((scanf("%d", &*n) != 1) || (*n <= 0) || (*n > N))
    {
        printf("\nError! The size of array is small or big!");
        return EXIT_FAILURE;
    }
    //printf("Enter elements in array:\n");
    for (int i = 0; i < *n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("\nError! The number is incorrect!");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

void reverse(int *arr, int n)
{
    int first_num, rev_num = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            printf("%d ", arr[i]);
            while (arr[i] != 0)
            {
                first_num = arr[i] % 10;
                rev_num = rev_num * 10 + first_num;
                arr[i] /= 10;
            }
            printf("%d ", rev_num);
            rev_num = 0;
        }
        else
            printf("%d ", arr[i]);
    }
}

int main()
{
    setbuf(stdout, NULL);
    int arr[N], n = 0;

    if (read_array(arr, &n) == EXIT_FAILURE)
        return EXIT_FAILURE;
    printf("\nArray: ");
    reverse(arr, n);
    return EXIT_SUCCESS;
}