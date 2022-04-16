#include "my_funcs.h"

int proccess(FILE *f, double *avg)
{
    if (f == NULL || avg == NULL)
        return PARAM_ERR;
    double num;
    int n = 0, rc = EXIT_SUCCESS;   
    while ((rc = fscanf(f, "%lf", &num)) == 1 && rc != EOF)
        n++;
    if (n < 2 || rc == 0)
        return INCORRECT_FILE;
    rewind(f);
    rc = fscanf(f, "%lf", &num);
    double max = num, min = num; 
    while (rc != EOF && rc)
    {
        rc = fscanf(f, "%lf", &num);
        if (max < num)
            max = num;
        if (min > num)
            min = num;
    }
    if (fabs(min - max) < EPS)
        return NOT_AVG_ERR;

    rewind(f);
    int flag = 0;
    int avg_n = 0;
    double sum_num = 0.0;
    while ((rc = fscanf(f, "%lf", &num)) && rc != EOF && !((fabs(num - max) < EPS || fabs(num - min) < EPS) && flag == 1))
    {
        if (flag)
        {
            sum_num += num;
            avg_n++;
        }
        if (flag == 0 && (fabs(num - max) < EPS || fabs(num - min) < EPS))
            flag = 1;  
    }
    flag = 0;
    if (avg_n == 0)
        return NOT_AVG_ERR; 
    *avg = sum_num / avg_n;
    return 0;
}