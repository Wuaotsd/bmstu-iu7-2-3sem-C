#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main(void)
{
    setbuf(stdout, NULL);
    double x, res = 1.0;
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
        res = res * (x + i);
        i++;
	    
        printf("Введите значение аргумента: ");
        read = scanf("%lf", &x);
        if (!(read))
        {   
            printf("\nError! Аргумент некорректен!");
            return -1;
        }	
    }
	
    res = exp(1 / res);
    printf("\nResult = %lf", res);
    return 0;
}