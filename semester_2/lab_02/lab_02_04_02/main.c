#include <stdio.h>
#include <stdlib.h>
# define N 10
# define ARRAY_EMPTY -1
# define ARRAY_FULL 100

int input_array(int a[N], int *n);

void print_array(int a[N], int n);

void selection_sort(int a[N], int n);

int main(void)
{
	int arr_a[N], n = 0;
	
	int rc = input_array(arr_a, &n);
	if (rc == ARRAY_EMPTY)
	{
		printf("Error! The array is empty!");
		return rc;
	}	
	selection_sort(arr_a, n);
	
	printf("Array was sorted with Selection Sort:");
	print_array(arr_a, n);
	
	return rc;
}

int input_array(int a[N], int *n)
{
	int element, i = 0, rc = EXIT_SUCCESS;
	
	while (scanf("%d", &element) == 1)
	{
		i++;
		if (*n <= 9)
		{
			a[*n] = element;
			(*n)++;
		}
		if (i > 10)
		{
			rc = ARRAY_FULL;
			break;
		}
	}
	
	if (*n <= 0)
		rc = ARRAY_EMPTY;
		
	return rc;
}

void print_array(int a[N], int n)
{
	for (int i = 0; i < n; ++i)
			printf(" %d", a[i]);
}

void selection_sort(int a[N], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		int buff = a[min];
		a[min] = a[i];
		a[i] = buff;
	}
}
