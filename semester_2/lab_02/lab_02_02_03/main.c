#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10
# define ARRAY_EMPTY -1

int input_array(int a[N], int *n);

void print_array(int a[N], int n);

int armstrong_number(int);

int main(void)
{
	int arr_a[N], b[N], n = 0;
	int size = 0;

	int rc = input_array(arr_a, &n);
	
	if (rc == EXIT_FAILURE)
		return rc;
	
	for (int i = 0; i < n; i++)
	{
		int number = armstrong_number(arr_a[i]);
		if (number == arr_a[i])
		{
			b[size] = number;
			size++;
		}
	}
	if (size == 0)
	{
		printf("\nError! The array B is empty!");
		return ARRAY_EMPTY;
	}
	
	printf("\nThe array of armstrong number: ");
	print_array(b, size);
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
		//printf("Enter number: ");
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

int armstrong_number(int number)
{
	int sum = 0, digit = 1;
	int number_1 = number;
	
	while ((number_1 /= 10) > 0)
		digit++;
	
	while (number > 0)
	{
		int rem = number % 10;
		sum += pow(rem, digit);
		number = number / 10;
	}
	
	return sum;
}
