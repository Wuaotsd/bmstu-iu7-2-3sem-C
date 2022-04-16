#include <stdio.h>
#include <stdlib.h>
# define N 10

int input_array(int a[N], int *n);

int multi_uneven(int a[N], int n);

int main(void)
{
    setbuf(stdout, NULL);
	int arr[N], n = 0;
	
	int rc = input_array(arr, &n);
	if (rc == EXIT_FAILURE)
		return rc;
	
	int multi = multi_uneven(arr, n);
	
	printf("Multi of even numbers in array: %d", multi);
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

int multi_uneven(int a[N], int n)
{
	int result = 0;
	
	for (int i = 0; i < n; i++)
		if (a[i] % 2 != 0)
        {
            if (i == 0)
                result = a[i];
            else
                result *= a[i];
        }
	return result;
}
