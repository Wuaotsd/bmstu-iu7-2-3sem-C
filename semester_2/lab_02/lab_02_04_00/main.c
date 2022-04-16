#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10

int input_array(int a[N], int n);

void print_array(int a[N], int n);

void bubble_sort(int a[N], int n);

int main(void)
{
    setbuf(stdout, NULL);
	int arr_a[N], n = 0;
	
	n = input_array(arr_a, n);
	if (n == 0)
	{
		printf("Error! The array is empty!");
		return -1;
	}
	bubble_sort(arr_a, n);
	
	printf("Sort array with Bubble Sort:");	
	print_array(arr_a, n);
    if (n == N)
		return 100;
	return 0;
}

int input_array(int a[N], int n)
{
	for (int i = 0; i < N; i++)
	{
		//printf("\nEnter number: ");
		if (scanf("%d", &a[i]) != 1)
			return n;
		n++;	
	} 
	return n;
}

void print_array(int a[N], int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", a[i]);
}

void bubble_sort(int a[N], int n)
{
	int buff = 0;
	
	for (int i = 0; i < (n - 1); i++)
		for (int j = (n - 1); j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				buff = a[j - 1];
				a[j - 1] = a[j];
				a[j] = buff;
			}
		}
}