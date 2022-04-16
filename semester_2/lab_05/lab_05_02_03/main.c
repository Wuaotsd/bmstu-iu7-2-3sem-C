#include "process.h"

int main(int argc, char **argv)
{
    FILE *f;
    int rc = EXIT_SUCCESS, result = 0;
    if (argc < 2)
    {
        fprintf(stderr, "Warning! Please enter main.exe <fail_name>!");
        return NOT_ENTER_FILE;
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Warning! File wasn't found!");
        return NOT_FOUND_FILE;
    }
    result = process(f);
    if (result < 0)
    {
        rc = result;
        if (rc == ERR_PARAMS)
            fprintf(stderr, "Warning! The params of function is wrong!");
        if (rc == INCORRECT_FILE)
            fprintf(stderr, "Warning! File is incorrect!");
    }
    else
        printf("Result: %d", result);
    fclose(f);
    return rc;
}