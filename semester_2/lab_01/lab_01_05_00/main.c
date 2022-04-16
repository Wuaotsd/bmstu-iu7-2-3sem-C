#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, n;
    double result;
    printf("Input a^n: ");
    if (scanf("%d %d", &a, &n) != 2 || n <= 0)
        return -1;
    result = pow(a, n);
    printf("Result: %.6lf", result);
    return 0;
}