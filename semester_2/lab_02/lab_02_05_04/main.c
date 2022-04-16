#include <stdio.h>
#include <stdlib.h>
# define N 10

int input_array(int *pa, int *n);

void find_unique_numbers(int *pa, int n);

int main(void)
{
	int arr_a[N], n;
	int *pa;
	pa = arr_a;
	int rc = input_array(pa, &n);
	if (rc == EXIT_FAILURE)
		return rc;
		
	find_unique_numbers(pa, n);
	return rc;
}

int input_array(int *pa, int *n)
{
	int rc = EXIT_SUCCESS, element;
	printf("\nEnter size of array: ");
	if ((scanf("%d", &*n) != 1) || (*n <= 0) || (*n > N))
	{
		printf("\nError! The size of array is small or big or is incorrect!");
		return EXIT_FAILURE;
	}
	
	for (int i = 0; i < *n; i++)
	{
		printf("\nEnter number: ");
		if (scanf("%d", &element) != 1)
		{
			printf("\nError! The number is incorrect!");
			rc = EXIT_FAILURE;
			break;
		}
		*pa = element;
		pa++;
	}
	return rc;
}

void find_unique_numbers(int *pa, int n)
{
	int count = 0, count_uniq;
	int *pe = (pa + n);
	
	while (pa < pe)
	{
		int *pb = (pa + 1);
		while (pb < pe)
		{
			if (*pb == *pa)
			{
				count++;
				break;
			}
			++pb;
		}
		++pa;
	}
	count_uniq = n - count;
	printf(" \nNumber of unique figures = %d", count_uniq);
}