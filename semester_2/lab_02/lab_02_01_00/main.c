#include <stdio.h>
#include <stdlib.h>
# define N 10

int input_array(int a[N], int *n);

int sum_even(int a[N], int n);

int main(void)
{
    setbuf(stdout, NULL);
	int arr[N], n = 0;
	
	int rc = input_array(arr, &n);
	if (rc == EXIT_FAILURE)
		return rc;
	
	int sum = sum_even(arr, n);
	
	printf("Sum of even numbers in array: %d", sum);
	return EXIT_SUCCESS;
}

int input_array(int a[N], int *n)
{
	int rc = EXIT_SUCCESS;
	//printf("Enter  size: ");
	if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > N))
	{
		printf("Error! The size is incorrect!");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < *n; ++i)
	{
		//printf("Enter number: ");
		if (scanf("%d", &a[i]) != 1)
		{
			printf("Error! Incorrect number!");
			rc = EXIT_FAILURE;
			break;
		}
	}
	return rc;
}

int sum_even(int a[N], int n)
{
	int result;
	
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			result += a[i];
	
	return result;
}
