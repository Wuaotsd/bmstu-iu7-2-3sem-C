#include <stdio.h>
#include <math.h>

int main(void)
{
	float v0, a, t, s;
	printf("Input v0 a t:");
	scanf("%f %f %f", &v0, &a, &t);
	s = v0 * t + (a * t * t) / 2;
	printf("S = %0.2f", s);
	return 0;
}
