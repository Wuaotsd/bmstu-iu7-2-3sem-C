#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10

int input_matrix(int a[][M], size_t *n, size_t *m);

void matrix_sort_multi(int a[][M], size_t n, size_t m);

void print_matrix(int a[][M], size_t n, size_t m);

int main(void)
{
	int matrix[N][M];
	size_t n, m;
	int rc;
	
	setbuf(stdout, NULL);
	
	rc = input_matrix(matrix, &n, &m);
	if (rc == EXIT_SUCCESS)
	{
		matrix_sort_multi(matrix, n, m);
		print_matrix(matrix, n, m);
	}	
	return rc;
}

int input_matrix(int a[][M], size_t *n, size_t *m)
{
	int rc = EXIT_SUCCESS;
	
	printf("Enter size of matrix mxn:");
	if (scanf("%zu%zu", n, m) != 2)
	{
		printf("\nError! The size of matrix is incorrect! Entered symbol!");
		return EXIT_FAILURE;
	}	
	if (!(0 < *n && *n <= N) || !(0 < *m && *m <= M))
	{
		printf("\nError! The size of matrix is incorrect! Limit is upper!");
		return EXIT_FAILURE;
	}
	printf("\nEnter elements of matrix:\n");
	for (size_t i = 0; i < *n; i++)
	{
		for (size_t j = 0; j < *m; j++)
			if (scanf("%d", &a[i][j]) != 1)
			{
				printf("\nError! The size of matrix is incorrect! Entered symbol!");
				rc = EXIT_FAILURE;
				break;
			}
		if (rc == EXIT_FAILURE)
			break;
	}
	return rc;
}

void matrix_sort_multi(int a[][M], size_t n, size_t m)
{
	size_t min;
	
	for (size_t k = 0; k < n; k++)
	{
		min = k;
		for (size_t i = k + 1; i < n; i++)
		{
			int last = 1, next = 1;
			for (size_t j = 0; j < m; j++)
			{
				last *= a[min][j];
				next *= a[i][j];
			}
			if (last > next)
				min = i;
		}	
		for (size_t j = 0; j < m; j++)
		{
			int buff = a[min][j];
			a[min][j] = a[k][j];
			a[k][j] = buff;
		}	
	}
}

void print_matrix(int a[][M], size_t n, size_t m)
{
	printf("\nOur matrix:\n");
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			if (j == m - 1)
				printf("%d\n", a[i][j]);
			else
				printf("%d ", a[i][j]);
		}
}