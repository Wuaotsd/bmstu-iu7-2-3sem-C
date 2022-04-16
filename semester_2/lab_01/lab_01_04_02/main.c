#include <stdio.h>
int main(void)
{
    int t;
    int h, m, s;

    printf("Input seconds:\n    ");
    scanf("%d", &t);

    h = t / 3600;
    m = (t % 3600) / 60;
    s = (t % 3600) % 60;

    printf("It is:\n    %d h. %d min. %d sec.\n", h, m, s);

    return 0;
}