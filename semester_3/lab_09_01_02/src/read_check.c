#include "read_check.h"

#include "read_check.h"

int check_prefix(char *str, char *prefix)
{
    int rc = 1;
    if (strlen(str) != strlen(prefix))
        rc = 0;
    for (size_t i = 0; i < strlen(prefix) && rc; i++)
        if (toupper(prefix[i]) != toupper(str[i]))
            rc = 0;
    return rc;
}

int file_is_empty(FILE *f)
{
    int rc = EXIT_SUCCESS;
    long size;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    if (size == 0)
        rc = FILE_IS_EMPTY;
    fseek(f, 0, SEEK_SET);
    return rc;
}
