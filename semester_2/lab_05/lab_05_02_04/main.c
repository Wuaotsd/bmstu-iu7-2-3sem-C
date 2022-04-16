#include "my_funcs.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argv == NULL)
    {
        fprintf(stderr, "Warning! Please enter main.exe <fail_name>!");
        return PARAM_ERR;
    }
    FILE *f;
    int rc = EXIT_SUCCESS;
    double avg_num = 0.0;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Warning! File wasn't found!");
        return NOT_FOUND_FILE;
    }
    rc = proccess(f, &avg_num);
    if (rc != 0)
    {
        if (rc == PARAM_ERR)
            fprintf(stderr, "Warning! The params of function is wrong!");
        if (rc == INCORRECT_FILE)
            fprintf(stderr, "Warning! File is incorrect!");
        if (rc == NOT_AVG_ERR)
            fprintf(stderr, "Warning! The avg of numbers not found!");
    }
    else
        printf("Среднее значение между макс и мин значение в последовательности: %.6lf", avg_num);
    fclose(f);
    return rc;
}