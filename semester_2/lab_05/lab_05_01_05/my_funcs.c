#include "my_funcs.h"

int proccess(FILE *f, int *count)
{
    if (f == NULL || count == NULL)
        return PARAM_ERR;
    
    int num_1, num_2, number_snum_rc = 1, count_snum = 1, i = 0, rc;
    
    while ((rc = fscanf(f, "%d ", &num_2)) == 1)
    {
        if (i == 0)
        {
            num_1 = num_2;
            i++;
            continue;
        }
        if (num_1 == num_2)
            count_snum++; 
        else 
        {
            if (count_snum > number_snum_rc)
                number_snum_rc = count_snum;
            count_snum = 1;
        }
        num_1 = num_2;
        i++;
    }
    if (count_snum > number_snum_rc)
        number_snum_rc = count_snum;
    *count = number_snum_rc;
    if (i < 1)
       return INPUT_ERR;
    return 0;
}