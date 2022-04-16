#include "func_tfp.h"

#define ARG_ERROR  53

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 5 || argv == NULL)
        return ARG_ERROR;
        
    FILE *f_in;
    st arr[SIZE_ARR];
    int n = 0, rc = EXIT_SUCCESS;
    
    if (strcmp(argv[1], "st") == 0)
    {
        if (argc != 3)
            return ARG_ERROR;

        f_in = fopen(argv[2], "r");
        if (f_in == NULL)
        {
            fclose(f_in);
            return NOT_FOUND_FILE;
        }
        rc = read_students(f_in, arr, &n);
        if (rc == EXIT_SUCCESS)
        {
            sort_students(arr, n);
            printf_st(stdout, arr, n);
        }
        fclose(f_in);
    }
    else if (strcmp(argv[1], "ft") == 0)
    {
        if (argc != 5)
            return ARG_ERROR;

        f_in = fopen(argv[2], "r");
        if (f_in == NULL)
        {
            fclose(f_in);
            return NOT_FOUND_FILE;
        }
        rc = read_students(f_in, arr, &n);
        if (rc == EXIT_SUCCESS)
        {
            FILE *f_out;
            f_out = fopen(argv[3], "w");
            if (surname_fstr(f_out, arr, n, argv[4]) == 0)
                rc = NOT_FOUND_FILE;
            fclose(f_out);
        }
        fclose(f_in);
    }
    else if (strcmp(argv[1], "dt") == 0)
    {
        if (argc != 3)
            return ARG_ERROR;
        f_in = fopen(argv[2], "r");
        if (f_in == NULL)
        {
            fclose(f_in);
            return NOT_FOUND_FILE;
        }
        rc = read_students(f_in, arr, &n);
        fclose(f_in);
        if (rc == EXIT_SUCCESS)
        {
            float mas_avr[SIZE_ARR];
            float avr;
            avr = average_calc(arr, n, mas_avr);
            del_student(arr, mas_avr, &n, avr);
            if (n < 1)
                rc = NOT_FOUND_FILE;
            else
            {
                f_in = fopen(argv[2], "w");
                printf_st(f_in, arr, n);
                fclose(f_in);
            }
        }
    }
    else
        return ARG_ERROR;
        
    return rc;
}
