#include <stdio.h>
#include <stdlib.h>

# define N 10
# define M 10

int input_matrix (int matrix[N][M], int *n, int *m)
{
    printf("Введите размер матрицы nxm: ");
    if (!scanf("%d", n) || !scanf("%d", m))
        return 1;
    if (*n < 0 || *m < 0 || *n > N || *m > M)
       return 2;
    printf("Введите элементы матрицы %d x %d:\n", *n, *m);
    for (int i = 0; i < *n; i++)
        for(int j = 0; j < *m; j++)
            if (!scanf("%d", &matrix[i][j]))
                return 3;
    return 0;
}

void print_matrix(int matrix[N][M], int n, int m)
{
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < n - 1)
                printf(" ");
            else
                printf("\n");
        }
}
// umd - under main diagonal
void max_umd(int a[N][M], int n, int m, int *max)
{
    (*max) = a[1][m - 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (j < i && a[i][j] > *max)
                *max = a[i][j];
            if (n > m && i > m - 1 && a[i][j] > *max)
                *max = a[i][j];
        }
}

void min_umd(int a[N][M], int n, int m, int *min)
{
    (*min) = a[1][m - 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // j < j все что под главной диагональю
            if (j < i && a[i][j] < *min)
                *min = a[i][j];
            // если матрица прямоугольная
            if (n > m && i > m - 1 && a[i][j] < *min)
                *min = a[i][j];
        }
}

int main(void)
{
    setbuf(stdout, NULL);
    
    int matrix[N][M];
    int n, m;
    int rc = EXIT_SUCCESS;
    int max, min;
    rc = input_matrix(matrix, &n, &m);
    if (rc != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (n == 1 && m == 1)
        printf("Нет макс и мин!");
    else
    {
        max_umd(matrix, n, m, &max);
        min_umd(matrix, n, m, &min);
        printf("Максимальное значение под главной диагональю: %d\n", max);
        printf("Минимальное значение под главной диагональю: %d\n", min);
    }
    return rc;
}