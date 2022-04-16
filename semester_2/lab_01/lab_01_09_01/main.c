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
        res += sqrt(x / i);
        i++;
	    
        printf("Введите значение аргумента: ");
        read = scanf("%lf", &x);
        if (!(read))
        {   
            printf("\nError! Аргумент некорректен!");
            return -1;
        }	
    }
	
    res = sin(res);
    printf("\nResult = %lf", res);
    return 0;
}