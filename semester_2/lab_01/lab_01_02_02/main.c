#include <stdio.h>
#include <math.h>

int main(void)
{
	double xa, ya, xb, yb, xc, yc;
	double p, a, b, c;
	printf("Input xa, ya:");
	scanf("%lf %lf", &xa, &ya);
	printf("Input xb, yb:");
	scanf("%lf %lf", &xb, &yb);
	printf("Input xc, yc:");
	scanf("%lf %lf", &xc, &yc);
	
	a = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	b = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));
	c = sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya));
	
	p = a + b + c;
	
	printf("Pabc = %.6f", p);
	return 0;
}
