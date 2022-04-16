#include "process.h"

int my_read_file(FILE *f, item *items, size_t *n)
{
    int i = 0, rc = EXIT_SUCCESS;
    char end[] = "STOP";
    _Bool flag = 0;
    while (!feof(f) && rc == EXIT_SUCCESS)
    {
        if (i > LENGHT_ARRAY)
        {
            rc = ARRAY_OVERFLOW;
            break;
        }
        if (!fscanf(f, "%s", items[i].name))
            rc = INCORRECT_FILE;
        if (strcmp(items[i].name, end) == 0)
        {
            flag = 1;
            break;
        }
        if (strlen(items[i].name) > LENGHT_STRING + 1)
            rc = STRING_OVERFLOW;
        if (!fscanf(f, "%d", &items[i].numbers))
            rc = INCORRECT_FILE;
        i++;
    }
    if (!flag && rc == EXIT_SUCCESS)
       rc = STOP_ERR;
    if (i == 0)
        rc = FILE_IS_EMPTY;
    *n = i;
    return rc;
}

void print_data(item *items, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (items[i].numbers > 0)
            printf("%s %d\n", items[i].name, items[i].numbers);
}

void buble_sort_string(item *items, size_t n)
{
    item buff;
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = i + 1; j < n; j++)
            if (strcmp(items[i].name, items[j].name) > 0)
            {
                buff = items[j];
                items[j] = items[i];
                items[i] = buff;
            }
}
