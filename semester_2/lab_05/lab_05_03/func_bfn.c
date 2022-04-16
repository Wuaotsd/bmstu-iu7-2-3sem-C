#include <time.h>
#include "func_bfn.h"
#define N 50
#define N_M 1000

int create_bfn(FILE *f)
{
    if (f == NULL)
        return ERR_PARAM;
    
    srand(time(NULL));
    int n = rand() % N + 1;
    int r, i = 0;
    for (i = 0; i < n; i++)
    {
        r = rand() % N_M;
        fwrite(&r, 1, sizeof(int), f);
    }
    return EXIT_SUCCESS;
}

int sizef(FILE *f, size_t *n)
{
    if (f == NULL || n == NULL)
        return ERR_PARAM;
    
    long sz;
    if (fseek(f, 0L, SEEK_END))
        return FILE_IS_EMPTY;
    sz = ftell(f);
    if (sz <= 0)
        return FILE_IS_EMPTY;
    if (fseek(f, 0L, SEEK_SET))
        return ERROR_IO;
    if (sz % sizeof(int) != 0)
        return ERR_READ;
    *n = sz / sizeof(int);
    return EXIT_SUCCESS;
}

int printf_bfn(FILE *f)
{
    if (f == NULL)
        return ERR_PARAM;

    int num, rc = EXIT_SUCCESS, read;
    size_t k = 0;
    if (fseek(f, 0L, SEEK_SET) == 0)
    {
        rc = sizef(f, &k);
        if (rc == EXIT_SUCCESS)
            for (size_t i = 0; !rc && i < k; i++)
            {
                read = fread(&num, sizeof(num), 1, f);
                if (read == 1)
                    printf("%d ", num);
                else
                    rc = 1;
            }
    }
    return rc;
}

int get_number_by_pos(FILE *f, int pos, int *num)
{
    if (f == NULL)
        return ERR_PARAM;
    int rc = EXIT_SUCCESS;
    if (fseek(f, pos * sizeof(int), SEEK_SET) == 0)
    {
        if (fread(num, sizeof(int), 1, f) != 1)
            rc = ERROR_IO;
    }
    else
        rc = ERR_READ;
    return rc;
}

int put_number_by_pos(FILE *f, int pos, int num)
{
    if (f == NULL)
        return ERR_PARAM;
    int rc = EXIT_SUCCESS;
    if (fseek(f, pos * sizeof(int), SEEK_SET) == 0)
    {
        if (fwrite(&num, sizeof(int), 1, f) != 1)
            rc = ERROR_IO;
    }
    else
        rc = ERR_READ;
    return rc;
}

int sort_bfn(FILE *f)
{
    if (f == NULL)
        return ERR_PARAM;
    
    size_t k = 0;
    int num_1, num_2, rc = EXIT_SUCCESS;
    rc = sizef(f, &k);
    if (rc == EXIT_SUCCESS)
    {
        for (size_t i = 0; i < k - 1; i++)
            for (size_t j = i + 1; j < k; j++)
            {
                if (get_number_by_pos(f, i, &num_1) != EXIT_SUCCESS)
                    return ERR_READ;
                if (get_number_by_pos(f, j, &num_2) != EXIT_SUCCESS)
                    return ERR_READ;
                if (num_1 > num_2)
                {
                    if (put_number_by_pos(f, i, num_2) != EXIT_SUCCESS)
                        return ERR_READ;
                    if (put_number_by_pos(f, j, num_1) != EXIT_SUCCESS)
                        return ERR_READ;
                }
            }
    }
    return rc;
}
