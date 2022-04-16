#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10

int input_matrix(int a[][M], size_t *n, size_t *m);

void check_strok_simetric(int b[N], int a[][M], size_t n, size_t m);

void print_array(int b[N], size_t n);

int main(void)
{
	int matrix[N][M];
	int array[N];
	size_t n, m;
	
	int rc = input_matrix(matrix, &n, &m);
	if (rc == EXIT_FAILURE)
		return EXIT_FAILURE;
	check_strok_simetric(array, matrix, n, m);
	printf("Array: ");
	print_array(array, n);
	return EXIT_SUCCESS;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
	int rc = EXIT_SUCCESS;
	
	printf("Enter size of matrix nxm: ");
	if (scanf("%zu", n) != 1 || *n <= 0 || *n > N)
	{
		printf("Error! The size n of matrix is incorrect!");
		return EXIT_FAILURE;
	}
	if (scanf("%zu", m) != 1 || *m <= 0 || *m > M)
	{
		printf("Error! The size m of matrix is incorrect!");
		return EXIT_FAILURE;
	}
	printf("\nEnter elements of matrix:\n");
	for (size_t i = 0; i < *n; i++)
	{
		for (size_t j = 0; j < *m; j++)
			if (scanf("%d", &a[i][j]) != 1)
			{
				printf("Error! The element(s) of matrix is incorrect!");
				rc = EXIT_FAILURE;
				break;
			}
		if (rc == EXIT_FAILURE)
			break;
	}
	return rc;
}

void print_array(int b[N], size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%d", b[i]);
		else
			printf("%d ", b[i]);
	}
}

void check_strok_simetric(int b[N], int a[][M], size_t n, size_t m)
{
	int k;
	for (size_t i = 0; i < n; i++)
	{
		if (m == 1)
			k = 1;
		else
			for (size_t j = 0; j < (m / 2); j++)
			{
				if (a[i][j] == a[i][m - j - 1])
					k = 1;
				else
				{
					k = 0;
					break;
				}
			}
		b[i] = k;
	}
}
