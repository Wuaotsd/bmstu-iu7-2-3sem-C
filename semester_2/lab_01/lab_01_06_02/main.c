#include <stdio.h>
#include <math.h>

int check (double a, double b, double c)
{
    double eps = 1e-8;
    if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0))
        return 0;
    if (fabs(a) < eps && (b * c >= 0))
        return 1;

    if (fabs(b) < eps && (a * c >= 0))
        return 1;

    if (fabs(c) < eps && (b * a >= 0))
        return 1;
    return 2;
}

int main(void)
{
    setbuf(stdout, NULL);
    double xa, ya, xb, yb, xc, yc, xp, yp;
    double a, b, c;
    int result;
    printf("Enter xa ya: ");
    if (!(scanf("%lf", &xa)) || !(scanf("%lf", &ya)))
    {
        printf("The coordinate entered is incorrect! - xa, ya!");
        return -1;
    }
	
    printf("Enter xb yb: ");
    if (!(scanf("%lf", &xb)) || !(scanf("%lf", &yb)))
    {
        printf("The coordinate entered is incorrect! - xb, yb!");
        return -1;
    }

    printf("Enter xc yc: ");
    if (!(scanf("%lf", &xc)) || !(scanf("%lf", &yc)))
    {
        printf("The coordinate entered is incorrect! - xc, yc!");
        return -1;
    }
    
    printf("Enter xp yp: ");
    if (!(scanf("%lf", &xp)) || !(scanf("%lf", &yp)))
    {
        printf("The coordinate entered is incorrect! - xp, yp!");
        return -1;
    }
    
    a = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    b = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    c = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
    if (a + b <= c || a + c <= b || b + c <= a)
        return -1;// не треугольник
    a = (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
    b = (xb - xp) * (yc - yb) - (xc - xb) * (yb - yp);
    c = (xc - xp) * (ya - yc) - (xa - xc) * (yc - yp);
    result = check(a, b, c);
    printf("Result: %d", result);
    return 0;
}