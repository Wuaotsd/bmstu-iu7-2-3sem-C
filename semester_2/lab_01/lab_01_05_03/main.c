#include <stdio.h>
#include <math.h>

int main(void)
{
	int a, b;
  
	printf("Enter the first number:");
	if (!(scanf("%d", &a)))
	{
		printf("Your number entered is incorrect - maybe the first number!");
		return -1;
	}
	
	printf("Enter the second number:");
	if (!(scanf("%d", &b)))
	{
		printf("Your number entered is incorrect - maybe the second number!");
		return -1;
	}
	if ((a <= 0) || (b <= 0))
	{
		printf("The first or second number is less than or equal to zero!");
		if (a <= 0)
		{
			printf("=> the first number - a.");
		}
		if (b <= 0)
		{
			printf("=> the second number - b.");
		}
		return -1;
	}
	int i = a;
	
	while (i > 0)
	{
		if (a % i == 0 && b % i == 0)
		{
			printf("NOD = %d", i);
			break;
		}
		i--;
	} 
	
	return 0;
}
