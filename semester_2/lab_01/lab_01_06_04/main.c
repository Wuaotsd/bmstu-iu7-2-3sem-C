#include <stdio.h>
#include <math.h>

int check(double a, double b, double c)
{
    double eps = 1e-8;
    //printf("\n %lf  => %lf = %lf + %lf = %lf\n", fabs(a - (b + c)), a, b, c, b + c);
    if (fabs(a - (b + c)) < eps)
        return 1; // принадлежит
    return 0; // не принадлежит
}

int scanf_point(double *x , double *y)
{
    if (!(scanf("%lf", x)) || !(scanf("%lf", y)))
        return 0;
    return 1;
}

double len_seg(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
int main(void)
{
    setbuf(stdout, NULL);
    double xq, yq, xr, yr;
    double xp, yp;
    double qr, qp, pr;
    int result;
    printf("Введите кординаты отрезка QR.\n");
    printf("Кординаты точки Q: ");
    if (!(scanf_point (&xq , &yq)))
    {
        printf("Ошибка! Координаты не верны");
        return 1;
    }
	printf("Кординаты точки R: ");
    if (!(scanf_point (&xr , &yr)))
    {
        printf("Ошибка! Координаты не верны");
        return 1;
    }
    printf("Введите кординаты точки P.\n");
    printf("Кординаты точки P: ");
    if (!(scanf_point (&xp , &yp)))
    {
        printf("Ошибка! Координаты не верны");
        return 1;
    }
    
    qr = len_seg(xq, yq, xr, yr);
    qp = len_seg(xq, yq, xp, yp);
    pr = len_seg(xp, yp, xr, yr);
    
    result = check(qr, qp, pr);
    printf("Result: %d", result);
    return 0;
}