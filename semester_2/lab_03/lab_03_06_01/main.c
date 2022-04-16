#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

#define SIZE_ARR           1
#define NOT_SQUARE_MATRIX  2

int input_size_matrix(size_t *n, size_t *m);

void spiral_right(int a[][M], size_t n, size_t m);

void print_matrix(int a[][M], size_t n, size_t m);

int main(void)
{
	int matrix[N][M] = { { 0 } };
    size_t n, m;
	
	int rc = input_size_matrix(&n, &m);
	if (rc != EXIT_SUCCESS)
    {
        if (rc == SIZE_ARR)
            printf("\nError! The size of matrix is incorrect!");
        if (rc == NOT_SQUARE_MATRIX)
            printf("\nError! Matrix is not square!");
        return rc;
    }
	
	spiral_right(matrix, n, m);
	printf("\nOur matrix:\n");
	print_matrix(matrix, n, m);
	
	return EXIT_SUCCESS;
}

int input_size_matrix(size_t *n, size_t *m)
{
    printf("Enter size of matrix nxm:");
    if (scanf("%zu%zu", n, m) != 2 || *n > N || *m > M || *n <= 0 || *m <= 0)
        return SIZE_ARR;
    if (*n != *m)
        return NOT_SQUARE_MATRIX;
    return EXIT_SUCCESS;
}

void spiral_right(int a[][M], size_t n, size_t m)
{
	int number = 1;
	for (size_t i = 0; i < ((n + 1) / 2); i++)
	{
		// Заполнение верхней горизонтальной части матрицы
		for (size_t j = i; j < m - i; j++)
			a[i][j] = number++; // ok
		// Заполнение правой вертикальной части матрицы
		for (size_t j = i + 1; j < n - i ; j++)
			a[j][m - i - 1] = number++; // ok
		// Заполнение нижней горизонтальной части матрицы
	     for (int j = m - 2 - i; j >= (int) i; j--)
			a[n - i - 1][j] = number++; //ok
		// Заполнение левой вертикальной части матрицы
		for (size_t j = n - 2 - i; j > i; j--)
			a[j][i] = number++; //ok
	}
}

void print_matrix(int a[][M], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			if (j == m - 1)
				printf("%d\n", a[i][j]);
			else
				printf("%d ", a[i][j]);
		}
}
