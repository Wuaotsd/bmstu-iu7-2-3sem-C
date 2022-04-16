#include<stdio.h>
#include<math.h>

long long fact_even (int n) // 2 * 4 * 6 * 7 n = 7
{
    if (n == 0)
        return 1;
    int i = 1;
    long long res = 1;
    while (i < n)
    {
        if (i % 2 == 0)
            res *= i;
        i++;
    }
    res *= n;
    return res;
}

long long fact_noeven (int n) // 1 * 3 * 5 n = 5
{
    if (n == 0)
        return 1;
    int i = 1;
    long long res = 1;
    while (i <= n)
    {
        if (i % 2 != 0)
            res *= i;
        i++;
    }
    return res;
}

double s_find(double x, double eps)
{
    long long i = 1;
    double t = x;
    double res = 0;
    while (fabs(t) > eps) /* x + x^3 / (2 * 3) + 3x^5 / (2 * 4 * 5) ...*/
    {
        res += t;
        t = t / (i + 1) / (i + 2) * i * i * x * x;
        i += 2;
    }
    return res;
}

int main(void)
{
    setbuf(stdout, NULL);
    double s_x, f_x, eps, abs_err, rel_err;
    double x;
    int rc;

    printf("Введите аргумент и точность: ");
    rc = scanf("%lf%lf", &x, &eps);
    if (rc == 2)
    {
        if (eps > 1 || eps <= 0)
        {
            printf("Limit error! 0 < eps <= 1!");
            return 2;
        }
        else if (fabs(x) > 1)
        {
            return 3;
        }
        else
        {
            s_x = s_find(x, eps);
            f_x = asin(x); // arcsin(x)
            abs_err = fabs(f_x - s_x);
            rel_err = (fabs(f_x) < 0.000001) ? abs_err : fabs(abs_err / f_x);
            printf("s(x) = %lf\n", s_x);
            printf("f(x) = %lf\n", f_x);
            printf("Абсолютная: %lf\n", abs_err);
            printf("Относительная: %lf\n", rel_err);
            return 0;
        }
    }     
    printf("Аргумент и точность некорректны!");
    return 1;
}
