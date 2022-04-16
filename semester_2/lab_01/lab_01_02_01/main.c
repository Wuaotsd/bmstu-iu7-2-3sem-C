#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, q;
	double s;
	printf("Input a, b:");
	scanf("%lf %lf", &a, &b);
	printf("Input h:");
	scanf("%lf", &q);
	q = q * 2 * asin(1.0) / 180;
	s = (fabs(b * b - a * a) / 2) * (sin(q) * sin(q) / sin(2 * q));
	
	printf("S = %.6f", s);
	return 0;
}
