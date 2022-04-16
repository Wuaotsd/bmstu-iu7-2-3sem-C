#include<stdio.h>
#include<math.h>

long long fact (int n)
{
    if (n == 0)
        return 1;
    int i = 1;
    long long res = 1;
    while (i <= n)
    {
        res *= i;
        i++;
    }
    return res;
}

double s_find(double x, double eps)
{
    long long i = 1 , j = 0;
    double t = x;
    double res = t;
    while (fabs(t) > eps) /* x - x^3 / 3 + x^5 / 5 - x^7 / 7 + ...*/
    {
        i += 2;
        if (j % 2 == 0)
            t = -1 * pow(x, i) / fact(i);
        else 
            t = pow(x, i) / fact(i);
        res += t;
        j++;
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
        else if (fabs(x) < 1e-8)
        {
            s_x = s_find(x, eps);
            f_x = sin(x); // arctan(x)
            abs_err = fabs(f_x - s_x);
            rel_err = 0;
            printf("s(x) = %lf\n", s_x);
            printf("f(x) = %lf\n", f_x);
            printf("Абсолютная: %lf\n", abs_err);
            printf("Относительная: %lf\n", rel_err);
            return 0;
        }
        else
        {
            s_x = s_find(x, eps);
            f_x = sin(x); // sin(x)
            abs_err = fabs(f_x - s_x);
            rel_err = fabs((f_x - s_x) / f_x);
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
