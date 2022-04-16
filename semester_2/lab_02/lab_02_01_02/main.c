#include <stdio.h>
#include <stdlib.h>
# define N 10

int input_array(int a[N], int *n);

double arifmetic_mean(int a[N], int n);

int main(void)
{
	int arr[N], n = 0;
	
	int rc = input_array(arr, &n);
	if (rc == EXIT_FAILURE)
		return rc;
	
	double arifmetic = arifmetic_mean(arr, n);
	
	if (arifmetic == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}
	
	printf("Arifmetic mean: %lf", arifmetic);
	return EXIT_SUCCESS;
}

int input_array(int a[N], int *n)
{
	int rc = EXIT_SUCCESS;
	//printf("Enter size of array:: ");
	if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > N))
	{
		printf("Error! The size of array is small or big! or is incorrect!");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < *n; ++i)
	{
		//printf("Enter number: ");
		if (scanf("%d", &a[i]) != 1)
		{
			printf("Error! The number is incorrect!");
			rc = EXIT_FAILURE;
			break;
		}
	}
	return rc;
}

double arifmetic_mean(int a[N], int n)
{
	int interation = 0;
	double result, x_common = 0.0;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			x_common += a[i];
			interation++;
		}
	}
	
	if (interation == 0)
	{
		printf("Error! The number of array is positive!");
		return EXIT_FAILURE;
	}
	
	result = (x_common / interation);
	
	return result;
}
