#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10

int input_array(int a[N], int *n);

void replace_arr(int a[N], int i, int *n)
{
    for (; i < *n; i++)
        a[i] = a[i + 1];
    (*n)--;
}

int check_sqrt(int num)
{
    if (num < 0)
        return 0;
    double num_1;
    num_1 = sqrt(num);
    if (fabs(((int) num_1) * 10  - (num_1 * 10)) < 1e-8)
        return 1;
    return 0;
}

void del_sqrt_num(int a[N], int *n)
{
    int i = 0;
    while (i < *n)
    {
        if (check_sqrt(a[i]))
        {
            replace_arr(a, i, n);
            i--;
        }
        i++;
    }
}

void printf_arr(int a[N], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    setbuf(stdout, NULL);
	int arr_a[N], n;
	
	int rc = input_array(arr_a, &n);
	if (rc == EXIT_FAILURE)
		return rc;
    
	
    del_sqrt_num(arr_a, &n);
    if (n == 0)
    {
        printf("\nError! The array is empty!");
        return EXIT_FAILURE;
    }
	printf("\nArray: ");
    printf_arr(arr_a, n);
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
	
	for (int i = 0; i < *n; i++)
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
