#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int a;
	int result;
	
	printf("Input three-digit number:");
	scanf("%d", &a);
	result = abs((a / 100) * (a / 10 % 10) * (a % 10));
	printf("Result = %d", result);
	return 0;
}
