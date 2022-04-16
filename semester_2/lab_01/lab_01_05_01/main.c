#include <stdio.h>

int main(void)
{
    int a, d;
    int q, r;
    printf("Input a/d: ");
    if (scanf("%d %d", &a, &d) != 2 || a <= 0 || d <= 0)
        return -1;
    r = a % d;
    while (a >= d)
    {
        a -= d;
        q++;
    }
    printf("%d %d", q, r);
    return 0;
}