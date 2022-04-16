#include "process.h"

int process(FILE *f, int *count)
{
    if (f == NULL || count == NULL || *count != 0)
        return ERR_PARAMS;
        
    int num_1, num_2, num_3;
    int count_n = 0, count_number = 0, error = EXIT_SUCCESS;
    
    int rc = fscanf(f, "%d %d %d", &num_1, &num_2, &num_3);
    count_number = rc;
    if (rc != 0)
    {
        if (rc == 3)
        {
            do
            {   
                count_number ++;
                if (num_1 < num_2 && num_2 > num_3)
                {
                    count_n += 1;
                }
                num_1 = num_2;
                num_2 = num_3;
            }
            while (fscanf(f, "%d", &num_3) == 1);
        }
        if (count_number < 3)
            error = NOT_FOUND_FIGURES;
            
        *count = count_n;
    }
    else
        error = SEQUENCE_EMPTY_END;
    return error;
}