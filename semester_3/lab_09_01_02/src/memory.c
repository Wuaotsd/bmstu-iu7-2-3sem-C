#include "memory.h"

subject_t  *allocate_malloc_structs(size_t n)
{
    subject_t * data = NULL;
    if (n != 0)
        data = malloc(n * sizeof(subject_t));
    return data;
}

void free_structs(subject_t **arr, size_t n)
{
    for (int i = 0; i < n; i++)
        free_string(&(*arr + i)->name_subject);
    free(*arr);
    *arr = NULL;
}

char *allocate_malloc_string(size_t len)
{
    char *str = NULL;
    if (len != 0)
        str = malloc(len * sizeof(char));
    return str;
}

void free_string(char **str)
{
    free(*str);
    *str = NULL;
}
