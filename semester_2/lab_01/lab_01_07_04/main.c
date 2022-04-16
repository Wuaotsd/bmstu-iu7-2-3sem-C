#include<stdio.h>
#include<math.h>

double s_find(double x, double eps)
{
    long long i = 3;
    double t = 1;
    double res = t;
    while (fabs(t) > eps) 
    {
        t *= -1 * x / 2;
        res += t * (i - 1) * i;
        i += 1;
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
        else if (fabs(x) >= 1)
        {
            return 3;
        }
        else
        {
            s_x = s_find(x, eps);
            f_x = 1 / pow((1 + x), 3); // 1 / (1 + x)^3
            abs_err = fabs(f_x - s_x);
            rel_err = (fabs(f_x) < 1e-8) ? abs_err : fabs((f_x - s_x) / f_x);
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
