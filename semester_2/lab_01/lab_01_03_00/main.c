#include <stdio.h>
#include <math.h>

int main(void)
{
	double h, m, l;
	double mnormal, bmi;
	printf("Input height, girth, weight:");
	scanf("%lf %lf %lf", &h, &l, &m);
	
	mnormal = h * l / 240;
	bmi = m / ((h / 100) * (h / 100));
	
	printf("Mnormal, BMI = %.6f %.6f", mnormal, bmi);
	return 0;
}
