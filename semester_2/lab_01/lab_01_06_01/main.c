#include <stdio.h>
#include <math.h>

double check (double a, double b, double c)
{
    double p_abc, s_abc;
    p_abc = (a + b + c) / 2.0;
    s_abc = sqrt(p_abc * (p_abc - a) * (p_abc - b) * (p_abc - c));
    return s_abc;
}

int main(void)
{
    setbuf(stdout, NULL);
    double xa, ya, xb, yb, xc, yc;
    double a, b, c, result;
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
    
    a = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    b = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    c = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
    
    result = check(a, b, c);
    printf("Result: %.6lf", result);
    return 0;
}