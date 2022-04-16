#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10

int input_array(int a[N], int *n);

long long fibonachi(int num)
{
    int i = 0;
    
    if (num == 0)
        return num;
    i = 1;
    long long result = i;
    while (i <= num)
    {
        result *= i;
        i++;
    }
    return result;
}

void add_fib(int a[N], int n)
{
    int i = 0;
    
    while (i < n)
    {
        printf("%d ", a[i]);
        if (a[i] >= 0 && a[i] % 3 == 0)
            printf("%lld ", fibonachi(a[i]));
        i++;
    }
}

int main(void)
{
    setbuf(stdout, NULL);
	int arr_a[N], n;
	
	int rc = input_array(arr_a, &n);
	if (rc == EXIT_FAILURE)
		return rc;
    
    
	printf("\nArray: ");
    add_fib(arr_a, n);
	
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
