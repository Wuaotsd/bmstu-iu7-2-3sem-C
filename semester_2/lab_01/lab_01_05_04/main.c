#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n > 0: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return -1;
    if (n == 1)
    {
        printf("Множителей нет");
        return -1;
    }
    
    int i = 2;
    printf("Result: ");
    while (i <= n)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
        else
            i++;
    }
    return 0;
}