#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double len_vec(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double f, s, x, y;

    f = x2 - x1;
    s = y2 - y1;
    x = x3 - x1;
    y = y3 - y1;
    return (f * y - x * s);
}

int check(double len)
{
    if (len > 0)
        return 0;
    else if (len < 0)
        return 2;
    else
        return 1;
}
int scanf_point(double *x , double *y)
{
    if (!(scanf("%lf", x)) || !(scanf("%lf", y)))
        return 0;
    return 1;
}
int main(void)
{
    setbuf(stdout, NULL);
    double xp, yp;
    double xq, yq, xr, yr;
    double len;
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
    
    len = len_vec(xq, yq, xr, yr, xp, yp);
    result = check(len);
    printf("Result: %d", result);
    return 0;
}