#include "utils.h"
#include "errors.h"
#include "read.h"

int get_size_square_matrix(FILE *f, int *n, int *m)
{
    int rc = EXIT_SUCCESS, buff;
    char buff_sym;
    int size = 0;
    while ((rc = fscanf(f, "%d", &buff)) == 1)
    {
        size++;
        fscanf(f, "%c", &buff_sym);
        if (buff_sym == '\n')
            break;
    }
    if (rc == 0)
        rc = INCORRECT_FILE;
    else if (size == 0)
        rc = EMPTY_FILE;
    else
    {
        *n = size;
        *m = size;
        rc = EXIT_SUCCESS;
    }
    return rc;

}
int read_element_matrix(FILE *f, int **data, int n, int m)
{
    int rc = EXIT_SUCCESS;
    for (int i = 0; i < n && rc == 0; i++)
        for (int j = 0; j < m && rc == 0; j++)
            if (fscanf(f, "%d", *(data + i) + j) != 1)
                rc = INCORRECT_ELEMENT;

    return rc;
}