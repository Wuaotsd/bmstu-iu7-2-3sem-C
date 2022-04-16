#include <stdio.h>

int main(void)
{
    int n;
    printf("Input n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
        return -1;
    int i = 0, nr = 0, j;
    while (n > 0)
    {
        nr *= 10;
        nr += (n % 10);
        n /= 10;
    }
    n = nr;
    printf("Result: ");
    while (n > 0)
    {
        j = n % 10;
        while (i < 10)
        {
            if (i == j)
            {
                printf("%d", i);
                break;
            }
            i++;
        }
        n /= 10;
        i = 0;
    }
    return 0;
}