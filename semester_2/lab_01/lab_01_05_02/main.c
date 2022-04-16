#include <stdio.h>

int main(void)
{
    int a;
    int fib1 = 1, fib2 = 1, fib_sum;
    printf("Input a!: ");
    if (scanf("%d", &a) != 1 || a < 0)
        return -1;
    int i = 0;
    if (a == 0)
    {
        printf("Result: %d", a);
        return 0;
    }
    while (i < a - 2)
    {
        fib_sum = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib_sum;
        i++;
    }
    printf("Result: %d", fib2);
    return 0;
}