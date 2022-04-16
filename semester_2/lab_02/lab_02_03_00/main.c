#include <stdio.h>
#include <stdlib.h>
# define N 10
# define ARRAY_EMPTY -1

int input_array(int a[N], int *n);

void print_array(int a[N], int n);

int revers_of_number(int number);

void delete_polindrom_number(int *a, int *n);

int main(void)
{
    setbuf(stdout, NULL);
	int arr_a[N], n;
	
	int rc = input_array(arr_a, &n);
	if (rc == EXIT_FAILURE)
		return rc;
    
	delete_polindrom_number(arr_a, &n);
	if (n == 0)
	{
		printf("\nError! Array is empty!");
		return ARRAY_EMPTY;
	}
	printf("\nArray without polindrom-number: ");
	print_array(arr_a, n);
	
	return EXIT_SUCCESS;
}

int input_array(int a[N], int *n)
{
	int rc = EXIT_SUCCESS;
	printf("Enter size of array: ");
	if ((scanf("%d", &*n) != 1) || (*n <= 0) || (*n > N))
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

int revers_of_number(int number)
{
	int reverse_number = 0;
	
	while (number > 0)
	{
		reverse_number = reverse_number * 10 + number % 10;
		number = number / 10;
	}
	
	return reverse_number;
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

void delete_polindrom_number(int *a, int *n)
{
	for (int i = 0; i < *n; i++)
	{
		int polindrom = revers_of_number(a[i]);
		if (polindrom == a[i])
		{
			(*n)--;
			for (int j = i; j < *n; j++)
				a[j] = a[j + 1];
			i--;
		}
	}
}
