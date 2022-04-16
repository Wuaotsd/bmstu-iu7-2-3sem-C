#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "struct_subject.h"
#include "memory.h"
#include "read_struct.h"
#include "read_check.h"
#include "sort_struct.h"
#include "print_struct.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    if (!(argc >= 2 && argc <= 3) || argv == NULL)
        return PARAMS_ERR;
    FILE *f_in;
    int rc = EXIT_SUCCESS;

    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
        rc = FILE_NOT_FOUND;
    else if (file_is_empty(f_in))
    {
        rc = FILE_IS_EMPTY;
        fclose(f_in);
    }
    else
    {
        subject_t *arr = NULL;
        size_t n = 0;
        rc = read_struct(f_in, &arr, &n);
        if (rc == EXIT_SUCCESS)
        {
            if (argc == 2)
            {
                sort_array_by_density(arr, n);
                printf_struct(stdout, arr, n);
            }
            else if (argc == 3)
            {
                if (check_prefix(argv[2], "ALL") == 1)
                    printf_struct(stdout, arr, n);
                else
                    rc = print_struct_begining_string(stdout, arr, n, argv[2]);
            }
        }
        free_structs(&arr, n);
        fclose(f_in);
    }
    return rc;
}
