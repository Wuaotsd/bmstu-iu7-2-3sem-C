#include "process.h"

int main(int argc, char **argv)
{
    if (argc != 2 || argv == NULL)
    {
        printf("1");
        return PARAM_ERR;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("2");
        return NOT_FOUND_FILE;
    }
    int rc = EXIT_SUCCESS, avg = 0;
    student students[ARR_WORD];
    size_t n;
    rc = my_fscanf(f, students, &n);
    if (rc == EXIT_SUCCESS)
    {
        avg = find_avta(students, n);
        my_print_avg(students, n, avg);
    }
    fclose(f);
    return rc;
}