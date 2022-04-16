#include <stdio.h>
#include <math.h>

int main(void)
{
	int numberofflat;
	int numberofentrance, numberoffloor;
	printf("Input number of flat:");
	scanf("%d", &numberofflat);
	
	int n = 9, m = 36;
    if (numberofflat % 36 == 0)
	{
		numberofentrance = numberofflat / m;
		numberoffloor = n;
	}
	else
	{
		numberofentrance = numberofflat / m + 1;
		numberoffloor = ((numberofflat % m) / (m / n)) + 1;
	}
	printf("Number of entrance and floor = %d %d", numberofentrance, numberoffloor);
	return 0;
}
