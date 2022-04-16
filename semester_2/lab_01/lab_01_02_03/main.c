#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, q;
	double s;
	printf("Input a, b:");
	scanf("%lf %lf", &a, &b);
	printf("Input q:");
	scanf("%lf", &q);
	q = q * 2 * asin(1.0) / 180;
	s = 0.5 * (a * b) * sin(q);
	printf("S = %.6f", s);
	return 0;
}
