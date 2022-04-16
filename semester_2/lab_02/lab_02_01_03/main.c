#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define N 10

int input_array(int a[N], int *n);

double geometric_mean(int a[N], int n);

int main(void)
{
	int arr[N], n = 0;
	
	int res = input_array(arr, &n);
	if (res == -1)
		return -1;
	
	double geometric_number = geometric_mean(arr, n);
	
	if (geometric_number == -1)
		return -1;
	
	printf("Geometric mean: %lf", geometric_number);
	return 0;
}

int input_array(int a[N], int *n)
{
	//printf("Enter number of figures: ");
	if ((scanf("%d", &*n) != 1) || (*n <= 0) || (*n > N))
	{
		printf("Error! The size of array is small or big!");
		return -1;
	}
	for (int i = 0; i < *n; ++i)
	{
		//printf("\nEnter number: ");
		if (scanf("%d", &a[i]) != 1)
		{
			printf("Error! The number is incorrect!");
			return -1;
		}
	}
	return 0;
}

double geometric_mean(int a[N], int n)
{
	int interation = 0;
	double result, x_common = 1.0;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			x_common = x_common * a[i];
			interation++;
		}
	}
	
	if (interation == 0)
	{
		printf("Error! The number of array is negative!");
		return -1;
	}
	
	result = exp((1.0 / interation) * log(x_common)); //pow(x_common, (1.0 / 10));
	
	return result;
}
