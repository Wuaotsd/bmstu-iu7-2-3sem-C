#include <stdio.h>
#include <math.h>

int main(void)
{
	double r1, r2, r3;
	double r;
	printf("Input r1, r2, r3:");
	scanf("%lf %lf %lf", &r1, &r2, &r3);
	
	r = 1 / r1 + 1 / r2 + 1 / r3;
	r = 1 / r;
	printf("R = %.6f", r);
	return 0;
}
