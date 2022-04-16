#include "process.h"

int my_fscanf(FILE *f, student *arr, size_t *n)
{
    size_t i = 0;
    int rc = EXIT_SUCCESS;
    char end[] = "STOP";
    while (!feof(f))
    {
        if (i > ARR_WORD)
        {
            rc = ARR_FULL_ERR;
            break;
        }
        if(!(fscanf(f, "%s", arr[i].name)))
        {
            rc = INCORRECT_ERR;
            break;
        }
        if (strcmp(arr[i].name, end) == 0)
            break;
        if (strlen(arr[i].name) > WORD_LEN)
        {
            rc = WORD_FULL_ERR;
            break;
        }
        if (!fscanf(f, "%zu", &arr[i].mark))
        {
            rc = INCORRECT_ERR;
            break;
        }
        i++;
    }
    *n = i;
    return rc;
}

void my_print_avg(student *arr, size_t n, int avg)
{
    for (size_t i = 0; i < n; i++)
        if (arr[i].mark == avg)
            printf("%s %zu\n", arr[i].name, arr[i].mark);
}

int  find_avta(student *arr, size_t n)
{
    int avg = 6;
    for (size_t i = 0; i < n; i++)
        if (arr[i].mark < avg && arr[i].mark > 2)
            avg = arr[i].mark;
    return avg;
}