#include <stdio.h>
#include <math.h>

int check (double a, double b, double c)
{
    if (a + b <= c || a + c <= b || b + c <= a)
        return -1;
    if (c * c > a * a + b * b)
        return 2;// тупоугольный
    else if (c * c < a * a + b * b)
        return 0; // остроугольный
    else
        return 1; // прямоугольный
}

int main(void)
{
    setbuf(stdout, NULL);
    double xa, ya, xb, yb, xc, yc;
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
        printf("The coordinate entered is incorrect! - xp, yp!");
        return -1;
    }
    
    a = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    b = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    c = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
    
    result = check(a, b, c);
    if (result == -1)
    {
        printf("Это не треугольник");
        return -1;
    }
    printf("Result: %d", result);
    return 0;
}