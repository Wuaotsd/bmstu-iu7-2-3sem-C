#include <stdio.h>

int main(void)
{
    double c = 4.2;
    double m1, m2, t1, t2, t, m;
    scanf("%lf", &m1);
    scanf("%lf", &t1);
    scanf("%lf", &m2);
    scanf("%lf", &t2);
    t = (m1 * c * t1 + m2 * c * t2) / (m1 * c + m2 * c);
    m = m1 + m2;
    printf("%.6f %.6f", m, t);
    return 0;
}