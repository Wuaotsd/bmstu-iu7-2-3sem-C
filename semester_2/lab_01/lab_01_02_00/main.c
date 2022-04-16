#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, h;
	double p, c, d;
	printf("Input a, b:");
	scanf("%lf %lf", &a, &b);
	printf("Input h:");
	scanf("%lf", &h);
	
	c = fabs(a - b) / 2;
	d = sqrt(h * h + c * c);
	p = 2 * d + a + b;
	printf("P = %.6f", p);
	return 0;
}
