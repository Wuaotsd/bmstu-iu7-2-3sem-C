#include <stdio.h>
#include <math.h>

int main(void)
{
	int number;
	int numberofbottles;
	printf("Input number of penny:");
	scanf("%d", &number);
	
	numberofbottles = (number - 20) / 25;
	
	printf("Number of bottles = %d", numberofbottles);
	return 0;
}
