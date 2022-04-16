#include "print_struct.h"

void print_struct_info(FILE *f, subject_t *nwv)
{
    fprintf(f, "%s\n", nwv->name_subject);
    fprintf(f, "%.6lf\n", nwv->weight);
    fprintf(f, "%.6lf\n", nwv->volume);
}

void printf_struct(FILE *f, subject_t *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        print_struct_info(f, &arr[i]);
}

int print_struct_begining_string(FILE *f, subject_t *arr, size_t n, char *str)
{
    int rc = EXIT_SUCCESS, flag = 0;
    for (size_t i = 0; i < n; i++)
        if (strspn(arr[i].name_subject, str) == strlen(str))
        {
            flag = 1;
            print_struct_info(f, &arr[i]);
        }
    if (flag == 0)
        rc = NOT_FOUND_STRUCT;
    return rc;
}
