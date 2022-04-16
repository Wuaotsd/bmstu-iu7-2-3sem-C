#include <stdio.h>

int main(void)
{
	int n, m, v, count = -1;
	
	printf("Enter number: ");
	if(scanf("%d", &n) != 1 || n <= 0)
	{
		printf("Error! Enter id incorrect!");
		return -1;
	}

	while(n > 0)
	{
		m = (n / 10) % 10;
		v = n % 10;
		n = n / 10;
		if (m < v)
			count++;
		if (m > v)
			count = -1;
	}
	printf("\nResult = %d", count);
	return 0;
}