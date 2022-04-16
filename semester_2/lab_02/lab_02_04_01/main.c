#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10

int input_array(int a[N], int n);

void print_array(int a[N], int n);

void insertion_sort(int a[N], int n);

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
	insertion_sort(arr_a, n);
	
	printf("Sort array with Insertion Sort:");	
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

void insertion_sort(int a[N], int n)
{
	int buff = 0;
	
	for (int i = 0; i < (n - 1); i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				buff = a[j];
				a[j] = a[i];
				a[i] = buff;
			}
}