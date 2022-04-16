#include <stdio.h>
#define N 100

int main(void)
{
	int a[N], n = 0;
	printf("Enter size of array: ");
	if(scanf("%d",  &n) != 1 || n > N || n <= 0)
	{
		printf("Error! Number is incorrect!");
		return -1;
	}
	
	for (int i = 0; i < n; i++)
	{
		if(scanf("%d", &a[i]) != 1)
		{
			printf("Error! The number of array is incorrect!");
			return -1;
		}
	}
	for (int j = 1; j < n; j++)
		if (a[j - 1] >= a[j])
		{
			for (int k = j; k < n; k++)
				a[k - 1] = a[k];
			n--;
			if (a[j] > a[j + 1] && a[j - 1] < a[j] && j != n)
			{
				for (int k = j + 1; k < (n - 1); k++)
					a[k] = a[k + 1];
				n--;
				j++;
			}
		}
	printf("\nResult =");
	for (int b = 0; b < n; b++)
		printf(" %d", a[b]);
	return 0;
}