#include "process.h"

int main(void)
{
    int rc = EXIT_SUCCESS, count = 0;
    rc = process(stdin, &count);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == NOT_FOUND_FIGURES)
            fprintf(stderr, "Warning! Number of figures must be > 2!");
        if (rc == SEQUENCE_EMPTY_END)
            fprintf(stderr, "Warning! Numbers wasn't entered - only end!");
        if (rc == ERR_PARAMS)
            fprintf(stderr, "Warning! The params of function is wrong!");
        return rc;
    }
    fprintf(stdout, "Result: %d", count);
    return rc;
}