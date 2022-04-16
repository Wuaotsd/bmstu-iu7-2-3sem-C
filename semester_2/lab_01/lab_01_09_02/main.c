#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main(void)
{
    setbuf(stdout, NULL);
    double x, res = 0.0;
    int read, i = 1;
	
    printf("Введите значение аргумента: ");
    read = scanf("%lf", &x);

    if (!(read))
    {   
        printf("\nError! Аргумент некорректен!");
        return -1;
    }
	
    while (read && x >= 0)
    {   
        res += sqrt(i + x);
        i++;
	    
        printf("Введите значение аргумента: ");
        read = scanf("%lf", &x);
        if (!(read))
        {   
            printf("\nError! Аргумент некорректен!");
            return -1;
        }	
    }
	
    res = res / (i - 1);
    printf("\nResult = %lf", res);
    return 0;
}